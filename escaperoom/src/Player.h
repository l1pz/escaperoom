#pragma once
#include <unordered_map>
#include <functional>
#include "base/StorageItem.h"
#include "base/Room.h"
class Player
{
private:
	std::shared_ptr<Room> _currentRoom;
	StorageItem _backpack{"backpack", "backpack"};
	std::unordered_map<std::string,
		std::function<void(const std::vector<std::string>& items)>> _actions{
		{"nézd", [this] (const std::vector<std::string>& items){this->_check(items); }},
		{"vedd fel", [this](const std::vector<std::string>& items) {this->_pickup(items); }}
	};

	void _check(const std::vector<std::string>& items) const;
	void _pickup(const std::vector<std::string>& items);

public:
	explicit Player(std::shared_ptr<Room> currentRoom);
	void input();
};

