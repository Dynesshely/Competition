#!/usr/bin/env bash
# ============================================================
#  luogu.sh — 洛谷自动提交 CLI 便捷包装脚本
# ============================================================
# 用法:
#   ./utils/luogu.sh submit <file.cpp>
#   ./utils/luogu.sh batch <directory>
#   ./utils/luogu.sh install
#   ./utils/luogu.sh --install        # 安装 luogu 别名
#
# 说明:
#   自动定位项目下的 CLI 入口并转发参数。
#   传入的文件/目录路径会自动转为绝对路径，确保相对路径正确解析。
# ============================================================

set -euo pipefail

# --- 颜色定义 -------------------------------------------------
GREEN='\033[32m'
BLUE='\033[34m'
RED='\033[31m'
RESET='\033[0m'

ok()   { echo -e " ${GREEN}[OK]${RESET} $1"; }
info() { echo -e "${BLUE}[INFO]${RESET} $1"; }
fail() { echo -e " ${RED}[FAIL]${RESET} $1"; }

# --- 路径解析 -------------------------------------------------
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
CLI_DIR="$REPO_ROOT/utils/chromium-ext-auto-submit/packages/cli"

# --- install 模式 -----------------------------------------------
if [[ "${1:-}" == "--install" ]]; then
    SCRIPT_PATH="$SCRIPT_DIR/luogu.sh"

    if [[ ! -x "$SCRIPT_PATH" ]]; then
        chmod +x "$SCRIPT_PATH"
    fi

    ALIAS_LINE="alias luogu='$SCRIPT_PATH'"

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

    # 去重写入
    if grep -q "alias luogu=" "$TARGET" 2>/dev/null; then
        sed -i "s|^alias luogu=.*|$ALIAS_LINE|" "$TARGET"
        ok "已更新: $TARGET"
    else
        echo "$ALIAS_LINE" >> "$TARGET"
        ok "已写入: $TARGET"
    fi

    info "在当前终端执行以下命令使其立即生效:"
    echo ""
    echo -e "    ${GREEN}eval \"$ALIAS_LINE\"${RESET}"
    echo ""
    info "新终端中打开即可直接使用: luogu submit P1000.cpp"

    exit 0
fi

# --- 参数校验 -------------------------------------------------
if [[ $# -lt 1 ]]; then
    echo "用法: $0 <command> [args...]"
    echo "      $0 --install"
    echo ""
    echo "命令:"
    echo "  submit <file.cpp>     提交单个代码文件"
    echo "  batch <directory>     批量提交目录中的 .cpp 文件"
    echo "  install               显示安装指引"
    echo ""
    echo "示例:"
    echo "  $0 submit P1000.cpp"
    echo "  $0 batch ./source/website/www.luogu.com.cn/"
    echo "  $0 --install"
    exit 1
fi

# --- 检查 node -------------------------------------------------
if ! command -v node &>/dev/null; then
    fail "node 未安装或不在 PATH 中"
    exit 1
fi

# --- 检查 CLI 是否已构建 ----------------------------------------
CLI_ENTRY="$CLI_DIR/dist/index.js"
if [[ ! -f "$CLI_ENTRY" ]]; then
    fail "CLI 未构建，请先在项目中运行: pnpm build"
    exit 1
fi

# --- 处理参数：文件/目录路径转为绝对路径 --------------------------
ARGS=()
for arg in "$@"; do
    # 如果看起来像文件路径（以 ./ ../ ~/ / 开头或包含扩展名），转为绝对路径
    if [[ "$arg" == ./* ]] || [[ "$arg" == ../* ]] || [[ "$arg" == /* ]] || [[ "$arg" == ~/* ]]; then
        # 相对于当前工作目录解析
        RESOLVED="$(cd "$(dirname "$arg")" 2>/dev/null && pwd)/$(basename "$arg")" || true
        if [[ -n "$RESOLVED" ]]; then
            ARGS+=("$RESOLVED")
        else
            ARGS+=("$arg")
        fi
    else
        ARGS+=("$arg")
    fi
done

# --- 执行 CLI -------------------------------------------------
exec node "$CLI_ENTRY" "${ARGS[@]}"
