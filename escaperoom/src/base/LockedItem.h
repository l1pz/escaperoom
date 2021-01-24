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
	std::string unlockedMessage{ "Siker�lt kinyitni." };
	std::string alreadyUnlockedMessage{ "Ezt m�r egyszer kinyitottam." };
	std::string needKeyMessage{ "Ennek a kinyit�s�hoz valami t�rgyra van sz�ks�gem." };
	std::string wrongKeyMessage{ "Ezt nem ezzel a t�rggyal kell kinyitni." };

protected:
	bool isUnlocked() const { return _unlocked; }

public:
	LockedItem() = default;
	using Item::Item;
	LockedItem(std::string_view name, std::string_view description, std::shared_ptr<Item> key);
	explicit LockedItem(std::shared_ptr<Item> key);
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::virtual_base_class<Item>(this), _unlocked, _key);
	}
	void check() override;
	void unlock(const Item& key) override;
	void unlock() override;
	bool isLockable() override { return true; }
};