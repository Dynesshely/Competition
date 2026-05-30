import { createApp } from "vue";
import { createRouter, createWebHashHistory } from "vue-router";
import App from "./App.vue";
import HomePage from "./pages/HomePage.vue";
import OJListPage from "./pages/OJListPage.vue";
import ProblemPage from "./pages/ProblemPage.vue";
import "./styles/main.css";
import "highlight.js/styles/github-dark.min.css";
import "katex/dist/katex.min.css";

const routes = [
  { path: "/", component: HomePage },
  { path: "/oj/:key", component: OJListPage },
  { path: "/problem/:oj/:pid", component: ProblemPage },
];

const router = createRouter({
  history: createWebHashHistory(),
  routes,
});

createApp(App).use(router).mount("#app");
