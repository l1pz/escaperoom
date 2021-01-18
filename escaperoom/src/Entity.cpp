#include "Entity.h"
#include<iostream>

void Entity::check() {
	std::cout << _description << std::endl;
}

void Entity::add(std::unique_ptr<Entity>& e) {
	inside.insert(move(e));
}
