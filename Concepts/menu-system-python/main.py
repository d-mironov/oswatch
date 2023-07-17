from menu import MenuItem, Menu

if __name__ == "__main__":
    menu: Menu = Menu([])
    menu.add_item(MenuItem("Clock"))
    menu.add_item(MenuItem("Settings"))
    menu.add_item(MenuItem("About"))
    for i in range(3):
        menu.render()
        menu.next()
    for i in range(3):
        menu.render()
        menu.prev()

