#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include <string>

using std::string;

enum MenuItemType {
    DEFAULT,
    BOOL,
    INTEGER,
    FLOAT,
    MENU,
};

class MenuItem {
public:
    MenuItem() = default;
    MenuItem(string title, MenuItemType type = MenuItemType::DEFAULT);
    MenuItem(string title);
    // Getter
    string get_title() const;
    bool is_current() const;
    bool is_focused() const;
    MenuItemType get_type() const;
    // Setter
    void set_title(string title);
    void set_current(bool value);
    void set_focused(bool value);
private:
    string _title;
    bool _is_current;
    bool _is_focused;
    MenuItemType _type;
};

class BoolMenuItem : public MenuItem {
public:
    BoolMenuItem() = default;
    bool get_value() const;
    void set_value(bool value);
private:
    bool _value;
};

class IntegerMenuItem : public MenuItem {
public:
    IntegerMenuItem() = default;
    int get_value() const;
    void set_value(int value);
private:
    int _value;
};

class FloatMenuItem : public MenuItem {
public:
    FloatMenuItem() = default;
    float get_value() const;
    void set_value(float value);
private:
    float _value;
};

class AppMenuItem : public MenuItem {
    // TODO: Add callback function pointer
};


class SubMenuItem : public MenuItem {

};

class Menu {

};

/**
 * Object to manage the current menu and navigation
 */
class MenuManager {

};

#endif
