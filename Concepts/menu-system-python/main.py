from menu import MenuItem, Menu
from rich import print
import curses as tui
from curses import wrapper

if __name__ == "__main__":
    menu: Menu = Menu([])
    menu.add_item(MenuItem("Clock"))
    menu.add_item(MenuItem("Settings"))
    menu.add_item(MenuItem("About"))

def main(screen):
    screen.clear()
    screen.keypad(True)
    c = 0
    while True: 
        if c == ord('q'):
            break
        elif c == tui.KEY_DOWN:
            menu.next()
        elif c == tui.KEY_UP:
            menu.prev()

        items = menu.get_items()
        # screen.addstr("Hello world")
        for idx, item in enumerate(items):
            if item.is_current():
                screen.addstr(idx, 0, item.get_title(), tui.A_REVERSE)
            else:
                screen.addstr(idx, 0, item.get_title()) 

        screen.refresh()
        c = screen.getch()

wrapper(main)

