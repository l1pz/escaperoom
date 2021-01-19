#include "Item.h"

std::optional<std::shared_ptr<Item>> Item::removeItem(const std::string& name)
{
	if (this->name() == name) return move(shared_from_this());
	std::optional<std::shared_ptr<Item>> i;
	for (const auto& item : _items) {
		i = item.second->removeItem(name);
		if (i) {
			_items.erase(name);
			return move(i);
		}
	}
	return move(i);
}

void Item::addItem(std::shared_ptr<Item> item) {
	_items[item->name()] = move(item);
}
