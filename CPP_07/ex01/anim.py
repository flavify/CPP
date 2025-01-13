#!/usr/bin/env python3
import time
import sys

colors = [
    "\033[38;5;201m",
    "\033[38;5;165m",
    "\033[38;5;93m",
    "\033[38;5;57m",
    "\033[38;5;63m",
    "\033[38;5;27m"
]

RESET = "\033[0m"

ascii_art = [
" _____                    _       _            ",
"|_   _|__ _ __ ___  _ __ | | __ _| |_ ___  ___ ",
"  | |/ _ \\ '_ ` _ \\| '_ \\| |/ _` | __/ _ \\/ __|",
"  | |  __/ | | | | | |_) | | (_| | ||  __/\\__ \\",
"  |_|\\___|_| |_| |_| .__/|_|\\__,_|\\__\\___||___/",
"                   |_|                         "
]

for i, line in enumerate(ascii_art):
    color = colors[i % len(colors)]
    sys.stdout.write(color + line + RESET + "\n")
    sys.stdout.flush()
    time.sleep(0.1)

print()
