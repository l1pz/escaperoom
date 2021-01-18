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
	std::shared_ptr<Entity> stash = std::make_unique<Entity>("stash", "stash");
	std::shared_ptr<Entity> jeans = std::make_unique<Entity>("jeans", "jeans");
	std::shared_ptr<Entity> pocket = std::make_unique<Entity>("pocket", "pocket");
	std::shared_ptr<Entity> coin = std::make_unique<Entity>("coin", "coin");
	std::shared_ptr<Entity> money = std::make_unique<Entity>("money", "money");
	table->add(stash);
	stash->add(money);
	table->add(jeans);
	jeans->add(pocket);
	pocket->add(coin);
	return 0;
}