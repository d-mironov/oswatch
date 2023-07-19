#include "menu_generic.h"

int main(int argc, char *argv[]) {
    MenuItem<int> mi1{"Data1", 5};
    MenuItem<float> mi2{"Data2", 3.141};
    MenuItem<std::string> mi3{"Data2", "value"};


    Menu menu;

    menu.add_item(&mi1);
    // menu.add_item(&mi2);
    // menu.add_item(&mi3);

    // menu.render();
}
