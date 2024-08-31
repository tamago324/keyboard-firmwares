# trackmacro

## VSCode の設定

compile_commands.json の作成

```sh
$ fwbuild qmk generate-compilation-database trackmacro:default
```


## ファームウェアの作成

DevContainer の環境で作成する

```sh
# QMK
$ fwbuild qmk trackmacro:default
```
