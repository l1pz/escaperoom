#include "Room.h"

#include <cassert>
#include <iostream>
#include <memory>

std::unordered_map<Room::Direction, std::string> Room::_directionToString{
	{Direction::EAST, "keletre"},
	{Direction::SOUTH, "délre"},
	{Direction::WEST, "nyugatra"},
	{Direction::NORTH, "északra"},
};

Room::Room(const std::string& name, const std::string& description)
{
	setName(name);
	setDescription(name);
}

void Room::addExit(const Direction direction, std::shared_ptr<Room> exit)
{
	assert(_exits.count(direction) == 0);
	_exits[direction] = std::move(exit);
}

std::optional<std::shared_ptr<Room>> Room::direction(const Direction dir)
{
		if(_exits.count(dir))
		{
			return _exits[dir];
		}
		return std::nullopt;
}

void Room::check()
{
	StorageItem::check();
	for (const auto& [direction, room] : _exits)
	{
		std::cout << std::endl << "Egy ajtó van " << _directionToString[direction] << ".";
	}
}

std::optional<std::shared_ptr<Item>> Room::getItem(const std::string& name)
{
	std::optional<std::shared_ptr<Item>> i;
	for (const auto& [itemName, item] : _items)
	{
		if (i) break;
		i = item->getItem(name);
	}
	return i;
}

std::string Room::directionToString(const Direction dir)
{
	return _directionToString[dir];
}
