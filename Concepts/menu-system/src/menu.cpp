#include "menu.h"

MenuItem::MenuItem(string title, MenuItemType type) : 
    _title(title),
    _is_current(false),
    _is_focused(false),
    _type(type) {
}

MenuItem::MenuItem(string title) : 
    _title(title),
    _is_current(false),
    _is_focused(false),
    _type(MenuItemType::DEFAULT) {
}

string MenuItem::get_title() const {
    return _title;
}

bool MenuItem::is_current() const {
    return _is_current;
}

bool MenuItem::is_focused() const {
    return _is_focused;
}

MenuItemType MenuItem::get_type() const {
    return _type;
}

void MenuItem::set_title(string title) {
    _title = title;
}

void MenuItem::set_current(bool value) {
    _is_current = value;
}

void MenuItem::set_focused(bool value) {
    _is_focused = value;
}
