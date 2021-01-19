#include "Item.h"

std::optional<std::shared_ptr<Item>> Item::removeItem(const std::string& name)
{
	std::optional<std::shared_ptr<Item>> i;
	if (_items.count(name)) {
		i = move(_items[name]);
		_items.erase(name);
		return move(i);
	}
	else {
		for (const auto& item : _items) {
			i = item.second->removeItem(name);
			if (i) return move(i);
		}
	}
	return move(i);
}

void Item::addItem(std::shared_ptr<Item> item) {
	_items[item->name()] = move(item);
}
