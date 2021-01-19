#include "Item.h"

std::optional<std::shared_ptr<Item>> Item::getItem(const std::string& name)
{
	if (this->name() == name) 
		return move(shared_from_this()); 
	return std::nullopt;
}
