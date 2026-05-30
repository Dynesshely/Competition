<script setup>
import { ref, computed, onMounted } from "vue";
import { useRoute } from "vue-router";
import { loadIndex } from "../lib/index.js";
import { difficultyClass } from "../lib/renderer.js";

const route = useRoute();
const idx = ref(null);
const filterDifficulty = ref("");
const filterTag = ref("");

onMounted(async () => {
  idx.value = await loadIndex();
});

const oj = computed(() => idx.value?.ojs.find((o) => o.key === route.params.key));
const ojName = computed(() => oj.value?.name || route.params.key);

const list = computed(() => {
  if (!idx.value) return [];
  const key = route.params.key;
  return idx.value.problems.filter((p) => {
    if (p.oj === key) return true;
    if (p.type === "competition" && `competitions/${p.competition}` === key) return true;
    if (p.type === "district" && key === "districts") return true;
    return false;
  });
});

const filtered = computed(() => {
  return list.value.filter((p) => {
    if (filterDifficulty.value && p.difficulty !== filterDifficulty.value) return false;
    if (filterTag.value && !p.tags.includes(filterTag.value)) return false;
    return true;
  });
});

const allTags = computed(() => [...new Set(list.value.flatMap((p) => p.tags))].sort());
const allDifficulties = computed(() => [...new Set(list.value.map((p) => p.difficulty || "暂无评定"))].sort());

function resetFilters() {
  filterDifficulty.value = "";
  filterTag.value = "";
}
</script>

<template>
  <div v-if="idx" class="space-y-4">
    <router-link to="/" class="inline-block text-sm text-[#6e7681] hover:text-[#00d4aa]">← 返回首页</router-link>
    <h1 class="text-xl font-bold">
      {{ ojName }}
      <span class="text-[#6e7681] text-base font-normal">({{ list.length }} 题)</span>
    </h1>

    <div class="flex gap-2 flex-wrap items-center">
      <select v-model="filterDifficulty" class="py-1.5 px-3 bg-[#161822] border border-[#2a2d3a] rounded-md text-sm text-[#c9d1d9] outline-none">
        <option value="">全部难度</option>
        <option v-for="d in allDifficulties" :key="d" :value="d">{{ d }}</option>
      </select>
      <select v-model="filterTag" class="py-1.5 px-3 bg-[#161822] border border-[#2a2d3a] rounded-md text-sm text-[#c9d1d9] outline-none">
        <option value="">全部标签</option>
        <option v-for="t in allTags" :key="t" :value="t">{{ t }}</option>
      </select>
      <button @click="resetFilters" class="py-1.5 px-3 bg-[#2a2d3a] border-none rounded-md text-sm text-[#c9d1d9] cursor-pointer hover:bg-[#3a3d4a]">重置</button>
    </div>

    <p v-if="filtered.length === 0" class="text-[#6e7681] text-center py-8">暂无题目</p>
    <table v-else class="w-full border-collapse">
      <thead>
        <tr class="text-left text-xs text-[#6e7681] uppercase border-b border-[#2a2d3a]">
          <th class="p-2">编号</th>
          <th class="p-2">标题</th>
          <th class="p-2">难度</th>
          <th class="p-2">标签</th>
        </tr>
      </thead>
      <tbody>
        <tr
          v-for="p in filtered"
          :key="p.id"
          class="cursor-pointer border-b border-[#2a2d3a] hover:bg-[#00d4aa11] transition-colors text-sm"
          @click="$router.push(`/problem/${route.params.key}/${p.id}`)"
        >
          <td class="p-2 font-bold text-[#00d4aa] font-mono">{{ p.id }}</td>
          <td class="p-2">{{ p.title }}</td>
          <td class="p-2">
            <span class="diff inline-block px-2 py-0.5 rounded text-xs font-semibold" :class="difficultyClass(p.difficulty)">
              {{ p.difficulty || "暂无评定" }}
            </span>
          </td>
          <td class="p-2 max-w-[260px]">
            <span
              v-for="t in p.tags"
              :key="t"
              class="inline-block px-1.5 py-0.5 m-0.5 rounded bg-[#2a2d3a] text-[#6e7681] text-xs whitespace-nowrap"
            >{{ t }}</span>
          </td>
        </tr>
      </tbody>
    </table>
  </div>
  <div v-else class="text-center text-[#6e7681] py-16">加载中...</div>
</template>
