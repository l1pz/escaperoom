#pragma once
#include <functional>
#include "Item.h"

class LockedItem :
	public virtual Item
{
protected:
	bool _unlocked{false};
	std::function<void()> _callback;
	std::optional<std::shared_ptr<Item>> _key;
public:
	LockedItem(std::string_view name, std::string_view description, std::function<void()> callback, std::optional<std::shared_ptr<Item>> key);
	bool unlock(const Item& key) override;
	bool unlock() override;
	bool isLockable() override { return true; }
};
