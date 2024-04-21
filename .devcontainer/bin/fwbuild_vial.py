#!/usr/bin/env python3

import argparse
import os
import re
import shutil
import subprocess
import sys


TEMP_KEYBOARD_DIR = "fwbuild"
VIAL_DIR = "/workspace/__vial__"
SRC_DIR = "/workspace/keyboards"
DEST_DIR = f"{VIAL_DIR}/keyboards/{TEMP_KEYBOARD_DIR}/"


def echo(text: str):
    print("")
    print(f"**{'*' * len(text)}**")
    print(f"* {text} *")
    print(f"**{'*' * len(text)}**")
    print("")


def usage():
    print("fwbuild vial <options>")
    print("")
    print("Commands:")
    print("  fwbuild vial <keyboard>")
    print("")
    print("Options:")
    print("  --help  Show this help message and exit")
    sys.exit(1)


def build_vial(keyboard: str):
    os.chdir(VIAL_DIR)

    if subprocess.run(["make", f"{TEMP_KEYBOARD_DIR}/{keyboard}:vial"]).returncode != 0:
        echo("Build failed")
        sys.exit(1)

    uf2_filename = f"{TEMP_KEYBOARD_DIR}_{keyboard}_vial.uf2"

    if os.path.isfile(uf2_filename):
        shutil.copy(uf2_filename, f"/workspace/{uf2_filename}")
        echo("Build successful")
    else:
        echo(f"Failed to find the generated UF2 file: {uf2_filename}")
        sys.exit(1)


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
    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument("keyboard", nargs="?", default=None)
    parser.add_argument("--help", action="store_true")

    args = parser.parse_args()
    keyboard = args.keyboard

    if not keyboard or args.help:
        usage()

    if not keyboard or not re.match(r"^[a-zA-Z0-9_/]+$", keyboard):
        print("Unknown option: {}".format(keyboard))
        usage()

    try:
        copy_keyboards()
        build_vial(keyboard)
        exec_make_clean()
    finally:
        clean_keyboards()


if __name__ == "__main__":
    main()
