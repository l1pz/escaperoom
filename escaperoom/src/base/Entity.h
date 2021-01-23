#pragma once
#include <string>

#include <cereal/types/string.hpp>

class Entity
{
private:
	std::string _name;
	std::string _description;

public:
	Entity() = default;
	Entity(const std::string_view name, const std::string_view description) :
		_name{name}, _description{description}
	{
	}

	const std::string& name() const { return _name; }
	virtual void check();

	template <class Archive>
	void serialize(Archive& ar) {
		ar(_name, _description);
	};
};
