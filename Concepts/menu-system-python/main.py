from menu import MenuItem, Menu

if __name__ == "__main__":
    menu: Menu = Menu([])
    menu.add_item(MenuItem("Clock"))
    menu.add_item(MenuItem("Settings"))
    menu.add_item(MenuItem("About"))

    for item in menu.items:
        print(item.title)
