<script setup>
import { ref, watch, onMounted } from "vue";
import { useRouter } from "vue-router";
import Fuse from "fuse.js";
import { loadIndex } from "../lib/index.js";
import { BookOpen, Monitor, Moon, Sun } from "lucide-vue-next";

const router = useRouter();
const query = ref(""); const results = ref([]); const showDropdown = ref(false);
let fuse = null;
loadIndex().then(idx => {
  fuse = new Fuse(idx.problems || [], {
    keys: [{ name: "id", weight: 2 }, { name: "title", weight: 1.5 }, { name: "tags", weight: 1 }, { name: "ojName", weight: 0.5 }],
    threshold: 0.4, distance: 100,
  });
});
watch(query, val => {
  if (!val.trim() || !fuse) { results.value = []; showDropdown.value = false; return; }
  results.value = fuse.search(val).slice(0, 10); showDropdown.value = true;
});
function goTo(oj, pid) { query.value = ""; showDropdown.value = false; router.push(`/problem/${oj}/${pid}`); }
function closeDropdown(e) { if (!e.target.closest(".search-area")) showDropdown.value = false; }

// ── 主题 ──
const theme = ref("system");
function getCookie(n) { const m = document.cookie.match(new RegExp("(?:^|;\\s*)" + n + "=([^;]*)")); return m ? m[1] : null; }
function setCookie(n, v, d) { const dt = new Date(); dt.setTime(dt.getTime() + d * 864e5); document.cookie = n + "=" + v + ";path=/;expires=" + dt.toUTCString() + ";SameSite=Lax"; }
function resolveTheme(t) { return t === "system" ? (window.matchMedia("(prefers-color-scheme: light)").matches ? "light" : "dark") : t; }
function applyTheme(t) { document.documentElement.setAttribute("data-theme", resolveTheme(t)); }
onMounted(() => { theme.value = getCookie("academia-theme") || "system"; applyTheme(theme.value); });
function cycleTheme() {
  const order = ["system", "dark", "light"]; const idx = order.indexOf(theme.value);
  theme.value = order[(idx + 1) % 3]; setCookie("academia-theme", theme.value, 365); applyTheme(theme.value);
}
const themeIcon = { system: Monitor, dark: Moon, light: Sun };
</script>

<template>
  <nav class="sticky top-0 z-100 flex items-center justify-between h-[52px] px-4 sm:px-6 border-b backdrop-blur-md transition-theme"
    :style="{ background: `color-mix(in srgb, var(--color-bg-alt) 95%, transparent)`, borderColor: 'var(--color-border)' }"
    @click="closeDropdown">
    <router-link to="/" class="font-bold text-lg no-underline whitespace-nowrap tracking-tight" style="font-family: var(--font-heading); color: var(--color-fg)">
      <BookOpen :size="18" class="inline-block mr-1 -mt-0.5" style="color: var(--color-accent)" />Dynesshely's OI Solutions
    </router-link>

    <div class="flex items-center gap-2">
      <div class="search-area relative w-[180px] sm:w-[240px]">
        <input v-model="query" type="text" placeholder="搜索题目..." autocomplete="off"
          class="input-academia w-full h-9 px-3 rounded text-sm outline-none transition-theme"
          :style="{ background: 'var(--color-bg)', border: `1px solid var(--color-border)`, color: 'var(--color-fg)', fontFamily: 'var(--font-body)' }"
          @focus="query && (showDropdown = true)" />
        <div v-if="showDropdown && results.length"
          class="absolute top-[42px] left-0 right-0 rounded-lg max-h-[360px] overflow-y-auto z-200 shadow-xl border transition-theme"
          :style="{ background: 'var(--color-bg-alt)', borderColor: 'var(--color-border)' }">
          <div v-if="results.length === 0" class="p-3 text-center text-sm" style="color: var(--color-muted-fg)">无匹配结果</div>
          <a v-for="r in results" :key="r.item.id" href="javascript:void(0)"
            class="search-item no-underline" style="color: var(--color-fg); border-color: var(--color-border)"
            @click="goTo(r.item.oj || 'www.luogu.com.cn', r.item.id)">
            <span class="font-bold font-mono min-w-[60px]" style="color: var(--color-accent)">{{ r.item.id }}</span>
            <span class="flex-1">{{ r.item.title }}</span>
            <span class="text-xs" style="color: var(--color-muted-fg)">{{ r.item.ojName }}</span>
          </a>
        </div>
      </div>

      <button @click="cycleTheme" :title="'主题: ' + theme"
        class="w-8 h-8 flex items-center justify-center rounded-full border text-sm cursor-pointer transition-theme hover-accent-border"
        :style="{ background: 'var(--color-bg)', borderColor: 'var(--color-border)', color: 'var(--color-accent)' }">
        <component :is="themeIcon[theme] || Monitor" :size="15" />
      </button>
    </div>
  </nav>
</template>
