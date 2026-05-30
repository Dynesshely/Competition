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

const md = new MarkdownIt({
  html: false,
  breaks: true,
  linkify: true,
  highlight(str, lang) {
    if (lang && hljs.getLanguage(lang)) {
      try { return '<pre class="hljs"><code>' + hljs.highlight(str, { language: lang, ignoreIllegals: true }).value + "</code></pre>"; }
      catch (_) {}
    }
    try { return '<pre class="hljs"><code>' + hljs.highlightAuto(str).value + "</code></pre>"; }
    catch (_) {}
    return '<pre class="hljs"><code>' + md.utils.escapeHtml(str) + "</code></pre>";
  },
});

md.use(texmath, {
  engine: katex,
  delimiters: ["dollars"],
  katexOptions: { macros: { "\\bm": "\\boldsymbol" }, throwOnError: false },
});

export function renderMarkdown(text) {
  if (!text) return "<p>暂无内容</p>";
  return md.render(text);
}

/**
 * 渲染代码并添加行号
 */
export function renderCode(code, lang) {
  if (!code) return "<p>暂无代码</p>";

  const language = lang ? lang.replace(".", "") : "";
  const lines = code.split("\n");

  // 逐行高亮，避免跨行标签被截断
  const highlighted = lines
    .map((line, i) => {
      const num = `<span class="line-no">${i + 1}</span>`;
      let content;
      if (language && hljs.getLanguage(language)) {
        content = hljs.highlight(line, { language, ignoreIllegals: true }).value;
      } else {
        content = hljs.highlightAuto(line).value;
      }
      return `<span class="line">${num}<span class="line-code">${content || " "}</span></span>`;
    })
    .join("");

  return `<pre class="hljs"><code>${highlighted}</code></pre>`;
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
