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

# プロンプトを見やすくする
echo 'parse_git_branch() {
     git branch 2> /dev/null | sed -e "/^[^*]/d" -e "s/* \(.*\)/ (\1)/"
}
PS1="\[\e[34m\]\w\[\e[m\]\[\e[32m\]\$(parse_git_branch) \[\e[m\]\$ "' >>$HOME/.bashrc

echo '. /workspace/.devcontainer/bin/_fwbuild_completions' >>$HOME/.bashrc

# 追加しておく
git config --global --add safe.directory /workspace
