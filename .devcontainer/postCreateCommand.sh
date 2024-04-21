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

# ビルドのスクリプトを実行できるようにする
FWBUILD_SH="/workspace/.devcontainer/bin/fwbuild.sh"
chmod +x $FWBUILD_SH
if [ ! -e "/usr/local/bin/fwbuild" ]; then
    ln -s $FWBUILD_SH /usr/local/bin/fwbuild
fi

# Load .devcontainer/_bashrc
if [ -f "/workspace/.devcontainer/_bashrc" ]; then
    echo 'source "/workspace/.devcontainer/_bashrc"' >> $HOME/.bashrc
fi