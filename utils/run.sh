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

    # --- 解析目标配置文件 -----------------------------------------
    TARGET="${2:-}"

    if [[ -z "$TARGET" ]]; then
        # 交互式选择
        echo "请选择要写入的配置文件:"
        echo ""

        # 收集可用的配置文件
        declare -A RC_FILES
        idx=1

        for rc in "$HOME/.bash_aliases" "$HOME/.bashrc" "$HOME/.zshrc"; do
            label="${rc#$HOME/}"
            if [[ -f "$rc" ]]; then
                printf "  ${GREEN}[%d]${RESET} %-20s (已存在)\n" "$idx" "$label"
            else
                printf "  ${GREEN}[%d]${RESET} %-20s (新建)\n" "$idx" "$label"
            fi
            RC_FILES["$idx"]="$rc"
            idx=$((idx + 1))
        done

        printf "  ${GREEN}[%d]${RESET} %s\n" "$idx" "自定义路径"

        echo ""
        read -r -p "输入序号 [1-$idx]: " CHOICE

        if [[ "$CHOICE" == "$idx" ]]; then
            read -r -p "输入配置文件完整路径: " TARGET
        elif [[ -n "${RC_FILES["$CHOICE"]:-}" ]]; then
            TARGET="${RC_FILES["$CHOICE"]}"
        else
            fail "无效选择"
            exit 1
        fi
    else
        # 允许短名（bashrc → ~/.bashrc 等）
        case "$TARGET" in
            bashrc)       TARGET="$HOME/.bashrc" ;;
            bash_aliases) TARGET="$HOME/.bash_aliases" ;;
            zshrc)        TARGET="$HOME/.zshrc" ;;
            .bashrc|.bash_aliases|.zshrc) TARGET="$HOME/$TARGET" ;;
        esac
    fi

    # --- 写入别名 ------------------------------------------------
    if grep -q "alias runcpp=" "$TARGET" 2>/dev/null; then
        sed -i "s|^alias runcpp=.*|$ALIAS_LINE|" "$TARGET"
        ok "已更新: $TARGET"
    else
        echo "$ALIAS_LINE" >> "$TARGET"
        ok "已写入: $TARGET"
    fi

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
