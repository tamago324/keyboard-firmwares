#!/usr/bin/env python3

import argparse
import os
import re
import shutil
import subprocess
import sys

def usage():
    print("fwbuild vial <options>")
    print("")
    print("Commands:")
    print("  fwbuild vial <keyboard>")
    print("Options:")
    print("  --help  Show this help message and exit")
    sys.exit(1)

def main():
    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument('keyboard', nargs='?', default=None)
    parser.add_argument('--help', action='store_true')

    args = parser.parse_args()

    if args.help:
        usage()

    keyboard = args.keyboard

    if not keyboard or not re.match(r'^[a-zA-Z0-9_/]+$', keyboard):
        print("Unknown option: {}".format(keyboard))
        usage()

    os.chdir('/workspace/__vial__')

    if subprocess.run(['make', f'{keyboard}:vial']).returncode != 0:
        print("")
        print("****************")
        print("* Build failed *")
        print("****************")
        print("")
        sys.exit(1)

    uf2_filename = f"{keyboard}_vial.uf2"

    if os.path.isfile(uf2_filename):
        shutil.copy(uf2_filename, f"/workspace/{uf2_filename}")
        print("")
        print("********************")
        print("* Build successful *")
        print("********************")
        print("")
    else:
        print("")
        print("********************************************************")
        print(f"* Failed to find the generated UF2 file: {uf2_filename} *")
        print("********************************************************")
        print("")
        sys.exit(1)

if __name__ == "__main__":
    main()