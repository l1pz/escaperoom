#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <optional>
class Entity
{
private:
	std::string _name;
	std::string _description;
	bool _unlocked{ true };

public:
	std::unordered_map<std::string, std::shared_ptr<Entity>> inside;

public:
	Entity(const std::string_view name, const std::string_view description, const bool unlocked = true) :
		_name{ name }, _description{ description }, _unlocked(unlocked) {};
	const std::string& name() const { return _name; };
	void check();
	void add(std::shared_ptr<Entity> e);
	std::optional<std::shared_ptr<Entity>> remove(const std::string& name);
	virtual void open();

};

