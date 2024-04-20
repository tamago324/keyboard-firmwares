# Build QMK Firmware / Vial using Dev Container

## Quick Start

このリポジトリを clone する

```sh
$ git clone https://github.com/tamago324/keyboard-firmwares
```

clone したら、VSCode で開き、 (`Dev Containers` 拡張機能を入れておく)  
Dev Container で開く (`コンテナで再度開く`のメッセージが表示されたら、クリックして開ける)  

初回のセットアップが行われ、`__qmk__` と `__vial__` が作成されたらセットアップ完了


ビルドするには

```sh
$ fwbuild qmk <keyboard>:<keymap> [-v <version>]
$ fwbuild vial <keyboard>
```

のように実行する


次回以降は Dev Container で開くことですぐに `fwbuild` コマンドでビルド可能  
また、環境を作り直したい場合、`__qmk__/` と `__vial__/` を削除し、`開発コンテナー: コンテナでリビルドして再度開く` コマンドを実行する

## Create keyboard firmware

`keyboards/` ディレクトリ配下に QMK Firmware の keyboards と同じように作成する  


## Usage

### fwbuild

```sh
fwbuild <command> [options]

Commands:
  fwbuild qmk     Build QMK firmware with specified options
  fwbuild vial    Build Vial firmware with specified options

Options:
  fwbuild <command> --help  Show <command> help message
```

### fwbuild qmk

```sh
fwbuild qmk <options>

Commands:
  fwbuild qmk <keyboard>:<keymap> [-v <version>]
  fwbuild qmk --versions
  fwbuild qmk --help

Options:
  -v <version>   Specify the QMK firmware version. If not specified, the latest tag will be used.
  --versions     List available QMK firmware versions
  --help         Show this help message and exit
```

### fwbuild vial

```sh
fwbuild vial <options>

Commands:
  fwbuild vial <keyboard>

Options:
  --help  Show this help message and exit
```


## Special Thanks

* [GPK FWMaker](https://github.com/darakuneko/gpk_fwmaker)
* [Keyball GitHub Actions](https://github.com/Yowkees/keyball/pull/547/files#diff-002f0cf6de5b59906143def2851a94115b1ce39b58995b2ce87ec84efc63d3c2)
