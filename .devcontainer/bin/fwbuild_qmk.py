import argparse
import os
import re
import shutil
import subprocess
import sys

def usage():
    print("fwbuild qmk <options>")
    print("")
    print("Commands:")
    print("  fwbuild qmk <keyboard>:<keymap> [-v <version>]")
    print("  fwbuild qmk --versions")
    print("  fwbuild qmk --help")
    print("")
    print("Options:")
    print("  -v <version>   Specify the QMK firmware version. If not specified, the latest tag will be used.")
    print("  --versions     List available QMK firmware versions")
    print("  --help         Show this help message and exit")
    sys.exit(1)

def list_versions():
    os.chdir('/workspace/__qmk__')
    subprocess.run(['git', 'tag', '|', 'grep', '-E', "'^[0-9]+\\.[1-9][0-9]+\\.[0-9]+$'", '|', 'sort', '-V'])
    sys.exit(0)

def build_qmk(keyboard, keymap, version):
    os.chdir('/workspace/__qmk__')

    if not version:
        latest_tag = subprocess.check_output(['git', 'rev-list', '--tags', '--max-count=1']).decode().strip()
        version = subprocess.check_output(['git', 'describe', '--tags', latest_tag]).decode().strip()

    subprocess.run(['git', 'checkout', 'tags/' + version])
    subprocess.run(['qmk', 'git-submodule'])

    if subprocess.run(['qmk', 'compile', '-j', '4', '-kb', keyboard, '-km', keymap]).returncode != 0:
        print()
        print("****************")
        print("* Build failed *")
        print("****************")
        print()
        sys.exit(1)

    keyboard_sanitized = keyboard.replace('/', '_')
    uf2_filename = f"{keyboard_sanitized}_{keymap}.uf2"
    hex_filename = f"{keyboard_sanitized}_{keymap}.hex"

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

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-v', '--version', default="")
    parser.add_argument('--versions', action='store_true')
    parser.add_argument('keyboard_keymap', nargs='?')
    args = parser.parse_args()

    if args.versions:
        list_versions()

    if args.keyboard_keymap:
        match = re.match(r'^([a-zA-Z0-9_/]+):([a-zA-Z0-9_]+)$', args.keyboard_keymap)
        if match:
            keyboard, keymap = match.groups()
            build_qmk(keyboard, keymap, args.version)
        else:
            print("Unknown option: " + args.keyboard_keymap)
            usage()
    else:
        usage()

if __name__ == "__main__":
    main()