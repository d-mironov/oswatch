#ifndef MENU_GENERIC_H
#define MENU_GENERIC_H

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
};

class Menu {
public:
    Menu() = default;
    template<class T>
    void add_item(const T* value) {
        items.push_back(pair<const type_info&, void*>(
            typeid(T), (void*)value
            )
        );
    }

    void render() const;
private:
    vector<pair<const type_info&, void*>> items;
};



#endif /* ifndef MENU_GENERIC_H */
