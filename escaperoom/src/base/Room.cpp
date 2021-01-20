#include "Room.h"
#include <memory>

void Room::addExit(const Direction direction, std::shared_ptr<Room> exit) {
	assert(_exits.count(direction) != 0);
	_exits[direction] = move(exit);
}

void Room::addItem(std::shared_ptr<Item> item) {
	_items[item->name()] = move(item);
}

std::optional<std::shared_ptr<Item>> Room::removeItem(const std::string& name) {
	std::optional<std::shared_ptr<Item>> i;
	for (auto& [itemName, item] : _items) {
		i = item->removeItem(name);
		if (i) {
			_items.erase(name);
			return i;
		};
	}
	return i;
}

std::optional<std::shared_ptr<Item>> Room::getItem(const std::string& name) {
	std::optional<std::shared_ptr<Item>> i;
	for (auto& [itemName, item] : _items) {
		i = item->getItem(name);
		if (i) break;
	}
	return i;
}
