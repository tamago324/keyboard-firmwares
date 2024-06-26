#!/bin/bash

# 現在のスクリプトのディレクトリの絶対パスを取得
SCRIPT_DIR=$(dirname "$(realpath "$0")")

# ヘルプメッセージの定義
usage() {
    echo "fwbuild <command> [options]"
    echo ""
    echo "Commands:"
    echo "  fwbuild qmk     Build QMK firmware with specified options"
    echo "  fwbuild vial    Build Vial firmware with specified options"
    echo ""
    echo "Options:"
    echo "  fwbuild <command> --help    Show <command> help message"
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
    python3 "${SCRIPT_DIR}/fwbuild_qmk.py" "$@"
    ;;
vial)
    python3 "${SCRIPT_DIR}/fwbuild_vial.py" "$@"
    ;;
*)
    echo "Unknown command: $command"
    usage
    ;;
esac
