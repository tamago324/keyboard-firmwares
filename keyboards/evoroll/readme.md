
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
$ fwbuild qmk compile evoroll:tamago324 -v 0.26.0
```

## ファームウェアの書き込み

1. 以下のいずれかで書き込みモードにする
   1. RP2040-Zero の左側のボタンを押した状態で USB を接続する
   2. USBで接続した状態で RP2040-Zero の右側のボタンを2回押す
   3. 左上のキーを押した状態で USB を接続する (1度、ファームウェアを書き込んでおく必要がある)
2. ファイルエクスプローラに表示されたドライブに、作成したファームウェア (`fwbuild_evoroll_tamago324.uf2`) をコピー (コピーが完了した時点でデバイスとの接続が切断される)
3. 書き込んだファームウェアの入力になっていれば書き込み成功

## 参考

* https://github.com/Yowkees/keyball/tree/main/qmk_firmware/keyboards/keyball
* https://github.com/aki27kbd/vial-qmk/tree/vial/keyboards/aki27/cocot36plus