<script setup>
import { ref, onMounted } from "vue";
import { loadIndex } from "../lib/index.js";
import WordCloud from "../components/WordCloud.vue";

const idx = ref(null);

onMounted(async () => {
  idx.value = await loadIndex();
});
</script>

<template>
  <div v-if="idx" class="space-y-8">
    <!-- Hero -->
    <section class="text-center py-8 px-4">
      <h1 class="text-3xl font-bold mb-2">OI 竞赛题解库</h1>
      <p class="flex justify-center gap-6 flex-wrap text-[#6e7681] text-sm">
        <span
          >📝
          <strong class="text-[#c9d1d9]">{{
            idx.summary.totalProblems
          }}</strong>
          道题目</span
        >
        <span
          >✅
          <strong class="text-[#c9d1d9]">{{ idx.summary.withMetadata }}</strong>
          篇题解</span
        >
        <span
          >🏷️
          <strong class="text-[#c9d1d9]">{{ idx.tags.length }}</strong>
          个标签</span
        >
      </p>
    </section>

    <!-- OJ 平台 -->
    <section>
      <h2 class="text-lg font-semibold mb-4">📋 OJ 平台</h2>
      <div
        class="grid grid-cols-2 sm:grid-cols-3 lg:grid-cols-4 xl:grid-cols-6 gap-3"
      >
        <router-link
          v-for="o in idx.ojs.filter((o) => !o.type)"
          :key="o.key"
          :to="`/oj/${o.key}`"
          class="flex justify-between items-center px-4 py-3 bg-[#161822] border border-[#2a2d3a] rounded-lg hover:border-[#00d4aa] transition-colors no-underline group"
        >
          <span class="font-semibold text-[#c9d1d9] text-sm">{{ o.name }}</span>
          <span class="text-[#6e7681] text-xs whitespace-nowrap ml-2"
            >{{ o.count }} 题</span
          >
        </router-link>
      </div>
    </section>

    <!-- 竞赛 -->
    <section v-if="idx.ojs.filter((o) => o.type === 'competition').length">
      <h2 class="text-lg font-semibold mb-4">🏆 竞赛</h2>
      <div
        class="grid grid-cols-2 sm:grid-cols-3 lg:grid-cols-4 xl:grid-cols-6 gap-3"
      >
        <router-link
          v-for="o in idx.ojs.filter((o) => o.type === 'competition')"
          :key="o.key"
          :to="`/oj/${o.key}`"
          class="flex justify-between items-center px-4 py-3 bg-[#161822] border border-[#2a2d3a] border-l-[3px] border-l-[#f0c000] rounded-lg hover:border-[#00d4aa] no-underline"
        >
          <span class="font-semibold text-[#c9d1d9] text-sm">{{ o.name }}</span>
          <span class="text-[#6e7681] text-xs whitespace-nowrap ml-2"
            >{{ o.count }} 题</span
          >
        </router-link>
      </div>
    </section>

    <!-- 地区训练 -->
    <section v-if="idx.ojs.filter((o) => o.type === 'district').length">
      <h2 class="text-lg font-semibold mb-4">📍 地区训练</h2>
      <div
        class="grid grid-cols-2 sm:grid-cols-3 lg:grid-cols-4 xl:grid-cols-6 gap-3"
      >
        <router-link
          v-for="o in idx.ojs.filter((o) => o.type === 'district')"
          :key="o.key"
          :to="`/oj/${o.key}`"
          class="flex justify-between items-center px-4 py-3 bg-[#161822] border border-[#2a2d3a] border-l-[3px] border-l-[#58a6ff] rounded-lg hover:border-[#00d4aa] no-underline"
        >
          <span class="font-semibold text-[#c9d1d9] text-sm">{{ o.name }}</span>
          <span class="text-[#6e7681] text-xs whitespace-nowrap ml-2"
            >{{ o.count }} 题</span
          >
        </router-link>
      </div>
    </section>

    <!-- 标签词云 -->
    <section>
      <h2 class="text-lg font-semibold mb-4">🏷️ 标签</h2>
      <WordCloud
        :words="idx.tags.map((t) => ({ text: t.name, weight: t.count }))"
        :height="260"
        :min-font-size="12"
        :max-font-size="42"
      />
    </section>
  </div>
  <div v-else class="text-center text-[#6e7681] py-16">加载中...</div>
</template>
