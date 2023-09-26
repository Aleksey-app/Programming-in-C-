#include <iostream>
#include "TApplication.h"

using namespace std;

TApplication::TApplication()
{
}

int TApplication::exec()
{
	int ch;
	while (true)
	{
		ch = menu();
		switch (ch)
		{
		case 0:
			return 0;
		default:
			break;
		}
	}
}
int TApplication::menu()
{
	int ch;
	cout << "0 - exit" << endl << ">";
	cin >> ch;
	return ch;
}
