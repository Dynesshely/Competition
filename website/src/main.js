import { createApp } from "vue";
import { createRouter, createWebHashHistory } from "vue-router";
import App from "./App.vue";
import HomePage from "./pages/HomePage.vue";
import OJListPage from "./pages/OJListPage.vue";
import ProblemPage from "./pages/ProblemPage.vue";
import "./styles/main.css";
import "katex/dist/katex.min.css";

// highlight.js 双主题 — 通过 URL 导入，运行时按 data-theme 切换
import hljsDark from "highlight.js/styles/github-dark.min.css?url";
import hljsLight from "highlight.js/styles/github.min.css?url";

const HLJS_THEMES = { dark: hljsDark, light: hljsLight };

// 在 <head> 中创建 highlight.js 主题 <link>，随 data-theme 动态切换
const hljsLink = document.createElement("link");
hljsLink.rel = "stylesheet";
hljsLink.id = "hljs-theme";
document.head.appendChild(hljsLink);

function applyHljsTheme() {
  const t = document.documentElement.getAttribute("data-theme") || "dark";
  hljsLink.href = HLJS_THEMES[t] || HLJS_THEMES.dark;
}
applyHljsTheme();

// 监听主题变化（由 NavBar 或其他组件触发）
new MutationObserver(applyHljsTheme).observe(document.documentElement, {
  attributes: true,
  attributeFilter: ["data-theme"],
});

// ── Vue 应用 ──────────────────────────────────────────────
const routes = [
  { path: "/", component: HomePage },
  { path: "/oj/:key", component: OJListPage },
  { path: "/problem/:oj/:pid", component: ProblemPage },
];

const router = createRouter({ history: createWebHashHistory(), routes });
createApp(App).use(router).mount("#app");
