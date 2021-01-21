#include "LockedItem.h"

LockedItem::LockedItem(const std::string_view name, const std::string_view description, std::function<void()> callback, std::optional<std::shared_ptr<Item>> key = std::nullopt)
	: Item{ name, description }, _callback{ move(callback) }, _key{ move(key) } {}

void LockedItem::unlock(const Item& key)
{
	if (!_unlocked && key == *_key.value())
	{
		_unlocked = true;
		_callback();
	}
}
