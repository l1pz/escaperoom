#include "Room.h"

#include <cassert>
#include <memory>

void Room::addExit(const Direction direction, std::shared_ptr<Room> exit) {
	assert(_exits.count(direction) != 0);
	_exits[direction] = move(exit);
}

std::optional<std::shared_ptr<Item>> Room::getItem(const std::string& name) {
	std::optional<std::shared_ptr<Item>> i;
	for (const auto& [itemName, item] : _items) {
		if (i) break;
		i = item->getItem(name);
	}
	return i;
}
