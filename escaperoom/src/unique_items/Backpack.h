#pragma once
#include "../base/StorageItem.h"

class Backpack :
	public StorageItem
{
public:
	using StorageItem::StorageItem;
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::base_class<StorageItem>(this));
	}
};

CEREAL_REGISTER_TYPE(Backpack);
