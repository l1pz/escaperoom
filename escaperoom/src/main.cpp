#ifdef _WIN32
#include <Windows.h>
#endif

#include "Entity.h"


int main() {
#ifdef _WIN32
	SetConsoleCP(65001); // set input console codepage to utf8
	SetConsoleOutputCP(65001); // set output console codepage to utf8
#endif
	std::shared_ptr<Entity> table = std::make_unique<Entity>("table", "table");
	std::shared_ptr<Entity> cabinet = std::make_unique<Entity>("cabinet", "cabinet");
	table->add(std::make_unique<Entity>("spoon", "spoon"));
	table->add(std::make_unique<Entity>("fork", "fork"));
	cabinet->add(table->remove("spoon"));
	return 0;
}