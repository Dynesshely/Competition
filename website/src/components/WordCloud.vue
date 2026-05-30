<script setup>
import { ref, onMounted, watch, nextTick } from "vue";

const props = defineProps({
  words: { type: Array, default: () => [] },
  minFontSize: { type: Number, default: 12 },
  maxFontSize: { type: Number, default: 42 },
  colors: {
    type: Array,
    default: () => ["#00d4aa", "#58a6ff", "#f0c000", "#f0883e", "#f85149", "#a371f7"],
  },
  width: { type: Number, default: 0 },
  height: { type: Number, default: 260 },
});

const canvasRef = ref(null);

function render() {
  const canvas = canvasRef.value;
  if (!canvas || !props.words.length) return;

  const dpr = window.devicePixelRatio || 1;
  const W = props.width || canvas.parentElement?.clientWidth || 600;
  const H = props.height;

  canvas.width = W * dpr;
  canvas.height = H * dpr;
  canvas.style.width = W + "px";
  canvas.style.height = H + "px";

  const ctx = canvas.getContext("2d");
  ctx.scale(dpr, dpr);

  const sorted = [...props.words].sort((a, b) => b.weight - a.weight);
  const maxW = sorted[0]?.weight || 1;
  const minW = sorted[sorted.length - 1]?.weight || 1;
  const range = maxW - minW || 1;
  const placed = [];

  for (const word of sorted) {
    const fontSize = props.minFontSize + ((word.weight - minW) / range) * (props.maxFontSize - props.minFontSize);
    const color = props.colors[Math.floor(Math.random() * props.colors.length)];
    ctx.font = `bold ${fontSize}px -apple-system, "Noto Sans SC", sans-serif`;
    const metrics = ctx.measureText(word.text);
    const tw = metrics.width + 6;
    const th = fontSize + 4;

    let cx = W / 2, cy = H / 2, angle = Math.random() * Math.PI * 2, radius = 0, found = false;

    for (let step = 0; step < 3000 && !found; step++) {
      const x = cx + Math.cos(angle) * radius - tw / 2;
      const y = cy + Math.sin(angle) * radius - th / 2;
      if (x > 4 && y > 4 && x + tw < W - 4 && y + th < H - 4) {
        let overlap = false;
        for (const r of placed) {
          if (x < r.x + r.w && x + tw > r.x && y < r.y + r.h && y + th > r.y) { overlap = true; break; }
        }
        if (!overlap) {
          found = true;
          ctx.fillStyle = color;
          ctx.fillText(word.text, x + 3, y + fontSize);
          placed.push({ x, y, w: tw, h: th });
        }
      }
      angle += 0.25;
      radius += 1.2;
    }
  }
}

onMounted(() => nextTick(render));
watch(() => props.words, () => nextTick(render), { deep: true });
</script>

<template>
  <div class="flex justify-center bg-[#161822] border border-[#2a2d3a] rounded-lg p-4" :style="{ minHeight: height + 'px' }">
    <canvas v-if="words.length" ref="canvasRef" class="max-w-full" />
    <p v-else class="text-[#6e7681] self-center">暂无标签</p>
  </div>
</template>
