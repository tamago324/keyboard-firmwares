# Build QMK Firmware / Vial using Dev Container

## Setup

* clone する
  ```sh
  $ git clone https://github.com/tamago324/keyboard-firmwares
  ```
* VSCode で開く
  * `Dev Containers` 拡張機能を入れておく
* Dev Container で開く (`コンテナで再度開く`のメッセージが表示されたら、クリックして開ける)
  * 初回のセットアップが行われる (`__qmk__`, `__vial__` が作成される)
    * 完了したら、利用可能
* 次回以降は Dev Container で開くことですぐに `fwbuild` コマンドでビルド可能
* もし、環境を作り直したい場合、`__qmk__/` と `__vial__/` を削除し、`開発コンテナー: コンテナでリビルドして再度開く` コマンドを実行する


## Quick Start

Compile

```sh
$ fwbuild qmk <keyboard>:<keymap> [-v <version>]
$ fwbuild vial <keyboard>
```

## Usage

### fwbuild

```sh
fwbuild <command> [options]

Commands:
  qmk     Build QMK firmware with specified options
  vial    Build Vial firmware with specified options

Options:
  fwbuild <command> --help
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
