#ifndef MENU_VOID_PTR
#define MENU_VOID_PTR

#include <string>

using std::string;

class MenuItem {
public:
    MenuItem() = default;
    MenuItem(string title, void* data = nullptr);
    // Getter
    string get_title() const;
    bool is_current() const;
    bool is_focused() const;
    // Setter
    void set_title(string title);
    void set_current(bool value);
    void set_focused(bool value);
    void* get_value() const;
    void set_value(void* data);
private:
    string _title;
    bool _is_current;
    bool _is_focused;
    void* _data;
};
#endif /* ifndef MENU_VOID_PTR */
