
# devcontainer を使用してコンパイルできる環境

## setup

```sh
$ fwbuild setup
```

## コンパイル

```sh
$ fwbuild qmk <keyboard>:<keymap> [-v <version>]
$ fwbuild vial <keyboard>
```

## Usage

### fwbuild

```sh
fwbuild <command> [options]

Commands:
  setup   Setup the environment
  qmk     Build QMK firmware with specified options
  vial    Build Vial firmware with specified options
  upadte  Update QMK and Vial repository

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
