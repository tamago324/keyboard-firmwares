#!/bin/bash

# 現在のスクリプトのディレクトリの絶対パスを取得
SCRIPT_DIR=$(dirname "$(realpath "$0")")

# ヘルプメッセージの定義
usage() {
    echo "fwbuild <command> [options]"
    echo ""
    echo "Commands:"
    echo "  setup  Setup the environment"
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
setup)
    # __qmk__ サブモジュールの初期化
    cd /workspace
    qmk setup --home __qmk__ --yes
    qmk git-submodule
    
    # __vial__ サブモジュールの初期化
    cd /workspace/__vial__
    make git-submodule
    ;;
    
update)
    # __qmk__ サブモジュールの更新
    cd /workspace
    git submodule update --remote __qmk__
    qmk git-submodule

    # __vial__ サブモジュールの更新
    cd /workspace
    git submodule update --remote __qmk__
    cd /workspace/__vial__
    make git-submodule
    ;;
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
