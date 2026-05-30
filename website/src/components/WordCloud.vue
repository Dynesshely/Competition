<script setup>
import { ref, onMounted, nextTick } from "vue";
import { useRouter } from "vue-router";

const router = useRouter();
const props = defineProps({
  words: { type: Array, default: () => [] },
  minFontSize: { type: Number, default: 12 },
  maxFontSize: { type: Number, default: 42 },
  colors: {
    type: Array,
    default: () => [
      "#C9A962",
      "#8B2635",
      "#6B5E4A",
      "#9C8B7A",
      "#4A3F35",
      "#C4B99A",
    ],
  },
  width: { type: Number, default: 0 },
  height: { type: Number, default: 260 },
});

const containerRef = ref(null);
const placedWords = ref([]);

function compute() {
  const words = props.words;
  if (!words.length) {
    placedWords.value = [];
    return;
  }
  const W = props.width || 700;
  const H = props.height;
  const sorted = [...words].sort((a, b) => b.weight - a.weight);
  const maxW = sorted[0]?.weight || 1;
  const minW = sorted[sorted.length - 1]?.weight || 1;
  const range = maxW - minW || 1;
  const placed = [];
  const result = [];
  const measure = document.createElement("canvas").getContext("2d");
  for (const word of sorted) {
    const fontSize =
      props.minFontSize +
      ((word.weight - minW) / range) * (props.maxFontSize - props.minFontSize);
    const color = props.colors[Math.floor(Math.random() * props.colors.length)];
    measure.font = `bold ${fontSize}px "Cormorant Garamond", "Noto Sans SC", serif`;
    const metrics = measure.measureText(word.text);
    const tw = metrics.width + 8;
    const th = fontSize + 6;
    let cx = W / 2,
      cy = H / 2,
      angle = Math.random() * Math.PI * 2,
      radius = 0,
      found = false;
    for (let step = 0; step < 3000 && !found; step++) {
      const x = cx + Math.cos(angle) * radius - tw / 2;
      const y = cy + Math.sin(angle) * radius - th / 2;
      if (x > 2 && y > 2 && x + tw < W - 2 && y + th < H - 2) {
        let overlap = false;
        for (const r of placed) {
          if (x < r.x + r.w && x + tw > r.x && y < r.y + r.h && y + th > r.y) {
            overlap = true;
            break;
          }
        }
        if (!overlap) {
          found = true;
          placed.push({ x, y, w: tw, h: th });
          result.push({ text: word.text, x, y, w: tw, h: th, fontSize, color });
        }
      }
      angle += 0.25;
      radius += 1.2;
    }
  }
  placedWords.value = result;
}

function onClick(word) {
  router.push(`/oj/www.luogu.com.cn?tag=${encodeURIComponent(word.text)}`);
}
onMounted(() => nextTick(compute));
</script>

<template>
  <div
    ref="containerRef"
    class="relative rounded-lg overflow-hidden select-none border"
    :style="{
      minHeight: height + 'px',
      height: height + 50 + 'px',
      background: 'var(--color-bg-alt)',
      borderColor: 'var(--color-border)',
    }"
  >
    <p
      v-if="!placedWords.length"
      class="text-center absolute inset-0 flex items-center justify-center"
      style="color: var(--color-muted-fg)"
    >
      暂无标签
    </p>
    <div class="relative max-w-175 mx-auto my-6">
      <a
        v-for="(w, i) in placedWords"
        :key="i"
        href="javascript:void(0)"
        class="absolute font-bold no-underline hover:opacity-80 hover:scale-110 transition-transform duration-150 whitespace-nowrap"
        :style="{
          left: w.x + 'px',
          top: w.y + 'px',
          fontSize: w.fontSize + 'px',
          color: w.color,
          fontFamily: 'var(--font-heading)',
        }"
        @click="onClick(w)"
        >{{ w.text }}</a
      >
    </div>
  </div>
</template>
