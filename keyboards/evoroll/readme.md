
# evoroll

左側は haqua34、右側は evoroll

## VSCode の設定

compile_commands.json の作成

```sh
$ fwbuild qmk generate-compilation-database evoroll:tamago324
```

## ファームウェアの作成

DevContainer の環境で作成する

```sh
# QMK
$ fwbuild qmk compile evoroll:tamago324
```

## 参考

* https://github.com/Yowkees/keyball/tree/main/qmk_firmware/keyboards/keyball
* https://github.com/aki27kbd/vial-qmk/tree/vial/keyboards/aki27/cocot36plus