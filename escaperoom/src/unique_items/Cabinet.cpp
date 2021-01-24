#include "Cabinet.h"

Cabinet::Cabinet(const std::string_view name, const std::string_view description, std::shared_ptr<Room> room, std::shared_ptr<Item> key)
	: Item{ name, description }, MovableItem{ std::move(room) }, LockedItem{ std::move(key) }
{
}

Cabinet::Cabinet(const std::string_view name, const std::string_view description, std::shared_ptr<Room> room)
	: Item{ name, description }, MovableItem { std::move(room) }
{
}

void Cabinet::check()
{
	if (isUnlocked())
	{
		StorageItem::check();
	}
	else
	{
		LockedItem::check();
	}
}