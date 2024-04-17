import argparse
import os
import re
import shutil
import subprocess
import sys

TEMP_KEYBOARD_DIR = "fwbuild"
QMK_DIR = "/workspace/__qmk__"
SRC_DIR = "/workspace/keyboards"
DEST_DIR = f"{QMK_DIR}/keyboards/{TEMP_KEYBOARD_DIR}/"


def echo(text: str):
    print("")
    print(f"**{len(text)}**")
    print(f"* {text} *")
    print(f"**{len(text)}**")
    print("")


def usage():
    print("fwbuild qmk <options>")
    print("")
    print("Commands:")
    print("  fwbuild qmk <keyboard>:<keymap> [-v <version>]")
    print("  fwbuild qmk --versions")
    print("  fwbuild qmk --help")
    print("")
    print("Options:")
    print(
        "  -v <version>   Specify the QMK firmware version. If not specified, the latest tag will be used."
    )
    print("  --versions     List available QMK firmware versions")
    print("  --help         Show this help message and exit")
    sys.exit(1)


def list_versions():
    os.chdir(QMK_DIR)
    # git tagコマンドの実行
    git_tag = subprocess.Popen(["git", "tag"], stdout=subprocess.PIPE)

    # grepコマンドでバージョン番号だけをフィルタリング
    grep = subprocess.Popen(
        ["grep", "-E", "^[0-9]+\\.[2-9][0-9]\\.[0-9]+$"],
        stdin=git_tag.stdout,
        stdout=subprocess.PIPE,
    )
    git_tag.stdout.close()

    # sortコマンドでバージョン番号をソート
    sorted = subprocess.Popen(["sort", "-V"], stdin=grep.stdout, stdout=subprocess.PIPE)
    grep.stdout.close()

    # 結果を取得
    output = sorted.communicate()[0].decode("utf-8")

    print(output)
    sys.exit(0)


def build_qmk(keyboard, keymap, version):
    os.chdir(QMK_DIR)

    if not version:
        latest_tag = (
            subprocess.check_output(["git", "rev-list", "--tags", "--max-count=1"])
            .decode()
            .strip()
        )
        version = (
            subprocess.check_output(["git", "describe", "--tags", latest_tag])
            .decode()
            .strip()
        )

    subprocess.run(["git", "checkout", "tags/" + version])
    subprocess.run(["qmk", "git-submodule"])

    if (
        subprocess.run(
            [
                "qmk",
                "compile",
                "-j",
                "4",
                "-kb",
                f"{TEMP_KEYBOARD_DIR}/{keyboard}",
                "-km",
                keymap,
            ]
        ).returncode
        != 0
    ):
        print()
        print("****************")
        print("* Build failed *")
        print("****************")
        print()
        sys.exit(1)

    keyboard_sanitized = keyboard.replace("/", "_")
    uf2_filename = f"{TEMP_KEYBOARD_DIR}_{keyboard_sanitized}_{keymap}.uf2"
    hex_filename = f"{TEMP_KEYBOARD_DIR}_{keyboard_sanitized}_{keymap}.hex"

    if os.path.isfile(uf2_filename):
        shutil.copy(uf2_filename, f"/workspace/{uf2_filename}")
    elif os.path.isfile(hex_filename):
        shutil.copy(hex_filename, f"/workspace/{hex_filename}")
    else:
        print()
        print("*************************************")
        print("* Failed to find the generated file *")
        print("*************************************")
        print()
        sys.exit(1)

    print()
    print("********************")
    print("* Build successful *")
    print("********************")
    print()


def copy_keyboards():
    if not os.path.exists(DEST_DIR):
        os.makedirs(DEST_DIR)

    shutil.copytree(SRC_DIR, DEST_DIR, dirs_exist_ok=True)


def clean_keyboards():
    if os.path.exists(DEST_DIR):
        shutil.rmtree(DEST_DIR)


def exec_make_clean():
    subprocess.run(["make", "distclean"], stdout=subprocess.DEVNULL)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-v", "--version", default="")
    parser.add_argument("--versions", action="store_true")
    parser.add_argument("keyboard_keymap", nargs="?")
    args = parser.parse_args()

    if args.versions:
        list_versions()

    if args.keyboard_keymap:
        match = re.match(r"^([a-zA-Z0-9_/]+):([a-zA-Z0-9_]+)$", args.keyboard_keymap)
        if match:
            keyboard, keymap = match.groups()
            try:
                copy_keyboards()
                build_qmk(keyboard, keymap, args.version)
                exec_make_clean()
            finally:
                clean_keyboards()
        else:
            print("Unknown option: " + args.keyboard_keymap)
            usage()
    else:
        usage()


if __name__ == "__main__":
    main()
