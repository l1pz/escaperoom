#include "LockedItem.h"

LockedItem::LockedItem(const std::string_view name, const std::string_view description, std::function<void()> callback)
	: Item{ name, description }, _callback(move(callback)) {}

void LockedItem::unlock(const Item& key) {
	if (!_unlocked && key == *_key.value()) {
		_unlocked = true;
		_callback();
	}
}