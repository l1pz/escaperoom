#include "Box.h"

Box::Box(const std::string_view name, const std::string_view description, std::shared_ptr<Item> key)
	: Item{ name, description },	LockedStorageItem { std::move(key) }
{
}

Box::Box(const std::string_view name, const std::string_view description)
	: Item{ name, description }
{
}

std::optional<std::shared_ptr<Item>> Box::removeItem(const std::string& name)
{
	auto i{ LiftableItem::removeItem(name) };
	if(!i)
	{
		i = StorageItem::removeItem(name);
	}
	return i;
}
