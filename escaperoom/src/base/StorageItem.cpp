#include "StorageItem.h"

std::optional<std::shared_ptr<Item>> StorageItem::removeItem(const std::string& name)
{
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

void StorageItem::addItem(std::shared_ptr<Item> item) {
	_items[item->name()] = move(item);
}