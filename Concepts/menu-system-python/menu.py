from dataclasses import dataclass, field
from typing import Callable


class MenuEmptyException(Exception):
    pass

@dataclass
class MenuItem:
    _title: str = field(default="")
    _callback: Callable = field(default=None)
    _is_current: bool = field(default=False)
    _is_focused: bool = field(default=False)

    def get_title(self) -> str:
        return self._title

    def set_title(self, new_title: str) -> None:
        self._title = new_title

    def is_current(self) -> bool:
        return self._is_current

    def set_current(self, value: bool) -> None:
        self._is_current = value

    def is_focused(self) -> bool:
        return self._is_focused

    def set_focused(self, value: bool) -> None:
        self._is_focused = value



@dataclass
class BoolMenuItem(MenuItem):
    _value: bool = field(default=False)

    def get_value(self) -> bool:
        return self._value

    def set_value(self, value: bool) -> None:
        self._value = value


@dataclass
class AppMenuItem(MenuItem):
    def execute(self) -> None:
        self._callback()


@dataclass
class Menu:
    _items: list[MenuItem] = field(default_factory=lambda: [])
    _current_item: int = field(default=0)

    def add_item(self, item: MenuItem) -> None:
        self._items.append(item)
        if len(self._items) == 1:
            self._items[self._current_item].set_current(True)

    def next(self) -> None:
        self.current_item().set_current(False)
        self._current_item = (self._current_item + 1) % len(self._items)
        self.current_item().set_current(True)

    def prev(self) -> None:
        self.current_item().set_current(False)
        length = len(self._items)
        self._current_item = (((self._current_item - 1) % length) + length) % length
        self.current_item().set_current(True)

    def get_items(self) -> list[MenuItem]:
        return self._items

    def current_item_index(self) -> int:
        return self._current_item

    def current_item(self) -> MenuItem:
        if len(self._items) == 0:
            raise MenuEmptyException
        return self._items[self._current_item]

    def render(self) -> str:
        print("------------")
        for item in self._items:
            print("> " if item.is_current() else "  ", end="")
            print(item.get_title())

@dataclass
class MenuManager:
    _root_menu: Menu
    _cur_menu: Menu

    def get_root_menu(self) -> Menu:
        return self._root_menu

