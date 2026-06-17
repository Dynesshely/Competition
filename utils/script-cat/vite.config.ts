import { defineConfig } from 'vite'
import monkey from 'vite-plugin-monkey'

export default defineConfig({
  plugins: [
    monkey({
      entry: 'src/main.ts',
      userscript: {
        name: '洛谷助手',
        namespace: 'com.luogu.userscript',
        version: '0.0.1',
        description: '洛谷题目页面增强脚本',
        author: 'Dynesshely',
        match: ['https://www.luogu.com.cn/*'],
        icon: 'https://www.luogu.com.cn/favicon.ico',
        license: 'MIT',
      },
      build: {
        externalGlobals: {},
      },
    }),
  ],
})
