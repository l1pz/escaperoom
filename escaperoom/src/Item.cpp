#include "Item.h"

Item::Item(const std::string_view name, const std::string_view description, std::optional<std::shared_ptr<Item>> key) :
	Entity{ name, description }, _key{ key }, _locked{ true } {}

std::optional<std::shared_ptr<Item>> Item::removeItem(const std::string& name)
{
	if (this->name() == name) return move(shared_from_this());
	std::optional<std::shared_ptr<Item>> i;
	if (!_locked) {
		for (const auto& item : _items) {
			i = item.second->removeItem(name);
			if (i) {
				_items.erase(name);
				return move(i);
			}
		}
	}
	return move(i);
}

void Item::addItem(std::shared_ptr<Item> item) {
	_items[item->name()] = move(item);
}

void Item::unlock(const Item& key) {
	if (key == *_key.value()) {
		_locked = false;
	}
}
