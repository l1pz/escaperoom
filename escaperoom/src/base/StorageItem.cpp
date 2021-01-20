#include "StorageItem.h"

std::optional<std::shared_ptr<Item>> StorageItem::removeItem(const std::string& name)
{
	std::optional<std::shared_ptr<Item>> i;
	for (const auto& [name, item] : _items) {
		i = item->removeItem(name);
		if (i) {
			_items.erase(name);
			return i;
		}
	}
	return i;
}

std::optional<std::shared_ptr<Item>> StorageItem::getItem(const std::string& name)
{
	auto i{Item::getItem(name)};
	for (const auto& [name, item] : _items) {
		if (i) break;
		i = item->getItem(name);
	}
	return i;
}

void StorageItem::addItem(std::shared_ptr<Item> item) {
	_items[item->name()] = move(item);
}