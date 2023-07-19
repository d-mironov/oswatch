#include "menu_generic.h"

int main(int argc, char *argv[]) {
    MenuItem<int> mi1{"Data1", 5};
    MenuItem<float> mi2{"Data2", 3.141};
    MenuItem<std::string> mi3{"Data2", "value"};

    MenuItem<int> sub_mi1{"SubData1", 10};
    MenuItem<float> sub_mi2{"SubData2", 1.123};
    MenuItem<std::string> sub_mi3{"SubData2", "sub_value"};

    Menu menu;
    Menu sub_menu;

    MenuItem<Menu*> mi4{"SubMenu", &sub_menu};

    menu.add_item(&mi1);
    menu.add_item(&mi2);
    menu.add_item(&mi3);
    menu.add_item(&mi4);

    sub_menu.add_item(&sub_mi1);
    sub_menu.add_item(&sub_mi2);
    sub_menu.add_item(&sub_mi3);

    menu.render();
    // sub_menu.render();
}
