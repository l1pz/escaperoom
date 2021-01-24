#pragma once
#include "Entity.h"
#include <cereal/types/base_class.hpp>
#include <optional>
class Item :
	public Entity,
	public std::enable_shared_from_this<Item>
{
public:
	using Entity::Entity;
	bool operator==(const Item& rhs) const { return this->name() == rhs.name(); }

	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::base_class<Entity>(this));
	}

	virtual void addItemInside(std::shared_ptr<Item> item, std::string_view description)
	{
	}

	virtual void addItemBehind(std::shared_ptr<Item> item, std::string_view description, std::string_view descriptionMoved)
	{
	}

	virtual std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) { return std::nullopt; }
	virtual std::optional<std::shared_ptr<Item>> getItem(const std::string& name);
	virtual std::vector<std::string> getItemList() { return {}; }
	virtual bool isLiftable() { return false; }
	virtual bool isLockable() { return false; }
	virtual bool isStorage() { return false; }
	virtual bool isMovable() { return false; }
	virtual bool isBreakable() { return false; }

	virtual void unlock(const Item& key)
	{
	}

	virtual void unlock()
	{
	}

	virtual void move()
	{
	}

	virtual void breakIt(const Item& tool)
	{
	}
	
	virtual void breakIt()
	{
	}
};
