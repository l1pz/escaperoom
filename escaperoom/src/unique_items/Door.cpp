#include "Door.h"

Door::Door(const std::string_view name, const std::string_view description, std::shared_ptr<Item> key)
	: Item{ name, description }, LockedItem{ std::move(key) }
{
}

Door::Door(const std::string_view name, const std::string_view description)
	: Item{ name, description }
{
}

