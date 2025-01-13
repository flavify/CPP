import os
import time
import sys

# Colors
PINK    = "\033[38;2;255;182;193m"
B_PINK  = "\033[1;38;2;255;182;193m"
RESET   = "\033[0m"

frames = [
    f"""
     {PINK}(\(\\
     ( -.-)
     o_(")("){RESET}
    """,
    f"""
     {PINK}(\(\\
     ( o.o)
     o_(")("){RESET}
    """,
    f"""
     {PINK}(\(\\
     ( >.<)
     o_(")("){RESET}
    """
]

def clear():
  os.system('clear')

def animate():
  stop_file = "stop_animation.txt" 
  animation_cycles = 4
  try:
    while not os.path.exists(stop_file):
      for _ in range (animation_cycles):  
        for frame in frames:
          if os.path.exists(stop_file):
              break
          clear()
          print(frame)
          time.sleep(0.3)
  finally:
    if os.path.exists(stop_file):
      os.remove(stop_file)
    clear()
    print(f"""
    {PINK}(\(\ 
    ( ^_^)
    o_(")("){B_PINK}✨Build Complete!✨{RESET}
    """)
    sys.exit()

if __name__ == "__main__":
  animate()
