#ifndef MENU_GENERIC_H
#define MENU_GENERIC_H

#include <cstddef>
#include <string>
#include <array>
#include <vector>
#include <utility>
#include <typeinfo>

using std::string;
using std::array;
using std::vector;
using std::pair;
using std::type_info;

class Menu;


template <typename T>
struct MenuItemType;

enum ItemType {
    Default,
    Int,
    Float,
    Bool,
    SubMenu
};

template <typename T>
class MenuItem {
public:
    MenuItem() = default;
    MenuItem(string title, T value = T{});
    // Getter
    string get_title() const;
    bool is_current() const;
    bool is_focused() const;
    T get_value() const;
    ItemType get_type() const;
    // Setter
    void set_title(string title);
    void set_current(bool value);
    void set_focused(bool value);
    void set_value(T value);
private:
    string _title;
    bool _is_current;
    bool _is_focused;
    T _value;
    ItemType _type;
};


template <>
struct MenuItemType<int> {
    static const ItemType T = ItemType::Int;
};

template <>
struct MenuItemType<float> {
    static const ItemType T = ItemType::Float;
};

template <>
struct MenuItemType<string> {
    static const ItemType T = ItemType::Default;
};

template <>
struct MenuItemType<Menu*> {
    static const ItemType T = ItemType::SubMenu;
};

template <>
struct MenuItemType<bool> {
    static const ItemType T = ItemType::Bool;
};


class Menu {
public:
    // Menu() = default;
    Menu();

    /* ==============| Dynamic std::vector Version |============== */
    // template<class T>
    // void add_item(const T* value) {
    //     items.push_back(pair<const type_info&, void*>(
    //         *value.get_type(), (void*)value
    //         )
    //     );
    // }


    /* ==============| Static std::array Version |============== */
    template <class T>
    void add_item(const T* value) {
        items[next_free_index].first = value->get_type();
        items[next_free_index].second = (void*) value;
        next_free_index++;
    }

    void render() const;
private:
    // vector<pair<const type_info&, void*>> items;
    array<pair<ItemType, void*>, 32> items;
    size_t next_free_index;
};



#endif /* ifndef MENU_GENERIC_H */
