#include "cmd.h"

Cmd::Cmd() {}
Cmd::~Cmd() {}

void Cmd::run() {
	int n;
	while (true) {
		cout << setw(5) << "================\n";
		cout <<setw(5)<< "1. Item 추가\n";
		cout << setw(5) << "2. 화면에 출력\n";
		cout << setw(5) << "3. Empty List\n";
		cout << setw(5) << "4. Quit\n";
		cout << setw(5) << "================\n";
		cin >> n;
		if (n == 1) { elem.SetRecordFromKB(); AL.Add(elem); }
		else if (n == 2) { AL.PrintAll(); }
		else if (n == 3) { AL.MakeEmpty(); }
		else if (n == 4) { cout << "EXITTING PROGRAMMMM....\n"; break; }
		else { cout << "Illegal Input\n"; }
	}
}
//void Cmd::addItem() {}
//void Cmd::printAll() { AL.PrintAll(); }
//void Cmd::makeEmptyList() { AL.MakeEmpty(); }
//void Cmd::getFromFile() {}
//void Cmd::putToFile() {}
//bool Cmd::quit() {}

