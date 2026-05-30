#!/usr/bin/env bash
# ============================================================
#  compile-all.sh — 批量编译仓库中所有 C/C++ 源文件
# ============================================================
# 用法:
#   ./utils/compile-all.sh              # 编译全部
#   ./utils/compile-all.sh -j4          # 4 线程并行编译
#   ./utils/compile-all.sh --dry-run    # 仅列出文件，不编译
# ============================================================

set -euo pipefail

# --- 路径配置 -------------------------------------------------
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
SOURCE_DIR="$REPO_ROOT/source"
COMPILED_DIR="$REPO_ROOT/compiled"
LOG_DIR="$REPO_ROOT/com_log"

# --- 参数解析 -------------------------------------------------
JOBS=1
DRY_RUN=false

while [[ $# -gt 0 ]]; do
    case "$1" in
        -j*) JOBS="${1#-j}" ;;
        --dry-run) DRY_RUN=true ;;
        *) echo "未知参数: $1"; exit 1 ;;
    esac
    shift
done

# --- 初始化 ---------------------------------------------------
mkdir -p "$COMPILED_DIR" "$LOG_DIR"

TIMESTAMP=$(date +%Y-%m-%d_%H-%M-%S)
LOG_FILE="$LOG_DIR/${TIMESTAMP}_compile.log"

# 颜色
GREEN='\033[32m'
BLUE='\033[34m'
CYAN='\033[36m'
RED='\033[31m'
YELLOW='\033[1;33m'
RESET='\033[0m'

log()  { echo -e "$(date '+%Y-%m-%d %H:%M:%S') $1" | tee -a "$LOG_FILE"; }
ok()   { log "${GREEN}[OK]${RESET} $1"; }
info() { log "${BLUE}[INFO]${RESET} $1"; }
warn() { log "${YELLOW}[WARN]${RESET} $1"; }
fail() { log "${RED}[FAIL]${RESET} $1"; }

# --- 主逻辑 ---------------------------------------------------
info "编译开始 | 线程数: $JOBS | 根目录: $REPO_ROOT"

START_TS=$(date +%s)

# 收集所有 .cpp 和 .c 文件（排除 website/scripts 目录）
mapfile -t CPP_FILES < <(find "$SOURCE_DIR" -type f \( -name "*.cpp" -o -name "*.c" \) 2>/dev/null | sort)

if [[ ${#CPP_FILES[@]} -eq 0 ]]; then
    warn "未找到任何 C/C++ 源文件"
    exit 0
fi

info "找到 ${#CPP_FILES[@]} 个源文件"

# 编译单个文件的函数
compile_file() {
    local src="$1"
    local rel="${src#$SOURCE_DIR/}"
    local out_dir="$COMPILED_DIR/$(dirname "$rel")"
    local ext="${src##*.}"

    mkdir -p "$out_dir"

    local out="$out_dir/$(basename "$src" ".$ext")"

    if [[ "$ext" == "cpp" ]]; then
        g++ -std=c++17 -O2 -Wall -o "$out" "$src" 2>&1
    else
        gcc -std=c11 -O2 -Wall -o "$out" "$src" 2>&1
    fi
}

if $DRY_RUN; then
    info "--dry-run 模式: 仅列出文件"
    for f in "${CPP_FILES[@]}"; do
        echo "  ${f#$REPO_ROOT/}"
    done
else
    count=0
    pass=0
    total=${#CPP_FILES[@]}

    if [[ "$JOBS" -gt 1 ]]; then
        info "并行编译模式 (jobs=$JOBS)"
        # 使用后台进程池实现简易并行
        running=0
        for src in "${CPP_FILES[@]}"; do
            # 等待进程池有空位
            while [[ $running -ge $JOBS ]]; do
                wait -n 2>/dev/null || true
                running=$((running - 1))
            done
            compile_file "$src" &
            running=$((running + 1))
            count=$((count + 1))
        done
        wait
    else
        for src in "${CPP_FILES[@]}"; do
            count=$((count + 1))
            rel="${src#$REPO_ROOT/}"
            printf "${CYAN}[%3d/%3d]${RESET} %s ... " "$count" "$total" "$rel"
            if compile_file "$src"; then
                echo -e "${GREEN}PASS${RESET}"
                pass=$((pass + 1))
            else
                echo -e "${RED}FAIL${RESET}"
                fail "$rel"
            fi
        done
    fi
fi

END_TS=$(date +%s)
ELAPSED=$((END_TS - START_TS))

info "编译结束 | 耗时: ${ELAPSED}s | 总计: ${total:-0} 文件"
log "日志已保存至: $LOG_FILE"
