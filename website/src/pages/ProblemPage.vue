<script setup>
import { ref, computed, onMounted, watch, nextTick } from "vue";
import { useRoute } from "vue-router";
import { loadIndex } from "../lib/index.js";
import { renderMarkdown, renderCode, difficultyClass } from "../lib/renderer.js";

const route = useRoute();
const idx = ref(null);
const problemMd = ref("");
const explainMd = ref("");
const codeRaw = ref("");
const copied = ref(false);

// Split bar
const rightPanelRef = ref(null);
const codeRatio = ref(0.6);
const dragging = ref(false);

onMounted(async () => {
  idx.value = await loadIndex();
  await loadContent();
});

watch(() => route.params.pid, async () => {
  if (idx.value) await loadContent();
});

const problem = computed(() => {
  if (!idx.value) return null;
  const key = route.params.oj;
  const pid = route.params.pid;
  return idx.value.problems.find((p) => {
    if (p.id === pid) {
      if (p.oj === key) return true;
      if (p.type === "competition" && `competitions/${p.competition}` === key) return true;
      if (p.type === "district" && key === "districts") return true;
    }
    return false;
  });
});

function getBasePath() {
  const p = problem.value;
  if (!p) return "";
  if (p.oj) return `/_gen/assets/website/${p.oj}`;
  if (p.type === "competition") {
    const parts = (p.files?.code || "").split("/");
    parts.pop();
    return `/_gen/assets/competitions/${p.competition}/${parts.join("/")}`.replace(/\/$/, "");
  }
  if (p.type === "district") {
    const parts = (p.files?.code || "").split("/");
    parts.pop();
    return `/_gen/assets/districts/${parts.join("/")}`.replace(/\/$/, "");
  }
  return "";
}

const problemUrl = computed(() => { const f = problem.value?.files?.problem; return f ? `${getBasePath()}/${f}` : null; });
const explainUrl = computed(() => { const f = problem.value?.files?.explain; return f ? `${getBasePath()}/${f}` : null; });
const codeUrl = computed(() => { const f = problem.value?.files?.code; return f ? `${getBasePath()}/${f}` : null; });
const codeLang = computed(() => (problem.value?.files?.code || "").split(".").pop() || "cpp");

async function loadContent() {
  problemMd.value = ""; explainMd.value = ""; codeRaw.value = "";
  const [pm, em, cr] = await Promise.all([
    problemUrl.value ? fetch(problemUrl.value).then(r => r.ok ? r.text() : null).catch(() => null) : null,
    explainUrl.value ? fetch(explainUrl.value).then(r => r.ok ? r.text() : null).catch(() => null) : null,
    codeUrl.value ? fetch(codeUrl.value).then(r => r.ok ? r.text() : null).catch(() => null) : null,
  ]);
  problemMd.value = pm || ""; explainMd.value = em || ""; codeRaw.value = cr || "";
}

async function copyCode() {
  await navigator.clipboard.writeText(codeRaw.value);
  copied.value = true;
  setTimeout(() => copied.value = false, 2000);
}

// Split bar drag
function onSplitDown(e) {
  dragging.value = true;
  document.addEventListener("mousemove", onSplitMove);
  document.addEventListener("mouseup", onSplitUp);
  e.preventDefault();
}
function onSplitMove(e) {
  if (!dragging.value || !rightPanelRef.value) return;
  const rect = rightPanelRef.value.getBoundingClientRect();
  const y = e.clientY - rect.top;
  const total = rect.height - 6;
  codeRatio.value = Math.max(0.2, Math.min(0.8, y / total));
}
function onSplitUp() {
  dragging.value = false;
  document.removeEventListener("mousemove", onSplitMove);
  document.removeEventListener("mouseup", onSplitUp);
}
</script>

<template>
  <div v-if="problem" class="flex flex-col h-[calc(100vh-52px-2rem)] sm:h-[calc(100vh-52px-3rem)] overflow-hidden">
    <!--  标题栏 -->
    <div class="flex-none">
      <div class="flex items-center gap-3">
        <router-link :to="`/oj/${route.params.oj}`" class="text-sm text-[#6e7681] hover:text-[#00d4aa] whitespace-nowrap">← 返回列表</router-link>
        <h1 class="text-lg font-bold flex-1 truncate">{{ problem.id }} {{ problem.title }}</h1>
        <a v-if="problem.sourceUrl" :href="problem.sourceUrl" target="_blank" class="text-xs text-[#6e7681] hover:text-[#00d4aa] whitespace-nowrap">原题链接 →</a>
      </div>
      <div class="flex gap-2 flex-wrap items-center mt-1">
        <span v-if="problem.difficulty" class="diff inline-block px-2 py-0.5 rounded text-xs font-semibold" :class="difficultyClass(problem.difficulty)">{{ problem.difficulty }}</span>
        <span v-for="t in problem.tags" :key="t" class="inline-block px-1.5 py-0.5 rounded bg-[#2a2d3a] text-[#6e7681] text-xs">{{ t }}</span>
      </div>
    </div>

    <!--  内容区 -->
    <div class="flex-1 grid grid-cols-1 md:grid-cols-2 gap-2 min-h-0 mt-4">
      <!-- 左: 题目描述 -->
      <div class="bg-[#1a1d2e] border border-[#2a2d3a] rounded-lg overflow-hidden flex flex-col">
        <div class="flex-none px-3 py-2 bg-[#161822] border-b border-[#2a2d3a] font-semibold text-sm">📋 题目描述</div>
        <div class="flex-1 overflow-y-auto px-4 py-3 pane-body" v-html="problemMd ? renderMarkdown(problemMd) : '<p class=\'text-[#6e7681]\'>暂无题目描述</p>'"></div>
      </div>

      <!-- 右侧: 代码 + 分割条 + 题解 -->
      <div ref="rightPanelRef" class="flex flex-col gap-0 min-h-0">
        <!-- 代码 -->
        <div class="bg-[#1a1d2e] border border-[#2a2d3a] rounded-t-lg overflow-hidden flex flex-col min-h-0" :style="{ flex: codeRatio }">
          <div class="flex-none px-3 py-2 bg-[#161822] border-b border-[#2a2d3a] font-semibold text-sm flex items-center justify-between">
            <span>💻 代码</span>
            <button
              @click="copyCode"
              class="text-xs px-2 py-0.5 rounded border border-[#2a2d3a] bg-transparent text-[#6e7681] hover:text-[#c9d1d9] hover:border-[#00d4aa] cursor-pointer transition-colors"
            >{{ copied ? '✓ 已复制' : '📋 复制' }}</button>
          </div>
          <div class="flex-1 overflow-y-auto pane-code h-full" v-html="codeRaw ? renderCode(codeRaw, codeLang) : '<p class=\'text-[#6e7681] px-4 py-3\'>暂无代码</p>'"></div>
        </div>

        <!-- Split bar -->
        <div
          class="flex-none h-[6px] bg-[#2a2d3a] cursor-ns-resize hover:bg-[#00d4aa] transition-colors rounded-full mx-1 my-1.5"
          :class="{ '!bg-[#00d4aa]': dragging }"
          @mousedown="onSplitDown"
        ></div>

        <!-- 题解 -->
        <div class="bg-[#1a1d2e] border border-[#2a2d3a] rounded-b-lg overflow-hidden flex flex-col min-h-0" :style="{ flex: 1 - codeRatio }">
          <div class="flex-none px-3 py-2 bg-[#161822] border-b border-[#2a2d3a] font-semibold text-sm">📝 题解</div>
          <div class="flex-1 overflow-y-auto px-4 py-3 pane-body" v-html="explainMd ? renderMarkdown(explainMd) : '<p class=\'text-[#6e7681]\'>暂无题解</p>'"></div>
        </div>
      </div>
    </div>
  </div>

  <div v-else class="text-center py-16">
    <h2 class="text-3xl text-[#00d4aa] mb-2">题目未找到</h2>
    <p class="text-[#6e7681] mb-4">{{ route.params.pid }} @ {{ route.params.oj }}</p>
    <router-link to="/" class="text-[#00d4aa]">返回首页</router-link>
  </div>
</template>
