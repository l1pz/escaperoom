#include "LockedItem.h"

#include <iostream>

void LockedItem::_unlock()
{
	if(!_unlocked)
	{
		_unlocked = true;
		std::cout << "Sikeres kinyitottad ezt: " << name();
	}
	else
	{
		std::cout << "Ezt m�r egyszer kinyitottam.";
	}
	
}

LockedItem::LockedItem(const std::string_view name, const std::string_view description, std::optional<std::shared_ptr<Item>> key = std::nullopt)
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
		std::cout << "Ennek a kinyit�s�hoz valami t�rgyra van sz�ks�gem.";
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
		std::cout << "Ezt nem ezzel a t�rggyal kell kinyitni.";
	}
}
