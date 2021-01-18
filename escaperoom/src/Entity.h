#pragma once
#include <string>
#include <unordered_set>
#include <memory>
class Entity
{
private:
	std::string _description;

public:
	std::unordered_set<std::unique_ptr<Entity>> inside;

public:
	Entity() : _description("Ennek a tárgynak nincs leírása...") {};
	Entity(const std::string_view description) : _description(description) {};
	void check();
	void add(std::unique_ptr<Entity>& e);

};

