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

public:
	Entity(const std::string_view name, const std::string_view description) :
		_name{ name }, _description{ description } {}
	const std::string& name() const { return _name; }
	virtual void check();
	
};

