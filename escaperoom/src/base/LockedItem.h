#pragma once
#include <functional>
#include "Item.h"

class LockedItem :
	public virtual Item
{
protected:
	bool _unlocked{false};
	std::function<void()> _callback{[](){}};
	std::optional<std::shared_ptr<Item>> _key{std::nullopt};
	void _unlock();
public:
	LockedItem() = default;
	LockedItem(std::string_view name, std::string_view description, std::function<void()> callback, std::optional<std::shared_ptr<Item>> key);
	void unlock(const Item& key) override;
	void unlock() override;
	bool isLockable() override { return true; }
};
