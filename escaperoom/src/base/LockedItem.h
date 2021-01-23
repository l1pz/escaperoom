#pragma once
#include <functional>
#include "Item.h"

class LockedItem :
	public virtual Item
{
protected:
	bool _unlocked{false};
	std::shared_ptr<Item> _key;
	void _unlock();
public:
	LockedItem() = default;
	using Item::Item;
	LockedItem(std::string_view name, std::string_view description, std::shared_ptr<Item> key);
	void unlock(const Item& key) override;
	void unlock() override;
	bool isLockable() override { return true; }
};
