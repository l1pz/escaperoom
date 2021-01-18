#ifdef _WIN32
#include <Windows.h>
#endif

#include "Entity.h"


int main() {
#ifdef _WIN32
	SetConsoleCP(65001); // set input console codepage to utf8
	SetConsoleOutputCP(65001); // set output console codepage to utf8
#endif
	
	return 0;
}