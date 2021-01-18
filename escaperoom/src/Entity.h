#pragma once
#include <string>
#include <unordered_set>
#include <memory>
class Entity
{
private:
	std::string _description;

public:
	Entity() : _description("Ennek a tárgynak nincs leírása...") {};
	Entity(const std::string_view description) : _description(description) {};
	void check();

};

