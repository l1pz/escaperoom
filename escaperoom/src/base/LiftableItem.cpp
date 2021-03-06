#include "LiftableItem.h"

std::optional<std::shared_ptr<Item>> LiftableItem::removeItem(const std::string& name)
{
	if (name == this->name()) return shared_from_this();
	return std::nullopt;
}
