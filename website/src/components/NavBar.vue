<script setup>
import { ref, watch } from "vue";
import { useRouter } from "vue-router";
import Fuse from "fuse.js";
import { loadIndex } from "../lib/index.js";

const router = useRouter();
const query = ref("");
const results = ref([]);
const showDropdown = ref(false);

let fuse = null;

loadIndex().then((idx) => {
  fuse = new Fuse(idx.problems || [], {
    keys: [
      { name: "id", weight: 2 },
      { name: "title", weight: 1.5 },
      { name: "tags", weight: 1 },
      { name: "ojName", weight: 0.5 },
    ],
    threshold: 0.4,
    distance: 100,
  });
});

watch(query, (val) => {
  if (!val.trim() || !fuse) {
    results.value = [];
    showDropdown.value = false;
    return;
  }
  results.value = fuse.search(val).slice(0, 10);
  showDropdown.value = true;
});

function goTo(oj, pid) {
  query.value = "";
  showDropdown.value = false;
  router.push(`/problem/${oj}/${pid}`);
}

function closeDropdown(e) {
  if (!e.target.closest(".search-area")) {
    showDropdown.value = false;
  }
}
</script>

<template>
  <nav class="sticky top-0 z-100 flex items-center justify-between h-[52px] px-4 sm:px-6 bg-[#161822]/95 border-b border-[#2a2d3a] backdrop-blur-md" @click="closeDropdown">
    <router-link to="/" class="font-bold text-base text-[#c9d1d9] hover:text-[#00d4aa] no-underline whitespace-nowrap">
      🏆 Dynesshely's OI Solutions
    </router-link>
    <div class="search-area relative w-[200px] sm:w-[280px]">
      <input
        v-model="query"
        type="text"
        placeholder="搜索题目..."
        autocomplete="off"
        class="w-full py-1.5 px-3 bg-[#0f1117] border border-[#2a2d3a] rounded-md text-sm text-[#c9d1d9] outline-none focus:border-[#00d4aa] placeholder:text-[#6e7681]"
        @focus="query && (showDropdown = true)"
      />
      <div
        v-if="showDropdown && results.length"
        class="absolute top-[38px] left-0 right-0 bg-[#161822] border border-[#2a2d3a] rounded-lg max-h-[360px] overflow-y-auto z-200 shadow-xl"
      >
        <div v-if="results.length === 0" class="p-3 text-center text-sm text-[#6e7681]">无匹配结果</div>
        <a
          v-for="r in results"
          :key="r.item.id"
          href="javascript:void(0)"
          class="flex gap-2 px-3 py-2 text-sm text-[#c9d1d9] border-b border-[#2a2d3a] last:border-b-0 hover:bg-[#00d4aa22] no-underline items-center"
          @click="goTo(r.item.oj || 'www.luogu.com.cn', r.item.id)"
        >
          <span class="font-bold text-[#00d4aa] font-mono min-w-[60px]">{{ r.item.id }}</span>
          <span class="flex-1">{{ r.item.title }}</span>
          <span class="text-xs text-[#6e7681]">{{ r.item.ojName }}</span>
        </a>
      </div>
    </div>
  </nav>
</template>
