#pragma once
#include <string>
#include <unordered_map>
#include <memory>
class Entity
{
private:
	std::string _name;
	std::string _description;
	bool _open{ false };

public:
	std::unordered_map<std::string, std::shared_ptr<Entity>> inside;

public:
	Entity(const std::string_view name, const std::string_view description) : _name{ name }, _description{ description } {};
	const std::string& name() const { return _name; };
	void check();
	void add(std::shared_ptr<Entity> e);
	std::shared_ptr<Entity> remove(const std::string& name);
	void open();

};

