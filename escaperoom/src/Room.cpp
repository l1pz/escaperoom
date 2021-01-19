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
	for (auto& item : _items) {
		if (item.first == name) {
			i = move(_items[name]);
			_items.erase(name);
			return move(i);
		}
		else {
			i = item.second->removeItem(name);
			if (i) return move(i);
		}
	}
	return move(i);
}
