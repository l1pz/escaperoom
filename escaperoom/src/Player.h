#pragma once
#include <unordered_map>
#include <functional>
#include "base/StorageItem.h"
#include "base/Room.h"

#include <cereal/types/memory.hpp>

class Player
{
private:
	std::shared_ptr<Room> _currentRoom;
	StorageItem _backpack{"backpack", "backpack"};

private:
	std::unordered_map<std::string,
	                   std::function<void(const std::vector<std::string>& items)>> _actions{
		{"nézd", [this](const std::vector<std::string>& items) { this->_check(items); }},
		{"vedd fel", [this](const std::vector<std::string>& items) { this->_pickup(items); }},
		{"leltár", [this](const std::vector<std::string>& items) { this->_checkBackpack(items); }},
		{"tedd le", [this](const std::vector<std::string>& items) { this->_putdown(items); }},
		{"nyisd", [this](const std::vector<std::string>& items) { this->_unlock(items); }},
		{"húzd", [this](const std::vector<std::string>& items) { this->_move(items); }},
		{"törd", [this](const std::vector<std::string>& items) { this->_break(items); }},

	  {"kelet", [this](const std::vector<std::string>& items) { this->_direction(items, Room::Direction::EAST); }},
	  {"dél", [this](const std::vector<std::string>& items) { this->_direction(items, Room::Direction::SOUTH); }},
	  {"nyugat", [this](const std::vector<std::string>& items) { this->_direction(items, Room::Direction::WEST); }},
	  {"észak", [this](const std::vector<std::string>& items) { this->_direction(items, Room::Direction::NORTH); }},

		{"mentés", [this](const std::vector<std::string>& items) { this->_save(items); }},
		{"betöltés", [this](const std::vector<std::string>& items) { this->_load(items); }},
	                   	
		{"?", [this](const std::vector<std::string>& items) { this->_help(); }},
	                   	
	};
	std::optional<std::shared_ptr<Item>> _getItem(const std::string& item);

	
	void _check(const std::vector<std::string>& items);
	void _pickup(const std::vector<std::string>& items);
	void _checkBackpack(const std::vector<std::string>& items);
	void _putdown(const std::vector<std::string>& items);
	void _unlock(const std::vector<std::string>& items);
	void _move(const std::vector<std::string>& items) const;
	void _break(const std::vector<std::string>& items);
	void _direction(const std::vector<std::string>& items, Room::Direction dir);
	void _help();
	void _save(const std::vector<std::string>& items);
	void _load(const std::vector<std::string>& items);

public:
	explicit Player(std::shared_ptr<Room> currentRoom);
	void input();
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(_currentRoom, _backpack);
	}
};
