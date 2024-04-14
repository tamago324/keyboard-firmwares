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
chmod +x /workspace/.devcontainer/bin/build.sh
if [ ! -e "/usr/local/bin/build" ]; then
    ln -s /workspace/.devcontainer/bin/build.sh /usr/local/bin/build
fi

# プロンプトを見やすくする
echo 'PS1="\[\e[34m\]\w\[\e[m\]\$ "' >>$HOME/.bashrc

echo '. /workspace/.devcontainer/bin/_build_completions' >>$HOME/.bashrc

# 追加しておく
git config --global --add safe.directory /workspace
