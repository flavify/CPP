import os
import time
import sys

# Colors
GRAY    = "\033[38;2;128;128;128m"
YELLOW  = "\033[38;2;255;255;0m"
RESET   = "\033[0m"


frames = [
    f"""
     {GRAY}    |\\__/,|     (`\\{RESET}
     {GRAY}  _.| - - |  _   ) )-{RESET}
     {GRAY}-(((---(((--------{RESET}
    """,
    f"""
     {GRAY}    |\\__/,|     (`\\{RESET}
     {GRAY}  _.| - - |  _   ) )-{RESET}
     {YELLOW}--(((---(((--------{RESET}
    """,
    f"""
     {GRAY}    |\\__/,|     (`\\{RESET}
     {YELLOW}  _.| o o |  _   ) )-{RESET}
     {YELLOW}--(((---(((--------{RESET}
    """,
    f"""
     {YELLOW}    |\\__/,|     (`\\{RESET}
     {YELLOW}  _.| o o |  _   ) )-{RESET}
     {YELLOW}--(((---(((--------{RESET}
    """,
    f"""
     {YELLOW}    |\\__/,|     (`\\{RESET}
     {YELLOW}  _.| O O |  _   ) )-{RESET}
     {YELLOW}--(((---(((--------{RESET}
    """,
    f"""
     {YELLOW}    |\\__/,|     (`\\{RESET}
     {YELLOW}  _.| @ @ |  _   ) )-{RESET}
     {YELLOW}--(((---(((--------{RESET}
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
     {YELLOW}    |\\__/,|     (`\\{RESET}
     {YELLOW}  _.| @ @ |  _   ) )-{RESET}{YELLOW}🌟Build complete!🌟{RESET}
     {YELLOW}--(((---(((--------{RESET}
    """)
    sys.exit()

if __name__ == "__main__":
  animate()
