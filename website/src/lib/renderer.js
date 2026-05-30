/**
 * Markdown 渲染 + 代码高亮 + 数学公式
 */
import MarkdownIt from "markdown-it";
import texmath from "markdown-it-texmath";
import katex from "katex";
import hljs from "highlight.js/lib/core";
import cpp from "highlight.js/lib/languages/cpp";
import c from "highlight.js/lib/languages/c";
import java from "highlight.js/lib/languages/java";
import python from "highlight.js/lib/languages/python";
import pascal from "highlight.js/lib/languages/delphi";

hljs.registerLanguage("cpp", cpp);
hljs.registerLanguage("c", c);
hljs.registerLanguage("java", java);
hljs.registerLanguage("python", python);
hljs.registerLanguage("pascal", pascal);

// ─── 共享：带行号的代码高亮 ──────────────────────────────────
function highlightLines(str, lang) {
  const lines = str.split("\n");
  return lines
    .map((line, i) => {
      const num = `<span class="line-no">${i + 1}</span>`;
      let content;
      if (lang && hljs.getLanguage(lang)) {
        content = hljs.highlight(line, { language: lang, ignoreIllegals: true }).value;
      } else {
        content = hljs.highlightAuto(line).value;
      }
      return `<span class="line">${num}<span class="line-code">${content || " "}</span></span>`;
    })
    .join("");
}

// ─── markdown-it ────────────────────────────────────────────
const md = new MarkdownIt({
  html: false,
  breaks: true,
  linkify: true,
  highlight(str, lang) {
    const code = highlightLines(str, lang);
    return `<pre class="hljs md-code"><code>${code}</code></pre>`;
  },
});

md.use(texmath, {
  engine: katex,
  delimiters: ["dollars"],
  katexOptions: { macros: { "\\bm": "\\boldsymbol" }, throwOnError: false },
});

// ─── 公开 API ───────────────────────────────────────────────

/**
 * 渲染 Markdown → HTML
 */
export function renderMarkdown(text) {
  if (!text) return "<p>暂无内容</p>";
  return md.render(text);
}

/**
 * 渲染独立代码块（用于代码面板）
 */
export function renderCode(code, lang) {
  if (!code) return "<p>暂无代码</p>";
  const language = lang ? lang.replace(".", "") : "";
  return `<pre class="hljs"><code>${highlightLines(code, language)}</code></pre>`;
}

export function difficultyClass(difficulty) {
  const map = {
    "暂无评定": "e0", "入门": "e1", "普及−": "e2",
    "普及/提高−": "e3", "普及+/提高": "e4",
    "提高+/省选−": "e5", "省选/NOI−": "e6",
    "NOI/NOI+/CTSC": "e7",
  };
  return "diff-" + (map[difficulty] || "e0");
}
