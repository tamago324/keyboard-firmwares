#!/bin/bash

# デフォルト値の設定
version=""

# 引数からオプションを取得
while [[ $# -gt 0 ]]; do
    key="$1"

    case $key in
        -kb)
        keyboard="$2"
        shift # オプション引数を飛ばす
        ;;
        -km)
        keymap="$2"
        shift # オプション引数を飛ばす
        ;;
        -version)
        version="$2"
        shift # オプション引数を飛ばす
        ;;
        *)
        # 不明なオプション
        echo "Unknown option: $key"
        exit 1
        ;;
    esac
    shift # 次のオプションへ移動
done

# 必要なオプションが指定されていることを確認
if [ -z "$keyboard" ] || [ -z "$keymap" ]; then
    echo "Usage: build_qmk -kb <keyboard> -km <keymap> [-version <version>]"
    exit 1
fi

# QMKのリポジトリへ移動
cd /workspace/__qmk__ || exit 1

# -versionオプションが指定されている場合は指定されたバージョンにチェックアウト
if [ -n "$version" ]; then
    git checkout tags/"$version" || exit 1
    qmk git-submodule
fi

# QMKをビルド
if ! qmk compile -j 4 -kb "$keyboard" -km "$keymap"; then
    echo ""
    echo "********************"
    echo "* Build failed *"
    echo "********************"
    echo ""
    exit 1
fi

# ビルドが成功した場合は、ファイルをコピー
uf2_filename="$keyboard"_"$keymap".uf2
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

