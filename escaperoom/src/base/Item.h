#pragma once
#include <cereal/types/string.hpp>
#include <optional>
class Item :
	public std::enable_shared_from_this<Item>
{

protected:
	std::string _name;
	std::string _description;

protected:
	void setName(const std::string& name) { _name = name; }
	void setDescription(const std::string& description) { _description = description; }
	
public:
	Item()
	{
		std::cout << "default item constructor called";
	};
	Item(const std::string_view name, const std::string_view description) :
		_name{ name }, _description{ description }
	{
		std::cout << "item initialized: " << _name << std::endl;
	}
	
	bool operator==(const Item& rhs) const { return this->_name == rhs._name; }

	template <class Archive>
	void serialize(Archive& ar) {
		ar(_name, _description);
	}

	const std::string& name() const { return _name; }
	const std::string& description() const { return _description; }
	
	virtual void check();

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
