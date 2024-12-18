#!/usr/bin/env python3
import sys
import time
import os

RESET = "\033[0m"
YELLOW = "\033[38;5;226m"
GRAY = "\033[38;5;240m"
BLUE = "\033[38;5;75m"
MAGENTA = "\033[38;5;201m"
SPARK = "\033[38;5;220m"

hammer_up = f"     {YELLOW}🔨{RESET}"
hammer_down = f"       {YELLOW}🔨{RESET}"

spark_frames = [
    f"{SPARK}*{RESET}",
    f"{SPARK} *{RESET}",
    f"{SPARK}  *{RESET}",
    f"{SPARK} *{RESET}",
    f"{SPARK}*{RESET}",
]

building_progress = [
    f"{GRAY}[{RESET}{' ' * 8}{GRAY}]{RESET}",
    f"{GRAY}[{RESET}{BLUE}##{RESET}{' ' * 6}{GRAY}]{RESET}",
    f"{GRAY}[{RESET}{BLUE}####{RESET}{' ' * 4}{GRAY}]{RESET}",
    f"{GRAY}[{RESET}{BLUE}######{RESET}{' ' * 2}{GRAY}]{RESET}",
    f"{GRAY}[{RESET}{BLUE}########{RESET}{GRAY}]{RESET}",
]

def clear_terminal():
    os.system('cls' if os.name == 'nt' else 'clear')

def hammer_build_animation():
    for i in range(len(building_progress)):
        for _ in range(3):
            clear_terminal()
            print(hammer_up)
            print(f"{building_progress[i]}")
            time.sleep(0.2)

            clear_terminal()

            print(hammer_down)
            print(f"{building_progress[i]} {spark_frames[_ % len(spark_frames)]}")
            time.sleep(0.2)
            
        clear_terminal()
        print(f"{building_progress[i]}")
        time.sleep(0.5)

    clear_terminal()
    print(f"{MAGENTA}✨BUILD COMPLETE!✨{RESET}".center(40))
    print(f"{BLUE}[########]{RESET}".center(40))

if __name__ == "__main__":
    hammer_build_animation()
