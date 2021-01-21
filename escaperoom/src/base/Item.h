#pragma once
#include "Entity.h"

class Item :
	public Entity,
	public std::enable_shared_from_this<Item>
{
public:
	using Entity::Entity;
	bool operator==(const Item& rhs) const { return this->name() == rhs.name(); }

	virtual void addItem(std::shared_ptr<Item> item, std::string_view description)
	{
	}

	virtual std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) { return std::nullopt; }
	virtual std::optional<std::shared_ptr<Item>> getItem(const std::string& name);
	virtual std::vector<std::string> getItemList() { return {}; }
	virtual bool isLiftable() { return false; }
	virtual bool isLockable() { return false; }
	virtual bool isStorage() { return false; }

	virtual void unlock(const Item& key)
	{
	}
};
