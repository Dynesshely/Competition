# 洛谷题库评测 API

> 供 OpenApp 将代码发回洛谷完成评测，适用于洛谷公开题库（RemoteJudge 除外）。

---

## 目录

- [1. 提交评测](#1-提交评测) — `POST /judge/problem`
- [2. 查询结果](#2-查询结果) — `GET /judge/result`
- [3. 数据结构](#3-数据结构)
  - [JudgeRecord](#judgerecord)
  - [CompileResult](#compileresult)
  - [JudgeResult](#judgeresult)
  - [Subtask](#subtask)
  - [TestCase](#testcase)
- [4. 状态码速查](#4-状态码速查)
- [5. 语言支持列表](#5-语言支持列表)

---

## 1. 提交评测

```
POST /judge/problem
```

将代码提交到洛谷评测。**异步接口**，仅返回 `requestId`。

> 结果保存 **15 分钟**，请及时查询。被动推送结果通过 WebSocket 频道 `judge.result`。

### 请求参数

| 参数 | 类型 | 必填 | 说明 |
|------|------|------|------|
| `pid` | `string` | ✅ | 题目 PID，如 `"P1001"` |
| `lang` | `string` | ✅ | 代码语言，见 [语言支持列表](#5-语言支持列表) |
| `code` | `string` | ✅ | 要评测的源代码 |
| `o2` | `boolean` | ❌ | 是否开启 `-O2` 编译优化。受题目限制，最终是否启用以编译结果中的返回为准 |
| `trackId` | `string` (≤64) | ❌ | 自定义追踪 ID，结果中原样返回 |

### 请求示例

```json
{
  "pid": "P1001",
  "lang": "cxx/17/gcc",
  "o2": true,
  "code": "#include <stdio.h>\nint main() {\n    int a,b;\n    scanf(\"%d%d\",&a,&b);\n    printf(\"%d\\n\", a+b);\n    return 0;\n}\n",
  "trackId": "my-submission-001"
}
```

### 响应

| 状态码 | 含义 |
|--------|------|
| `200 OK` | 提交成功，返回 `requestId` |
| `4xx` | 参数错误 |

---

## 2. 查询结果

```
GET /judge/result?id=<requestId>
```

通过 `requestId` 主动查询评测结果。

### 响应状态

| 状态码 | 含义 |
|--------|------|
| `200 OK` | 已有结果（部分或全部），返回 [JudgeRecord](#judgerecord) |
| `204 No Content` | 评测尚未完成，无结果产生 |

### 响应结构

| 字段 | 类型 | 说明 |
|------|------|------|
| `type` | `"judge"` | 固定值 |
| `data` | `object` | [JudgeRecord](#judgerecord) 评测记录 |
| `requestId` | `string` | 提交时返回的异步请求 ID |
| `trackId` | `string` | 提交时传入的自定义追踪 ID，原样返回 |

### 响应示例

```json
{
  "type": "judge",
  "data": {
    "compile": { "success": true, "message": null, "opt2": true },
    "judge": {
      "id": 0,
      "status": 0,
      "score": 100,
      "time": 15,
      "memory": 4096,
      "subtasks": [
        {
          "id": 0,
          "status": 0,
          "score": 100,
          "time": 15,
          "memory": 4096,
          "cases": [
            {
              "id": 0,
              "status": 0,
              "score": 10,
              "time": 3,
              "memory": 1024,
              "signal": 0,
              "exitCode": 0,
              "description": "Accepted"
            }
          ]
        }
      ]
    }
  },
  "requestId": "1BwHdxEa4LTFnL619bxRwC",
  "trackId": "my-submission-001"
}
```

---

## 3. 数据结构

### JudgeRecord

顶层结果对象，包含编译和评测两部分。

| 字段 | 类型 | 说明 |
|------|------|------|
| `compile` | `object` | [CompileResult](#compileresult) 编译结果 |
| `judge` | `object` | [JudgeResult](#judgeresult) 评测结果 |

### CompileResult

| 字段 | 类型 | 说明 |
|------|------|------|
| `success` | `boolean` | 编译是否成功 |
| `message` | `string` | 编译器的输出信息（警告、错误等） |
| `opt2` | `boolean` | 实际是否启用了 `-O2` 优化 |

### JudgeResult

| 字段 | 类型 | 说明 |
|------|------|------|
| `id` | `int` | 评测记录 ID |
| `status` | `int` | 整体评测状态，见 [状态码速查](#4-状态码速查) |
| `score` | `int` | 总分 |
| `time` | `int` | 总用时（ms） |
| `memory` | `int` | 最大内存（KB） |
| `subtasks` | `array` | [Subtask](#subtask) 列表 |

### Subtask

| 字段 | 类型 | 说明 |
|------|------|------|
| `id` | `int` | 子任务编号 |
| `status` | `int` | 子任务状态 |
| `score` | `int` | 子任务得分 |
| `time` | `int` | 子任务用时（ms） |
| `memory` | `int` | 子任务最大内存（KB） |
| `cases` | `array` | [TestCase](#testcase) 列表 |

### TestCase

| 字段 | 类型 | 说明 |
|------|------|------|
| `id` | `int` | 测试点编号 |
| `status` | `int` | 测试点状态 |
| `score` | `int` | 测试点得分 |
| `time` | `int` | 用时（ms） |
| `memory` | `int` | 内存（KB） |
| `signal` | `int` | 程序收到的信号（非 0 表示异常终止） |
| `exitCode` | `int` | 程序退出码 |
| `description` | `string` | 状态描述文本 |

---

## 4. 状态码速查

评测状态在各层级（`JudgeResult` / `Subtask` / `TestCase`）的 `status` 字段中统一使用。

| 状态码 | 含义 |
|--------|------|
| `0` | Accepted（通过） |
| `1` | Wrong Answer（答案错误） |
| `2` | Time Limit Exceeded（超时） |
| `3` | Memory Limit Exceeded（超内存） |
| `4` | Runtime Error（运行时错误） |
| `5` | Compile Error（编译错误） |
| `6` | Unknown Error（未知错误） |

---

## 5. 语言支持列表

常用语言标识符：

| 标识符 | 语言 |
|--------|------|
| `cxx/17/gcc` | C++17 (GCC) |
| `cxx/14/gcc` | C++14 (GCC) |
| `cxx/11/gcc` | C++11 (GCC) |
| `c/11/gcc` | C11 (GCC) |
| `python3/cpython` | Python 3 |
| `java/8` | Java 8 |
| `pascal/fpc` | Pascal (Free Pascal) |
