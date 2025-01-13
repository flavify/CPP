import os
import time
import sys

# Colors
BLUE    = "\033[1;34m"
GREEN   = "\033[1;38;2;30;130;30m"
GRASS   = "\033[1;38;2;124;252;0m"
PURPLE  = "\033[1;38;2;128;0;128m"
PINK    = "\033[1;38;2;255;182;193m"
RESET   = "\033[0m"

frames = [
    f"""

    *
                                                  {PURPLE}@{RESET} 
                                     {GREEN},--          {GRASS}|/{RESET}
                                    {GREEN}(__ \__    {PINK}@  {GRASS}|{RESET}
                                      {GREEN}_\  \\\_   {GRASS}\_|{RESET}
    {BLUE}~~~~ ~~ ~~~~~~ ~~  ~~~~~~~ ~~ ~~~{GRASS}_{GREEN}\,___\/{GRASS}--'-\#{RESET}
    """,
    f"""

                            
        *                                         {PURPLE}@{RESET}
                                     {GREEN},--          {GRASS}|/{RESET}
                                    {GREEN}(__ \__    {PINK}@  {GRASS}|{RESET}
                                      {GREEN}_\  \\\_   {GRASS}\_|{RESET}
    {BLUE}~~~~ ~~ ~~~~~~ ~~  ~~~~~~~ ~~ ~~~{GRASS}_{GREEN}\,___\/{GRASS}--'-\#{RESET}
    """,
    f"""

            *                 
                                                  {PURPLE}@{RESET}
                                     {GREEN},--          {GRASS}|/{RESET}
                                    {GREEN}(__ \__    {PINK}@  {GRASS}|{RESET}
                                      {GREEN}_\  \\\_   {GRASS}\_|{RESET}
    {BLUE}~~~~ ~~ ~~~~~~ ~~  ~~~~~~~ ~~ ~~~{GRASS}_{GREEN}\,___\/{GRASS}--'-\#{RESET}
    """,
    f"""

                            
                *                                 {PURPLE}@{RESET}
                                     {GREEN},--          {GRASS}|/{RESET}
                                    {GREEN}(__ \__    {PINK}@  {GRASS}|{RESET}
                                      {GREEN}_\  \\\_   {GRASS}\_|{RESET}
    {BLUE}~~~~ ~~ ~~~~~~ ~~  ~~~~~~~ ~~ ~~~{GRASS}_{GREEN}\,___\/{GRASS}--'-\#{RESET}
    """,
    f"""

                            
                                                  {PURPLE}@{RESET}
                    *                {GREEN},--          {GRASS}|/{RESET}
                                    {GREEN}(__ \__    {PINK}@  {GRASS}|{RESET}
                                      {GREEN}_\  \\\_   {GRASS}\_|{RESET}
    {BLUE}~~~~ ~~ ~~~~~~ ~~  ~~~~~~~ ~~ ~~~{GRASS}_{GREEN}\,___\/{GRASS}--'-\#{RESET}
    """,
    f"""

                            
                                                  {PURPLE}@{RESET}
                          *           oo          {GRASS}|/{RESET}
                                    {GREEN}(__ \__    {PINK}@  {GRASS}|{RESET}
                                      {GREEN}_\  \\\_   {GRASS}\_|{RESET}
    {BLUE}~~~~ ~~ ~~~~~~ ~~  ~~~~~~~ ~~ ~~~{GRASS}_{GREEN}\,___\/{GRASS}--'-\#{RESET}
    """,
    f"""

                            
                            *                     {PURPLE}@{RESET}
                                      OO          {GRASS}|/{RESET}
                                    {GREEN}(__ \__    {PINK}@  {GRASS}|{RESET}
                                      {GREEN}_\  \\\_   {GRASS}\_|{RESET}
    {BLUE}~~~~ ~~ ~~~~~~ ~~  ~~~~~~~ ~~ ~~~{GRASS}_{GREEN}\,___\/{GRASS}--'-\#{RESET}
    """,
    f"""

                              *.
                                `.                {PURPLE}@{RESET}
                                    {GREEN}_/{RESET}^^          {GRASS}|/{RESET}
                                    {GREEN}\__ \__    {PINK}@  {GRASS}|{RESET}
                                      {GREEN}_\  \\\_   {GRASS}\_|{RESET}
    {BLUE}~~~~ ~~ ~~~~~~ ~~  ~~~~~~~ ~~ ~~~{GRASS}_{GREEN}\,___\/{GRASS}--'-\#{RESET}
    """,
    f"""

                                
                                                  {PURPLE}@{RESET}
                                    {GREEN} ,{RESET}^^          {GRASS}|/{RESET}
                                    {GREEN}(__ \__    {PINK}@  {GRASS}|{RESET}
                                      {GREEN}_\  \\\_   {GRASS}\_|{RESET}
    {BLUE}~~~~ ~~ ~~~~~~ ~~  ~~~~~~~ ~~ ~~~{GRASS}_{GREEN}\,___\/{GRASS}--'-\#{RESET}
    """
]

def clear():
  os.system('clear')

def animate():
  stop_file = "stop_animation.txt" 
  animation_cycles = 1
  try:
    while not os.path.exists(stop_file):
      for _ in range (animation_cycles):  
        for frame in frames:
          if os.path.exists(stop_file):
              break
          clear()
          print(frame)
          time.sleep(0.4)
  finally:
    if os.path.exists(stop_file):
      os.remove(stop_file)
    clear()
    print(f"""

                                     Build complete!
                                         /        {PURPLE}@{RESET}
                                     {GREEN},--          {GRASS}|/{RESET}
                                    {GREEN}(__ \__    {PINK}@  {GRASS}|{RESET}
                                      {GREEN}_\  \\\_   {GRASS}\_|{RESET}
    {BLUE}~~~~ ~~ ~~~~~~ ~~  ~~~~~~~ ~~ ~~~{GRASS}_{GREEN}\,___\/{GRASS}--'-\#{RESET}
    """)
    sys.exit()

if __name__ == "__main__":
  animate()
