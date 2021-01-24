#include "Item.h"

void Item::check()
{
	std::cout << _description;
}

std::optional<std::shared_ptr<Item>> Item::getItem(const std::string& name)
{
	if (this->_name == name)
		return shared_from_this();
	return std::nullopt;
}
