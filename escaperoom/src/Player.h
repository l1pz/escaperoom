#pragma once
#include "base/StorageItem.h"
class Player
{
private:
	StorageItem _backpack{"backpack", "backpack"};

private:
	void _processInput(const std::string_view action, const std::vector<std::string>& items);
public:
	void input();
};

