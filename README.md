
# devcontainer を使用してコンパイルできる環境

## コンパイル

```sh
$ build qmk -kb <keyboard> -km <keymap> [-version <version>]
$ build vial -kb <keyboard>
```

## 環境をリセットしたいとき

環境をリセットしたい場合は、`__qmk__` と `__vial__` を削除して、`コンテナのリビルド` を実行する

## 懸念点

* `__qmk__` と `__vial__` のディレクトリがホスト側にも配置されてしまう