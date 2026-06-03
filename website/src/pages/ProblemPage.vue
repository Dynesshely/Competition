<script setup>
import { ref, computed, onMounted, watch } from "vue";
import { useRoute } from "vue-router";
import { loadIndex } from "../lib/index.js";
import {
  renderMarkdown,
  renderCode,
  difficultyClass,
} from "../lib/renderer.js";
import { ArrowLeft, ExternalLink, ClipboardList, Code2, FileText, Copy, Check } from "lucide-vue-next";

const route = useRoute();
const idx = ref(null);
const problemMd = ref("");
const explainMd = ref("");
const codeRaw = ref("");
const copied = ref(false);
const rightPanelRef = ref(null);
const codeRatio = ref(0.6);
const dragging = ref(false);
const selectedCodeIdx = ref(0);

onMounted(async () => {
  idx.value = await loadIndex();
  await loadContent();
});
watch(
  () => route.params.pid,
  async () => {
    if (idx.value) { selectedCodeIdx.value = 0; await loadContent(); }
  },
);
watch(selectedCodeIdx, async () => {
  if (idx.value && problem.value) await loadContent();
});

const problem = computed(() => {
  if (!idx.value) return null;
  const key = route.params.oj;
  const pid = route.params.pid;
  return idx.value.problems.find((p) => {
    if (p.id === pid) {
      if (p.oj === key) return true;
      if (p.type === "competition" && `competitions/${p.competition}` === key)
        return true;
      if (p.type === "district" && key === "districts") return true;
    }
    return false;
  });
});

function getBasePath() {
  const p = problem.value;
  if (!p) return "";
  const base = import.meta.env.BASE_URL;
  if (p.oj) return `${base}_gen/assets/website/${p.oj}`;
  if (p.type === "competition") {
    const parts = (p.files?.code || "").split("/");
    parts.pop();
    return `${base}_gen/assets/competitions/${p.competition}/${parts.join("/")}`.replace(/\/$/, "");
  }
  if (p.type === "district") {
    const parts = (p.files?.code || "").split("/");
    parts.pop();
    return `${base}_gen/assets/districts/${parts.join("/")}`.replace(/\/$/, "");
  }
  return "";
}

const codeOptions = computed(() => problem.value?.codes || []);
const selectedCode = computed(() => codeOptions.value[selectedCodeIdx.value]);

const problemUrl = computed(() => {
  const f = problem.value?.files?.problem;
  return f ? `${getBasePath()}/${f}` : null;
});
const explainUrl = computed(() => {
  const f = problem.value?.files?.explain;
  return f ? `${getBasePath()}/${f}` : null;
});
const codeUrl = computed(() => {
  const f = selectedCode.value?.file || problem.value?.files?.code;
  return f ? `${getBasePath()}/${f}` : null;
});
const codeLang = computed(() => {
  const f = selectedCode.value?.file || problem.value?.files?.code || "";
  return f.split(".").pop() || "cpp";
});

async function loadContent() {
  problemMd.value = "";
  explainMd.value = "";
  codeRaw.value = "";
  const [pm, em, cr] = await Promise.all([
    problemUrl.value
      ? fetch(problemUrl.value)
          .then((r) => (r.ok ? r.text() : null))
          .catch(() => null)
      : null,
    explainUrl.value
      ? fetch(explainUrl.value)
          .then((r) => (r.ok ? r.text() : null))
          .catch(() => null)
      : null,
    codeUrl.value
      ? fetch(codeUrl.value)
          .then((r) => (r.ok ? r.text() : null))
          .catch(() => null)
      : null,
  ]);
  problemMd.value = pm || "";
  explainMd.value = em || "";
  codeRaw.value = cr || "";
}

async function copyCode() {
  await navigator.clipboard.writeText(codeRaw.value);
  copied.value = true;
  setTimeout(() => (copied.value = false), 2000);
}

function onSplitDown(e) {
  dragging.value = true;
  document.addEventListener("mousemove", onSplitMove);
  document.addEventListener("mouseup", onSplitUp);
  e.preventDefault();
}
function onSplitMove(e) {
  if (!dragging.value || !rightPanelRef.value) return;
  const rect = rightPanelRef.value.getBoundingClientRect();
  codeRatio.value = Math.max(
    0.2,
    Math.min(0.8, (e.clientY - rect.top) / (rect.height - 8)),
  );
}
function onSplitUp() {
  dragging.value = false;
  document.removeEventListener("mousemove", onSplitMove);
  document.removeEventListener("mouseup", onSplitUp);
}
</script>

<template>
  <div
    v-if="problem"
    class="flex flex-col h-[calc(100vh-52px-2rem)] sm:h-[calc(100vh-52px-3rem)] overflow-hidden"
  >
    <!-- 标题栏 -->
    <div class="flex-none">
      <div class="flex items-center gap-3">
        <router-link
          :to="`/oj/${route.params.oj}`"
          class="text-sm whitespace-nowrap hover:underline"
          style="color: var(--color-muted-fg)"
          ><ArrowLeft :size="14" class="inline-block -mt-0.5 mr-0.5" /> 返回列表</router-link
        >
        <h1
          class="text-xl font-medium flex-1 truncate"
          style="font-family: var(--font-heading); color: var(--color-fg)"
        >
          {{ problem.id }} {{ problem.title }}
        </h1>
        <a
          v-if="problem.sourceUrl"
          :href="problem.sourceUrl"
          target="_blank"
          class="text-xs whitespace-nowrap hover:underline"
          style="font-family: var(--font-display); color: var(--color-muted-fg)"
          >原题链接 <ExternalLink :size="12" class="inline-block -mt-0.5" /></a
        >
      </div>
      <div class="flex gap-2 flex-wrap items-center mt-1">
        <span
          v-if="problem.difficulty"
          class="diff inline-block px-2 py-0.5 rounded text-xs font-semibold"
          :class="difficultyClass(problem.difficulty)"
          >{{ problem.difficulty }}</span
        >
        <span
          v-for="t in problem.tags"
          :key="t"
          class="inline-block px-1.5 py-0.5 rounded text-xs"
          style="background: var(--color-muted); color: var(--color-muted-fg)"
          >{{ t }}</span
        >
      </div>
    </div>

    <!-- 内容区 -->
    <div
      class="flex-1 grid grid-cols-1 md:grid-cols-2 gap-2 min-h-0 mt-3"
      style="--sm-h: calc(100vh - 52px - 2rem)"
    >
      <!-- 左: 题目 -->
      <div
        class="rounded-lg overflow-hidden flex flex-col border"
        style="
          background: var(--color-bg-alt);
          border-color: var(--color-border);
        "
      >
        <div
          class="flex-none px-3 py-2 border-b text-sm font-semibold"
          style="
            background: var(--color-bg);
            border-color: var(--color-border);
            font-family: var(--font-display);
            color: var(--color-accent);
          "
        >
          <ClipboardList :size="14" class="inline-block -mt-0.5 mr-1" /> 题目描述
        </div>
        <div
          class="flex-1 overflow-y-auto px-4 py-3 pane-body"
          v-html="
            problemMd
              ? renderMarkdown(problemMd)
              : '<p style=\'color:var(--color-muted-fg)\'>暂无题目描述</p>'
          "
        ></div>
      </div>

      <!-- 右侧 -->
      <div ref="rightPanelRef" class="flex flex-col gap-0 min-h-0">
        <!-- 代码 -->
        <div
          class="rounded-t-lg overflow-hidden flex flex-col min-h-0 border mb-1"
          :style="{
            flex: codeRatio,
            background: 'var(--color-bg-alt)',
            borderColor: 'var(--color-border)',
          }"
        >
          <div
            class="flex-none px-3 py-2 border-b text-sm font-semibold flex items-center justify-between"
            style="
              background: var(--color-bg);
              border-color: var(--color-border);
              font-family: var(--font-display);
              color: var(--color-accent);
            "
          >
            <span><Code2 :size="14" class="inline-block -mt-0.5 mr-1" /> 代码</span>
            <div class="flex items-center gap-2">
              <select
                v-if="codeOptions.length > 1"
                v-model="selectedCodeIdx"
                class="academia-select text-xs! py-1! px-1.5!"
              >
                <option v-for="(opt, i) in codeOptions" :key="i" :value="i">{{ opt.label }}</option>
              </select>
              <button @click="copyCode" class="btn-brass px-3 py-1 text-[10px]">
                <Check v-if="copied" :size="12" class="inline-block -mt-0.5 mr-0.5" /><span v-if="copied">已复制</span>
                <Copy v-if="!copied" :size="12" class="inline-block -mt-0.5 mr-0.5" /><span v-if="!copied">复制</span>
              </button>
            </div>
          </div>
          <div
            class="flex-1 overflow-y-auto pane-code h-full"
            v-html="
              codeRaw
                ? renderCode(codeRaw, codeLang)
                : '<p style=\'color:var(--color-muted-fg)\' class=\'px-4 py-3\'>暂无代码</p>'
            "
          ></div>
        </div>

        <!-- Split -->
        <div
          class="flex-none h-1.5 cursor-ns-resize transition-colors rounded-full mx-1 my-2"
          :class="{ 'bg-(--color-accent)!': dragging }"
          style="background: var(--color-border)"
          :style="{ '&:hover': { background: 'var(--color-accent)' } }"
          @mousedown="onSplitDown"
        ></div>

        <!-- 题解 -->
        <div
          class="rounded-b-lg overflow-hidden flex flex-col min-h-0 border mt-1"
          :style="{
            flex: 1 - codeRatio,
            background: 'var(--color-bg-alt)',
            borderColor: 'var(--color-border)',
          }"
        >
          <div
            class="flex-none px-3 py-2 border-b text-sm font-semibold"
            style="
              background: var(--color-bg);
              border-color: var(--color-border);
              font-family: var(--font-display);
              color: var(--color-accent);
            "
          >
            <FileText :size="14" class="inline-block -mt-0.5 mr-1" /> 题解
          </div>
          <div
            class="flex-1 overflow-y-auto px-4 py-3 pane-body"
            v-html="
              explainMd
                ? renderMarkdown(explainMd)
                : '<p style=\'color:var(--color-muted-fg)\'>暂无题解</p>'
            "
          ></div>
        </div>
      </div>
    </div>
  </div>

  <div v-else class="text-center py-16">
    <h2
      class="text-3xl mb-2"
      style="color: var(--color-accent); font-family: var(--font-heading)"
    >
      题目未找到
    </h2>
    <p class="mb-4" style="color: var(--color-muted-fg)">
      {{ route.params.pid }} @ {{ route.params.oj }}
    </p>
    <router-link to="/" style="color: var(--color-accent)"
      >返回首页</router-link
    >
  </div>
</template>
