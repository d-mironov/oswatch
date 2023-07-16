from dataclasses import dataclass, field
from typing import Callable


class MenuEmptyException(Exception):
    pass

@dataclass
class MenuItem:
    _title: str
    _callback: Callable
    _is_current: bool
    _is_focused: bool

    @property
    def title(self) -> str:
        return self._title

    @title.setter
    def title(self, new_title: str) -> None:
        self._title = new_title

    @property
    def is_current(self) -> bool:
        return self._is_current

    @is_current.setter
    def is_current(self, value: bool) -> None:
        self._is_current = value

    @property
    def is_focused(self) -> bool:
        return self._is_focused

    @is_focused.setter
    def is_focused(self, value: bool) -> None:
        self._is_focused = value



@dataclass
class BoolMenuItem(MenuItem):
    _value: bool

    @property
    def value(self) -> bool:
        return self._value

    @value.setter
    def setter(self, value: bool) -> None:
        self._value = value


@dataclass
class AppMenuItem(MenuItem):

    def execute(self) -> None:
        self._callback()


@dataclass
class Menu:
    _items: list[MenuItem]
    _current_item: int = field(default=0)

    def add_item(self, item: MenuItem) -> None:
        self._items.append(item)

    def next(self) -> None:
        self._current_item = (self._current_item + 1) % len(self._items)

    def prev(self) -> None:
        num_elem = len(self._items)
        self._current_item = (((self._current_item - 1) % num_elem) + num_elem) % num_elem

    @property
    def items(self) -> list[MenuItem]:
        return self._items

    @property
    def current_item_index(self) -> int:
        return self._current_item

    def current_item(self) -> MenuItem:
        if len(self._items) == 0:
            raise MenuEmptyException
        return self._items[self._current_item]
