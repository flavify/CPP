import os
import time
import sys

# Colors
BLUE    = "\033[1;38;2;0;25;102m"
RESET   = "\033[0m"

frames = [
    f"""

                                                                      
                                ________     |"\/"|
                              ,'        `.    \  /
                              |  -        \___/  |
    {BLUE}~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~{RESET}
    """,
    f"""


                        ___{BLUE}:{RESET}____     |"\/"|
                      ,'        `.    \  /
                      |  <        \___/  |
    {BLUE}~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~{RESET}
    """,
    f"""
          
                  "{BLUE}:{RESET}"
                ___{BLUE}:{RESET}____     |"\/"|
              ,'        `.    \  /
              |  O        \___/  |
    {BLUE}~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~{RESET}
    """,
    f"""
          {BLUE}:::{RESET}     
          "{BLUE}:{RESET}"
        ___{BLUE}:{RESET}____     |"\/"|
      ,'        `.    \  /
      |  ^        \___/  |
    {BLUE}~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~{RESET}
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
          time.sleep(0.6)
  finally:
    if os.path.exists(stop_file):
      os.remove(stop_file)
    clear()
    print(f"""
          {BLUE}.:.{RESET}
          "{BLUE}:{RESET}"
        ___{BLUE}:{RESET}____     |"\/"|
      ,'        `.    \  /
      |  ^        \___/  |
    {BLUE}~^~^~^~^~^~Build complete!^~^~^~^~^~^~^~^~^~{RESET}
    """)
    sys.exit()

if __name__ == "__main__":
  animate()
