#include "LockedItem.h"

#include <iostream>

void LockedItem::_unlock()
{
	if(!_unlocked)
	{
		_unlocked = true;
		std::cout << unlockedMessage;
	}
	else
	{
		std::cout << alreadyUnlockedMessage;
	}
	
}

LockedItem::LockedItem(const std::string_view name, const std::string_view description, std::shared_ptr<Item> key)
	: Item{ name, description }, _key{ std::move(key) }
{
}



void LockedItem::unlock()
{
	if (!_key)
	{
		_unlock();
	}
	else
	{
		std::cout << needKeyMessage;
	}
}

void LockedItem::check()
{
	Item::check();
	if(_unlocked)
	{
		std::cout << " Ki van nyitva.";
	}
	else
	{
		std::cout << " Be van zárva.";
	}
}

void LockedItem::unlock(const Item& key)
{
	if (key == *_key)
	{
		_unlock();
	}
	else
	{
		std::cout << wrongKeyMessage;
	}
}
