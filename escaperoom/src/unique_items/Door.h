#pragma once
#include "../base/LockedItem.h"
class Door :
	public LockedItem
{
private:
	std::shared_ptr<bool> _exitUnlocked;
public:
	Door() = default;
	Door(std::string_view name, std::string_view description, std::shared_ptr<Item> key);
	Door(std::string_view name, std::string_view description);
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::base_class<LockedItem>(this));
	}
	bool exitCondition() override;
};

CEREAL_REGISTER_TYPE(Door);
