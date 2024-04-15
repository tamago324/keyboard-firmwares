#!/bin/bash

# 現在のスクリプトのディレクトリの絶対パスを取得
SCRIPT_DIR=$(dirname "$(realpath "$0")")

# ヘルプメッセージの定義
usage() {
    echo "fwbuild <command> [options]"
    echo ""
    echo "Commands:"
    echo "  qmk    Build QMK firmware with specified options"
    echo "  vial   Build Vial firmware with specified options"
    echo ""
    echo "Options:"
    echo "  fwbuild <command> --help"
    exit 1
}

# 引数のチェック
if [ "$#" -lt 1 ]; then
    usage
fi

# コマンドの選択
command="$1"
shift
case "$command" in
qmk)
    source "${SCRIPT_DIR}/fwbuild_qmk.sh" "$@"
    ;;
vial)
    source "${SCRIPT_DIR}/fwbuild_vial.sh" "$@"
    ;;
*)
    echo "Unknown command: $command"
    usage
    ;;
esac
