<script setup>
import { ref, computed, onMounted, watch } from "vue";
import { useRoute } from "vue-router";
import { loadIndex } from "../lib/index.js";
import { difficultyClass } from "../lib/renderer.js";
import { ArrowLeft, ChevronLeft, ChevronRight, ChevronsLeft, ChevronsRight } from "lucide-vue-next";

const PAGE_SIZE_OPTIONS = [10, 20, 50, 100, 200];

const route = useRoute();
const idx = ref(null);
const filterDifficulty = ref("");
const filterTag = ref("");
const bankFilter = ref("P");
const pageSize = ref(20);
const currentPage = ref(1);

onMounted(async () => { idx.value = await loadIndex(); });

const oj = computed(() => idx.value?.ojs.find(o => o.key === route.params.key));
const ojName = computed(() => oj.value?.name || route.params.key);

const isLuogu = computed(() => route.params.key === "www.luogu.com.cn");

const list = computed(() => {
  if (!idx.value) return [];
  const key = route.params.key;
  let problems = idx.value.problems.filter(p => {
    if (p.oj === key) return true;
    if (p.type === "competition" && `competitions/${p.competition}` === key) return true;
    if (p.type === "district" && key === "districts") return true;
    return false;
  });
  if (isLuogu.value) {
    problems = problems.filter(p => p.id.startsWith(bankFilter.value));
  }
  return problems;
});

const filtered = computed(() => list.value.filter(p =>
  (!filterDifficulty.value || p.difficulty === filterDifficulty.value) &&
  (!filterTag.value || p.tags.includes(filterTag.value))
));

const totalPages = computed(() => Math.max(1, Math.ceil(filtered.value.length / pageSize.value)));

const paginated = computed(() => {
  const start = (currentPage.value - 1) * pageSize.value;
  return filtered.value.slice(start, start + pageSize.value);
});

const allTags = computed(() => [...new Set(list.value.flatMap(p => p.tags))].sort());
const allDifficulties = computed(() => [...new Set(list.value.map(p => p.difficulty || "暂无评定"))].sort());

function resetFilters() {
  filterDifficulty.value = "";
  filterTag.value = "";
}

// 筛选/分页变化时回到第一页
watch([filterDifficulty, filterTag, pageSize, bankFilter], () => { currentPage.value = 1; });
// 切换 OJ 时回到第一页并重置题库筛选
watch(() => route.params.key, () => { currentPage.value = 1; bankFilter.value = "P"; });

function goPage(n) {
  currentPage.value = Math.max(1, Math.min(totalPages.value, n));
}
</script>

<template>
  <div v-if="idx" class="flex flex-col h-[calc(100vh-52px-2rem)] sm:h-[calc(100vh-52px-3rem)] overflow-hidden">
    <div class="flex-none space-y-3">
      <router-link to="/" class="inline-block text-sm hover:underline" style="color: var(--color-muted-fg)"><ArrowLeft :size="14" class="inline-block -mt-0.5 mr-0.5" /> 返回首页</router-link>
      <h1 class="text-2xl font-medium" style="font-family: var(--font-heading); color: var(--color-fg)">
        {{ ojName }} <span class="text-base font-normal" style="color: var(--color-muted-fg)">({{ list.length }} 题)</span>
      </h1>

      <div class="flex gap-2 flex-wrap items-center pt-1">
        <select v-model="filterDifficulty" class="academia-select">
          <option value="">全部难度</option>
          <option v-for="d in allDifficulties" :key="d" :value="d">{{ d }}</option>
        </select>
        <select v-model="filterTag" class="academia-select">
          <option value="">全部标签</option>
          <option v-for="t in allTags" :key="t" :value="t">{{ t }}</option>
        </select>
        <button @click="resetFilters" class="py-1.5 px-3 rounded-md text-sm cursor-pointer transition-colors border-none"
          style="background: var(--color-muted); color: var(--color-fg); font-family: var(--font-body)">重置</button>

        <div v-if="isLuogu" class="flex rounded-md overflow-hidden border" style="border-color: var(--color-border)">
          <button @click="bankFilter = 'P'"
            class="px-3 py-1.5 text-sm cursor-pointer transition-all duration-300 border-none"
            style="font-family: var(--font-body)"
            :style="bankFilter === 'P' ? { background: 'var(--color-accent)', color: 'var(--color-accent-fg)' } : { background: 'var(--color-muted)', color: 'var(--color-muted-fg)' }">主题库</button>
          <button @click="bankFilter = 'B'"
            class="px-3 py-1.5 text-sm cursor-pointer transition-all duration-300 border-none border-l"
            style="font-family: var(--font-body); border-color: var(--color-border)"
            :style="bankFilter === 'B' ? { background: 'var(--color-accent)', color: 'var(--color-accent-fg)' } : { background: 'var(--color-muted)', color: 'var(--color-muted-fg)' }">入门与面试</button>
        </div>

        <select v-model="pageSize" class="academia-select ml-auto">
          <option v-for="n in PAGE_SIZE_OPTIONS" :key="n" :value="n">{{ n }} 条/页</option>
        </select>
      </div>
    </div>

    <div class="flex-1 overflow-y-auto min-h-0 mt-3">
      <p v-if="filtered.length === 0" class="text-center py-8" style="color: var(--color-muted-fg)">暂无题目</p>
      <template v-else>
        <table class="w-full border-collapse">
          <thead>
            <tr class="text-left text-xs uppercase tracking-[0.1em] border-b sticky top-0" style="font-family: var(--font-display); color: var(--color-muted-fg); border-color: var(--color-border); background: var(--color-bg)">
              <th class="p-2 font-medium">编号</th><th class="p-2 font-medium">标题</th><th class="p-2 font-medium">难度</th><th class="p-2 font-medium">标签</th>
            </tr>
          </thead>
          <tbody>
            <tr v-for="p in paginated" :key="p.id" @click="$router.push(`/problem/${route.params.key}/${p.id}`)"
              class="cursor-pointer border-b text-sm transition-colors duration-150"
              style="border-color: var(--color-border); font-family: var(--font-body); color: var(--color-fg)">
              <td class="p-2 font-bold font-mono" style="color: var(--color-accent)">{{ p.id }}</td>
              <td class="p-2">{{ p.title }}</td>
              <td class="p-2"><span class="diff inline-block px-2 py-0.5 rounded text-xs font-semibold" :class="difficultyClass(p.difficulty)">{{ p.difficulty || "暂无评定" }}</span></td>
              <td class="p-2 max-w-[260px]">
                <span v-for="t in p.tags" :key="t" class="inline-block px-1.5 py-0.5 m-0.5 rounded text-xs whitespace-nowrap"
                  style="background: var(--color-muted); color: var(--color-muted-fg)">{{ t }}</span>
              </td>
            </tr>
          </tbody>
        </table>
      </template>
    </div>

    <div v-if="filtered.length > 0" class="flex-none flex items-center justify-center gap-2 py-3 border-t" style="font-family: var(--font-body); border-color: var(--color-border)">
      <button @click="goPage(1)" :disabled="currentPage === 1"
        class="px-3 py-1.5 rounded text-sm cursor-pointer transition-colors border-none disabled:opacity-40 disabled:cursor-default"
        style="background: var(--color-muted); color: var(--color-fg)"><ChevronsLeft :size="14" class="inline-block -mt-0.5" /> 首页</button>
      <button @click="goPage(currentPage - 1)" :disabled="currentPage === 1"
        class="px-3 py-1.5 rounded text-sm cursor-pointer transition-colors border-none disabled:opacity-40 disabled:cursor-default"
        style="background: var(--color-muted); color: var(--color-fg)"><ChevronLeft :size="14" class="inline-block -mt-0.5" /> 上一页</button>
      <span class="text-sm px-3" style="color: var(--color-muted-fg)">
        第 {{ currentPage }} / {{ totalPages }} 页
      </span>
      <button @click="goPage(currentPage + 1)" :disabled="currentPage === totalPages"
        class="px-3 py-1.5 rounded text-sm cursor-pointer transition-colors border-none disabled:opacity-40 disabled:cursor-default"
        style="background: var(--color-muted); color: var(--color-fg)">下一页 <ChevronRight :size="14" class="inline-block -mt-0.5" /></button>
      <button @click="goPage(totalPages)" :disabled="currentPage === totalPages"
        class="px-3 py-1.5 rounded text-sm cursor-pointer transition-colors border-none disabled:opacity-40 disabled:cursor-default"
        style="background: var(--color-muted); color: var(--color-fg)">末页 <ChevronsRight :size="14" class="inline-block -mt-0.5" /></button>
    </div>
  </div>
  <div v-else class="text-center py-16" style="color: var(--color-muted-fg)">加载中...</div>
</template>
