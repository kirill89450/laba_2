#include <iostream>
#include <math.h>
using namespace std;

int main()

{
	setlocale(LC_ALL, "rus");

	int key = -1;
	while (key != 0)
	{
		cout << "Имеются задания 1-9"
			<< "\n";
		cout << "Введите какой номер задания хотите решить или введите 0 для выхода:"
			<< "\n";
		cin >> key;
		switch (key)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;

		case 9:

			break;
		case 0:
			cout << "Досвидания!"
				<< "\n";
			break;
		default:
			cout << "Такого задания нет"
				<< "\n";
		}
	}

	return 0;
}