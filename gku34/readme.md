# gku34

![gku34](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [tamago324](https://github.com/tamago324)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make gku34:default

Flashing example for this keyboard:

    make gku34:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available

## ファームウェアの作成

### nix-shell

```
nix-shell --run 'sudo make tamago324/gku34/rev01:tamago324'
```

### [gpk_fwmaker](https://github.com/darakuneko/gpk_fwmaker)

`keyboards\tamago324\gku34` を `C:\Users\xxxx\GPKFW\gku34` のように配置し、以下のコマンドを実行

Windows の場合

```
# qmk
curl -X POST -H "Content-Type: application/json" -d "{\"kb\": \"gku34/rev01\", \"km\": \"tamago324\", \"tag\": \"0.21.5\"}" 127.0.0.1:3123/build/qmk

# vial の場合
curl -X POST -H "Content-Type: application/json" -d "{\"kb\": \"gku34/rev01\", \"km\": \"vial\"}" 127.0.0.1:3123/build/vial
```

## ファームウェアの書き込み

1. RP2040-Zero の 左のボタンを押しながら、USB を接続
2. ファイルエクスプローラに表示されたドライブに、作成したファームウェア (`gku34_rev01_xxxxx.uf2`) をコピー (コピーが完了した時点でデバイスとの接続が切断される)
3. 書き込んだファームウェアの入力になっていれば書き込み成功
