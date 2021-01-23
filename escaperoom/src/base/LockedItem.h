#pragma once
#include <functional>
#include "Item.h"
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/memory.hpp>

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
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::virtual_base_class<Item>(this), _unlocked, _key);
	}
	void unlock(const Item& key) override;
	void unlock() override;
	bool isLockable() override { return true; }
};

CEREAL_REGISTER_TYPE(LockedItem);