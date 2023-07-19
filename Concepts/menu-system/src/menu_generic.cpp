#include "menu_generic.h"
#include <iostream>
#include <cstddef>
#include <cstdio>


template<typename T>
MenuItem<T>::MenuItem(string title, T value) : 
    _title(title),
    _is_current(false),
    _is_focused(false),
    _value(value),
    _type(MenuItemType<T>::T) {
}

template<typename T>
string MenuItem<T>::get_title() const {
    return _title;
}

template<typename T>
bool MenuItem<T>::is_current() const {
    return _is_current;
}

template<typename T>
bool MenuItem<T>::is_focused() const {
    return _is_focused;
}

template<typename T>
T MenuItem<T>::get_value() const {
    return _value;
}

template <typename T>
ItemType MenuItem<T>::get_type() const {
    return _type;
}

template<typename T>
void MenuItem<T>::set_title(string title) {
    _title = title;
}

template<typename T>
void MenuItem<T>::set_current(bool value) {
    _is_current = value;
}

template<typename T>
void MenuItem<T>::set_focused(bool value) {
    _is_focused = value;
}

template<typename T>
void MenuItem<T>::set_value(T value) {
    _value = value;
}

template class MenuItem<int>;
template class MenuItem<float>;
template class MenuItem<string>;
template class MenuItem<Menu*>;


Menu::Menu() : next_free_index(0) {
}

void Menu::render() const {
    for (size_t i = 0; i < next_free_index; ++i) {

        /* ====================| Static std::array Version |========================== */ 
        if (items[i].first == ItemType::Int) {
            MenuItem<int> item = *(MenuItem<int>*)items[i].second;
            std::cout << item.get_title() << " := " << item.get_value() << std::endl;
        } else if (items[i].first == ItemType::Float) {
            MenuItem<float> item = *(MenuItem<float>*)items[i].second;
            std::cout << item.get_title() << " := " << item.get_value() << std::endl;
        } else if (items[i].first == ItemType::Default) {
            MenuItem<string> item = *(MenuItem<string>*)items[i].second;
            std::cout << item.get_title() << " := " << item.get_value() << std::endl;
        } else if (items[i].first == ItemType::SubMenu) {
            MenuItem<Menu*> item = *(MenuItem<Menu*>*)items[i].second;
            Menu menu = *item.get_value();
            std::cout << item.get_title() << " := " << item.get_value() << std::endl;
        }

        /* ====================| Dynamic std::vector Version |========================== */ 
        // if (items[i].first == typeid(MenuItem<int>)) {
        //     MenuItem<int> item = *(MenuItem<int>*)items[i].second;
        //     std::cout << item.get_title() << " := " << item.get_value() << std::endl;
        // } else if (items[i].first == typeid(MenuItem<float>)) {
        //     MenuItem<float> item = *(MenuItem<float>*)items[i].second;
        //     std::cout << item.get_title() << " := " << item.get_value() << std::endl;
        // } else if (items[i].first == typeid(MenuItem<string>)) {
        //     MenuItem<string> item = *(MenuItem<string>*)items[i].second;
        //     std::cout << item.get_title() << " := " << item.get_value() << std::endl;
        // }
    }
}
