#!/bin/bash

# デフォルト値の設定
version=""

# ヘルプメッセージの定義
usage() {
    echo "fwbuild qmk <options>"
    echo ""
    echo "Commands:"
    echo "  fwbuild qmk <keyboard>:<keymap> [-v <version>]"
    echo "  fwbuild qmk --versions"
    echo "  fwbuild qmk --help"
    echo ""
    echo "Options:"
    echo "  -v <version>   Specify the QMK firmware version. If not specified, the latest tag will be used."
    echo "  --versions     List available QMK firmware versions"
    echo "  --help         Show this help message and exit"
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
    -v)
        version="$2"
        shift # オプション引数を飛ばす
        ;;
    --versions)
        # if [ -n "$version" ]; then
        #     echo "[fwbuild_qmk] '--versions' option cannot be used with other options like '-version'"
        #     exit 1
        # fi
        list_tags="true"
        ;;
    *)
        # 入力が "gku34:tamago324" 形式の場合、それぞれの値を -kb と -km オプションに変換
        if [[ "$key" =~ ^([a-zA-Z0-9_/]+):([a-zA-Z0-9_]+)$ ]]; then
            keyboard="${BASH_REMATCH[1]}"
            keymap="${BASH_REMATCH[2]}"
        else
            # 不明なオプション
            echo "Unknown option: $key"
            usage
        fi
        ;;
    esac
    shift # 次のオプションへ移動
done

# --versionsオプションが指定された場合はタグの一覧を表示
if [ "$list_tags" = "true" ]; then
    echo "Available QMK Firmware versions:"
    cd /workspace/__qmk__ || exit 1
    git tag | grep -E '^[0-9]+\.[1-9][0-9]+\.[0-9]+$' | sort -V
    exit 0
fi

# 必要なオプションが指定されていることを確認
if [ -z "$keyboard" ] || [ -z "$keymap" ]; then
    usage
fi

# QMKのリポジトリへ移動
cd /workspace/__qmk__ || exit 1

# -versionオプションが指定されている場合は指定されたバージョンにチェックアウト
# バージョンが指定されていない場合、最新のタグにチェックアウト
if [ -z "$version" ]; then
    echo "Version not specified. Checking out the latest tag..."
    version=$(git describe --tags $(git rev-list --tags --max-count=1))
fi

echo "Checking out version: $version"
git checkout tags/"$version" || exit 1
qmk git-submodule

# QMKをビルド
if ! qmk compile -j 4 -kb "$keyboard" -km "$keymap"; then
    echo ""
    echo "****************"
    echo "* Build failed *"
    echo "****************"
    echo ""
    exit 1
fi

# $keyboard 内の全ての `/` を `_` に置換
keyboard_sanitized=${keyboard//\//_}
# ビルドが成功した場合は、ファイルをコピー
uf2_filename="${keyboard_sanitized}_$keymap.uf2"
hex_filename="${keyboard_sanitized}_$keymap.hex"

if [ -f "$uf2_filename" ]; then
    cp "$uf2_filename" /workspace/"$uf2_filename" || exit 1
    copy_success="true"
elif [ -f "$hex_filename" ]; then
    cp "$hex_filename" /workspace/"$hex_filename" || exit 1
    copy_success="true"
else
    echo ""
    echo "*************************************"
    echo "* Failed to find the generated file *"
    echo "*************************************"
    echo ""
    exit 1
fi

if [ "$copy_success" = "true" ]; then
    echo ""
    echo "********************"
    echo "* Build successful *"
    echo "********************"
    echo ""
fi
