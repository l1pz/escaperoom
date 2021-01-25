#pragma once
#include "../base/StorageItem.h"

class Bathtub :
	public StorageItem
{
public:
	Bathtub() = default;
	Bathtub(std::string_view name, std::string_view description);
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::base_class<StorageItem>(this));
	}
};

CEREAL_REGISTER_TYPE(Bathtub)
