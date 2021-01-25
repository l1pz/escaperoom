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



void Room::addExit(Exit exit)
{
	assert(_exits.count(exit.direction) == 0);
	_exits[exit.direction] = std::move(exit);
	
}

std::optional<std::shared_ptr<Room>> Room::exit(const Direction dir)
{
	if (_exits.count(dir))
	{
		if(!_exits[dir].lock || _exits[dir].lock->isUnlocked())
		{
			std::cout << "Átmentél az kijáraton " << Room::directionToString(dir) << ".";
			return _exits[dir].room;
		}
		else
		{
			std::cout << _exits[dir].lockedMessage;
			return std::nullopt;
		}
	}
	std::cout << "Ebben az irányban nincs kijárat.";
	return std::nullopt;
}

void Room::check()
{
	StorageItem::check();
	/*for (const auto& [direction, exit] : _exits)
	{
		if (exit.lock->isUnlocked())
		{
			std::cout << std::endl << "Egy kijárat van " << _directionToString[direction] << ".";
		}
	}*/
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
