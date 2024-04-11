#!/bin/bash

cd /workspace

# qmk
if [ ! -d "__qmk__" ]; then
    git clone --recursive https://github.com/qmk/qmk_firmware __qmk__
    qmk setup --home __qmk__ --yes
    qmk git-submodule
fi

# vial
if [ ! -d "__vial__" ]; then
    git clone --recursive https://github.com/vial-kb/vial-qmk __vial__
    cd __vial__
    make git-submodule
fi

# link keybaords files
QMK_KEYBOARDS_DIR="/workspace/__qmk__/keyboards"
VIAL_KEYBOARDS_DIR="/workspace/__vial__/keyboards"

# keyboards/* ディレクトリのシンボリックリンクを作成する
for dir in /workspace/keyboards/*/; do
    link_name=$(basename "${dir%/}")

    # 存在しない場合のみ、作成する
    if [ ! -e "$QMK_KEYBOARDS_DIR/$link_name" ]; then
        ln -s "$dir" "$QMK_KEYBOARDS_DIR/$link_name"
    fi
    if [ ! -e "$VIAL_KEYBOARDS_DIR/$link_name" ]; then
        ln -s "$dir" "$VIAL_KEYBOARDS_DIR/$link_name"
    fi
done

# ビルドのスクリプトを実行できるようにする
chmod +x /workspace/bin/build_qmk.sh
ln -s $_ /usr/local/bin/build_qmk

chmod +x /workspace/bin/build_vial.sh
ln -s $_ /usr/local/bin/build_vial
