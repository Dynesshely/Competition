#!/usr/bin/env bash
# ============================================================
#  run.sh — 编译并运行单个 C++ 题解代码
# ============================================================
# 用法:
#   ./utils/run.sh source/website/www.luogu.com.cn/P1000.cpp
#   ./utils/run.sh /absolute/path/to/P1001.cpp
#
# 流程:
#   1. g++ -std=c++17 -O2 <src> -o <src>.out
#   2. chmod +x <src>.out
#   3. ./<src>.out
# ============================================================

set -euo pipefail

# --- 颜色定义 -------------------------------------------------
GREEN='\033[32m'
BLUE='\033[34m'
RED='\033[31m'
YELLOW='\033[1;33m'
RESET='\033[0m'

ok()   { echo -e " ${GREEN}[OK]${RESET} $1"; }
info() { echo -e "${BLUE}[INFO]${RESET} $1"; }
fail() { echo -e " ${RED}[FAIL]${RESET} $1"; }

# --- 参数解析 -------------------------------------------------
if [[ $# -lt 1 ]]; then
    echo "用法: $0 <source.cpp>"
    echo "      $0 --install"
    echo ""
    echo "参数:"
    echo "  source.cpp    要编译运行的 C++ 源文件路径"
    echo "  --install     在当前终端环境中注册 runcpp 命令别名"
    echo ""
    echo "示例:"
    echo "  $0 source/website/www.luogu.com.cn/P1000.cpp"
    echo "  $0 /absolute/path/to/P1001.cpp"
    echo "  $0 --install           # 安装后可直接使用: runcpp P1000.cpp"
    exit 1
fi

# --- install 模式 -----------------------------------------------
if [[ "$1" == "--install" ]]; then
    SCRIPT_PATH="$(cd "$(dirname "$0")" && pwd)/run.sh"

    # 检查脚本自身是否可执行
    if [[ ! -x "$SCRIPT_PATH" ]]; then
        chmod +x "$SCRIPT_PATH"
    fi

    ALIAS_LINE="alias runcpp='$SCRIPT_PATH'"

    # 记录实际写入的配置文件列表
    INSTALLED=()

    # ~/.bashrc
    if [[ -f "$HOME/.bashrc" ]]; then
        if grep -q "alias runcpp=" "$HOME/.bashrc" 2>/dev/null; then
            # 替换已有的 alias runcpp=...
            sed -i "s|^alias runcpp=.*|$ALIAS_LINE|" "$HOME/.bashrc"
        else
            echo "$ALIAS_LINE" >> "$HOME/.bashrc"
        fi
        INSTALLED+=("~/.bashrc")
    fi

    # ~/.bash_aliases
    if [[ -f "$HOME/.bash_aliases" ]]; then
        if grep -q "alias runcpp=" "$HOME/.bash_aliases" 2>/dev/null; then
            sed -i "s|^alias runcpp=.*|$ALIAS_LINE|" "$HOME/.bash_aliases"
        else
            echo "$ALIAS_LINE" >> "$HOME/.bash_aliases"
        fi
        INSTALLED+=("~/.bash_aliases")
    fi

    # ~/.zshrc
    if [[ -f "$HOME/.zshrc" ]]; then
        if grep -q "alias runcpp=" "$HOME/.zshrc" 2>/dev/null; then
            sed -i "s|^alias runcpp=.*|$ALIAS_LINE|" "$HOME/.zshrc"
        else
            echo "$ALIAS_LINE" >> "$HOME/.zshrc"
        fi
        INSTALLED+=("~/.zshrc")
    fi

    # 兜底：如果以上都不存在，写入 ~/.bashrc
    if [[ ${#INSTALLED[@]} -eq 0 ]]; then
        echo "$ALIAS_LINE" >> "$HOME/.bashrc"
        INSTALLED+=("~/.bashrc")
    fi

    ok "别名已写入: ${INSTALLED[*]}"
    info "在当前终端执行以下命令使其立即生效:"
    echo ""
    echo -e "    ${GREEN}eval \"$ALIAS_LINE\"${RESET}"
    echo ""
    info "新终端中打开即可直接使用: runcpp <source.cpp>"

    exit 0
fi

SRC="$1"

# --- 输入校验 -------------------------------------------------
if [[ ! -f "$SRC" ]]; then
    fail "文件不存在: $SRC"
    exit 1
fi

if [[ "$SRC" != *.cpp ]]; then
    fail "不是 .cpp 文件: $SRC"
    exit 1
fi

# --- 路径处理 -------------------------------------------------
SRC_DIR="$(cd "$(dirname "$SRC")" && pwd)"
SRC_NAME="$(basename "$SRC" .cpp)"
OUT="$SRC_DIR/$SRC_NAME.out"

# --- 编译 -----------------------------------------------------
info "编译: $SRC"
echo -ne "${YELLOW}"

if g++ -std=c++17 -O2 -Wall -o "$OUT" "$SRC"; then
    echo -ne "${RESET}"
    ok "编译成功 -> $OUT"
else
    echo -ne "${RESET}"
    fail "编译失败"
    exit 1
fi

# --- 赋予执行权限 ----------------------------------------------
chmod +x "$OUT"

# --- 运行 -----------------------------------------------------
info "运行: $OUT"
echo "────────────────────────────────────────────────────────────"

"$OUT"

echo "────────────────────────────────────────────────────────────"
ok "运行结束"
