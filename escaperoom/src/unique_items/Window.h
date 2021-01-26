#pragma once
#include "../base/BreakableItem.h"
#include "../base/LockedItem.h"
class Window :
	public BreakableItem,
	public LockedItem
{
public:
	Window() = default;
	Window(std::string_view name, std::string_view description);
	Window(std::string_view name, std::string_view description, std::shared_ptr<Item> key, std::shared_ptr<Item> tool);
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::base_class<BreakableItem>(this));
	}
	void check() override;
	bool exitCondition() override;
};

CEREAL_REGISTER_TYPE(Window)

