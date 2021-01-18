#pragma once
#include <string>
#include <unordered_set>
#include <memory>
class Entity
{
private:
	std::string _description;

public:
	Entity() : _description(u8"Ennek a t�rgynak nincs le�r�sa...") {};
	Entity(const std::string_view description) : _description(description) {};
	void check();

};

