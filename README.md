
# devcontainer を使用してコンパイルできる環境

## コンパイル

```sh
$ build_qmk -kb <keyboard> -km <keymap> [-version <version>]
$ build_vial -kb <keyboard>
```

## 環境をリセットしたいとき

環境をリセットしたい場合は、`__qmk__` と `__vial__` を削除して、`コンテナのリビルド` を実行する

## 懸念点

* `__qmk__` と `__vial__` のディレクトリがホスト側にも配置されてしまう
* VSCode のGit管理で `__qmk__` 配下が表示されてしまう (コマンドで git status では除外されているため、VSCode 側の問題？)