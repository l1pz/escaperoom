#include "Entity.h"
#include<iostream>

void Entity::check() {
	std::cout << _description << std::endl;
}

void Entity::add(std::shared_ptr<Entity> e) {
	inside[e->name()] = move(e);
}

std::shared_ptr<Entity> Entity::remove(const std::string& name) {
	if (!_open) return;
	if (inside.count(name)) {
		std::shared_ptr<Entity> e = move(inside[name]);
		inside.erase(name);
		return move(e);
	}
	else {
		std::shared_ptr<Entity> e;
		for (const auto& x : inside) {
			e = x.second->remove(name);
			if (e) break;
		}
		return move(e);
	}
}

void Entity::open() {}
