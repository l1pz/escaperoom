#ifdef _WIN32
#include <Windows.h>
#endif

#include "Entity.h"


int main() {
#ifdef _WIN32
	SetConsoleCP(65001); // set input console codepage to utf8
	SetConsoleOutputCP(65001); // set output console codepage to utf8
#endif
	std::shared_ptr<Entity> spoon = std::make_unique<Entity>("spoon", "spoon");
	std::shared_ptr<Entity> fork = std::make_unique<Entity>("fork", "fork");
	std::shared_ptr<Entity> table = std::make_unique<Entity>("table", "table");
	std::shared_ptr<Entity> cabinet = std::make_unique<Entity>("cabinet", "cabinet");
	table->add(spoon);
	table->add(fork);
	
	return 0;
}