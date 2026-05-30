<script setup>
import { ref, onMounted } from "vue";
import { loadIndex } from "../lib/index.js";
import WordCloud from "../components/WordCloud.vue";

const BASE = import.meta.env.BASE_URL;
const FALLBACK_ICON = `${BASE}icons/fallback.svg`;

const idx = ref(null);

const ojIconMap = {
  "www.luogu.com.cn": "luogu.ico", "ybt.ssoier.cn": "ybt.ico",
  "cjsoj.cn": "cjsoj.ico", "oj.crequency.cn": "crequency.ico",
  "www.51nod.com": "51nod.png",
};
function ojIcon(key) {
  return `${BASE}icons/${ojIconMap[key] || "fallback.svg"}`;
}

onMounted(async () => { idx.value = await loadIndex(); });
</script>

<template>
  <div v-if="idx" class="space-y-12">
    <!-- Hero -->
    <section class="text-center py-12 px-4">
      <h1 class="text-5xl font-medium mb-3 tracking-tight" style="font-family: var(--font-heading); color: var(--color-fg)">OI 竞赛题解库</h1>
      <p class="flex justify-center gap-6 flex-wrap text-sm" style="color: var(--color-muted-fg)">
        <span>📝 <strong style="color: var(--color-fg)">{{ idx.summary.totalProblems }}</strong> 道题目</span>
        <span>✅ <strong style="color: var(--color-fg)">{{ idx.summary.withMetadata }}</strong> 篇题解</span>
        <span>🏷️ <strong style="color: var(--color-fg)">{{ idx.tags.length }}</strong> 个标签</span>
      </p>
    </section>

    <!-- OJ 平台 -->
    <section>
      <div class="flex items-center gap-3 mb-5">
        <span class="text-xs uppercase tracking-[0.25em]" style="font-family: var(--font-display); color: var(--color-accent)">Volume I</span>
        <div class="flex-1 h-px" style="background: linear-gradient(90deg, var(--color-border), transparent)"></div>
      </div>
      <h2 class="text-2xl font-medium mb-4" style="font-family: var(--font-heading); color: var(--color-fg)">📋 OJ 平台</h2>
      <div class="grid grid-cols-2 sm:grid-cols-3 lg:grid-cols-4 xl:grid-cols-6 gap-3">
        <router-link v-for="o in idx.ojs.filter(o => !o.type)" :key="o.key" :to="`/oj/${o.key}`"
          class="flex justify-between items-center px-4 py-3 rounded border transition-all duration-300 no-underline hover:-translate-y-0.5"
          style="background: var(--color-bg-alt); border-color: var(--color-border)"
          onmouseenter="this.style.borderColor='var(--color-accent)';this.style.boxShadow='0 4px 16px rgba(0,0,0,calc(var(--shadow-strength)*0.2))'"
          onmouseleave="this.style.borderColor='var(--color-border)';this.style.boxShadow='none'">
          <span class="flex items-center gap-2 min-w-0">
            <img :src="ojIcon(o.key)" class="w-5 h-5 rounded flex-shrink-0" @error="e => e.target.src = FALLBACK_ICON" />
            <span class="font-semibold text-sm truncate" style="font-family: var(--font-body); color: var(--color-fg)">{{ o.name }}</span>
          </span>
          <span class="text-xs whitespace-nowrap ml-2" style="font-family: var(--font-display); color: var(--color-muted-fg)">{{ o.count }} 题</span>
        </router-link>
      </div>
    </section>

    <!-- 竞赛 -->
    <section v-if="idx.ojs.filter(o => o.type === 'competition').length">
      <div class="flex items-center gap-3 mb-5">
        <span class="text-xs uppercase tracking-[0.25em]" style="font-family: var(--font-display); color: var(--color-accent)">Volume II</span>
        <div class="flex-1 h-px" style="background: linear-gradient(90deg, var(--color-border), transparent)"></div>
      </div>
      <h2 class="text-2xl font-medium mb-4" style="font-family: var(--font-heading); color: var(--color-fg)">🏆 竞赛</h2>
      <div class="grid grid-cols-2 sm:grid-cols-3 lg:grid-cols-4 xl:grid-cols-6 gap-3">
        <router-link v-for="o in idx.ojs.filter(o => o.type === 'competition')" :key="o.key" :to="`/oj/${o.key}`"
          class="flex justify-between items-center px-4 py-3 rounded border border-l-[3px] transition-all duration-300 no-underline"
          style="background: var(--color-bg-alt); border-color: var(--color-border); border-left-color: #f0c000"
          onmouseenter="this.style.borderColor='var(--color-accent)'"
          onmouseleave="this.style.borderColor='var(--color-border)';this.style.borderLeftColor='#f0c000'">
          <span class="flex items-center gap-2 min-w-0">
            <span class="w-5 h-5 rounded flex-shrink-0 flex items-center justify-center text-xs font-bold" style="background: #f0c00022; color: #f0c000">🏆</span>
            <span class="font-semibold text-sm truncate" style="font-family: var(--font-body); color: var(--color-fg)">{{ o.name }}</span>
          </span>
          <span class="text-xs whitespace-nowrap ml-2" style="font-family: var(--font-display); color: var(--color-muted-fg)">{{ o.count }} 题</span>
        </router-link>
      </div>
    </section>

    <!-- 地区训练 -->
    <section v-if="idx.ojs.filter(o => o.type === 'district').length">
      <div class="flex items-center gap-3 mb-5">
        <span class="text-xs uppercase tracking-[0.25em]" style="font-family: var(--font-display); color: var(--color-accent)">Volume III</span>
        <div class="flex-1 h-px" style="background: linear-gradient(90deg, var(--color-border), transparent)"></div>
      </div>
      <h2 class="text-2xl font-medium mb-4" style="font-family: var(--font-heading); color: var(--color-fg)">📍 地区训练</h2>
      <div class="grid grid-cols-2 sm:grid-cols-3 lg:grid-cols-4 xl:grid-cols-6 gap-3">
        <router-link v-for="o in idx.ojs.filter(o => o.type === 'district')" :key="o.key" :to="`/oj/${o.key}`"
          class="flex justify-between items-center px-4 py-3 rounded border border-l-[3px] transition-all duration-300 no-underline"
          style="background: var(--color-bg-alt); border-color: var(--color-border); border-left-color: #58a6ff"
          onmouseenter="this.style.borderColor='var(--color-accent)'"
          onmouseleave="this.style.borderColor='var(--color-border)';this.style.borderLeftColor='#58a6ff'">
          <span class="flex items-center gap-2 min-w-0">
            <span class="w-5 h-5 rounded flex-shrink-0 flex items-center justify-center text-xs font-bold" style="background: #58a6ff22; color: #58a6ff">📍</span>
            <span class="font-semibold text-sm truncate" style="font-family: var(--font-body); color: var(--color-fg)">{{ o.name }}</span>
          </span>
          <span class="text-xs whitespace-nowrap ml-2" style="font-family: var(--font-display); color: var(--color-muted-fg)">{{ o.count }} 题</span>
        </router-link>
      </div>
    </section>

    <!-- 词云 -->
    <section>
      <div class="flex items-center gap-3 mb-5">
        <span class="text-xs uppercase tracking-[0.25em]" style="font-family: var(--font-display); color: var(--color-accent)">Index</span>
        <div class="flex-1 h-px" style="background: linear-gradient(90deg, var(--color-border), transparent)"></div>
      </div>
      <h2 class="text-2xl font-medium mb-4" style="font-family: var(--font-heading); color: var(--color-fg)">🏷️ 标签</h2>
      <WordCloud :words="idx.tags.map(t => ({ text: t.name, weight: t.count }))" :height="260" :min-font-size="12" :max-font-size="42" />
    </section>
  </div>
  <div v-else class="text-center py-16" style="color: var(--color-muted-fg)">加载中...</div>
</template>
