#include "StorageItem.h"

#include <algorithm>

std::optional<std::shared_ptr<Item>> StorageItem::removeItem(const std::string& name)
{
	std::optional<std::shared_ptr<Item>> i;
	for (const auto& [itemName, item] : _items) {
		i = item->removeItem(name);
		if (i) {
			_items.erase(name);
			break;
		}
	}
	return i;
}

std::optional<std::shared_ptr<Item>> StorageItem::getItem(const std::string& name)
{
	auto i{Item::getItem(name)};
	for (const auto& [itemName, item] : _items) {
		if (i) break;
		i = item->getItem(name);
	}
	return i;
}

void StorageItem::addItem(std::shared_ptr<Item> item) {
	_items[item->name()] = move(item);
}

std::vector<std::string> StorageItem::getItemList() {
	std::vector<std::string> result;
	result.reserve(_items.size());
	for(const auto& [itemName, item] : _items) {
		result.push_back(itemName);
	}
	return result;
}
