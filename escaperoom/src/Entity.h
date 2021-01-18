#pragma once
#include <string>
#include <unordered_set>
#include <memory>
class Entity
{
private:
	std::string _name;
	std::string _description;

public:
	std::unordered_set<std::unique_ptr<Entity>> inside;

public:
	Entity(const std::string_view name, const std::string_view description) : _name{ name }, _description{ description } {};
	void check();
	void add(std::unique_ptr<Entity>& e);

};

