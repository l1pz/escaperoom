#pragma once
#include "StorageItem.h"
#include "LockedItem.h"

class LockedStorageItem :
	virtual public LockedItem,
	virtual public StorageItem
{
public:
	LockedStorageItem() = default;
	explicit LockedStorageItem(std::shared_ptr<Item> key);
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::virtual_base_class<LockedItem>(this), cereal::virtual_base_class<StorageItem>(this));
	}
	void check() override;
	std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) override;
	std::optional<std::shared_ptr<Item>> getItem(const std::string& name) override;
};

