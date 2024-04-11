#!/bin/bash

# ヘルプメッセージの定義
usage() {
    echo "usage: build vial -kb <keyboard>"
    echo "       build vial <keyboard>"
    echo "       build vial --help"
    echo "  Options:"
    echo "    -kb <keyboard>       Specify the keyboard name"
    echo "    --help               Show this help message and exit"
    exit 1
}


# 引数からオプションを取得
while [[ $# -gt 0 ]]; do
    key="$1"

    case $key in
        --help)
        usage
        exit 0
        ;;
        -kb)
        keyboard="$2"
        shift # オプション引数を飛ばす
        ;;
        *)
        # 入力が "gku34:tamago324" 形式の場合、それぞれの値を -kb と -km オプションに変換
        if [[ "$key" =~ ^([a-zA-Z0-9_/]+)$ ]]; then
            keyboard="$key"
        else
            # 不明なオプション
            echo "Unknown option: $key"
            usage
        fi
        shift # 次のオプションへ移動
        ;;
    esac
    shift # 次のオプションへ移動
done

# 必要なオプションが指定されていることを確認
if [ -z "$keyboard" ]; then
    usage
fi

# vialのディレクトリへ移動
cd /workspace/__vial__ || exit 1

# makeコマンドを実行
if ! make "$keyboard:vial"; then
    echo ""
    echo "********************"
    echo "* Build failed *"
    echo "********************"
    echo ""
    exit 1
fi

# ビルドが成功した場合は、ファイルをコピー
uf2_filename="$keyboard"_vial.uf2
if [ -f "$uf2_filename" ]; then
    cp "$uf2_filename" /workspace/"$uf2_filename" || exit 1
    echo ""
    echo "********************"
    echo "* Build successful *"
    echo "********************"
    echo ""
else
    echo ""
    echo "********************************************************"
    echo "* Failed to find the generated UF2 file: $uf2_filename *"
    echo "********************************************************"
    echo ""
    exit 1
fi
