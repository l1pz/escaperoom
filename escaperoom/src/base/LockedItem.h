#pragma once
#include <functional>
#include "Item.h"
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/memory.hpp>

class LockedItem :
	public virtual Item
{
private:
	bool _unlocked{false};
	std::shared_ptr<Item> _key;
	void _unlock();

public:
	LockedItem() = default;
	explicit LockedItem(std::shared_ptr<Item> key);
	LockedItem(std::string_view name, std::string_view description, std::shared_ptr<Item> key);
	using Item::Item;

public:
	std::string unlockedMessage{ "Sikerült kinyitni." };
	std::string alreadyUnlockedMessage{ "Ezt már egyszer kinyitottam." };
	std::string needKeyMessage{ "Ennek a kinyitásához valami tárgyra van szükségem." };
	std::string wrongKeyMessage{ "Ezt nem ezzel a tárggyal kell kinyitni." };

public:
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::virtual_base_class<Item>(this), _unlocked, _key);
	}
	bool isUnlocked() const { return _unlocked; }
	void check() override;
	void unlock(const Item& key) override;
	void unlock() override;
	bool isLockable() override { return true; }
};