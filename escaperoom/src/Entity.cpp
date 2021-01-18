#include "Entity.h"
#include<iostream>

void Entity::check() {
	std::cout << _description << std::endl;
}

void Entity::add(std::shared_ptr<Entity> e) {
	inside[e->name()] = move(e);
}

std::shared_ptr<Entity> Entity::remove(const std::string& name) {
	std::shared_ptr<Entity> e = inside[name];
	inside.erase(name);
	return move(e);
}
