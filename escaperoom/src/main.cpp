#include <Windows.h>

#include "Entity.h"


int main() {
	SetConsoleCP(65001); // set input console codepage to utf8
	SetConsoleOutputCP(65001); // set output console codepage to utf8
	Entity e;
	e.check();
	return 0;
}