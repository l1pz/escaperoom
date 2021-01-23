#include "LockedItem.h"

#include <iostream>

void LockedItem::_unlock()
{
	if(!_unlocked)
	{
		_unlocked = true;
		std::cout << "Sikeres kinyitottad ezt: " << name();
		_callback();
	}
	else
	{
		std::cout << "Ezt már egyszer kinyitottam.";
	}
	
}

LockedItem::LockedItem(const std::string_view name, const std::string_view description, std::function<void()> callback, std::optional<std::shared_ptr<Item>> key = std::nullopt)
	: Item{ name, description }, _callback{ std::move(callback) }, _key{ std::move(key) }
{
}



void LockedItem::unlock()
{
	if (!_key)
	{
		_unlock();
	}
}

void LockedItem::unlock(const Item& key)
{
	if (key == *_key.value())
	{
		_unlock();
	}
	else
	{
		std::cout << "Ezt nem ezzel a tárggyal kell kinyitni.";
	}
}
