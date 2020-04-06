#include <iostream>
#include <math.h>
using namespace std;


void RES(int** n, int* n1, int a, int b);

void WIN(int* n, int a);
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
			int n, m;
			cout << "Введите сколько спортсменов и сколько каждый из них сделал выстрелов\n";
			cin >> n;
			cin >> m;

		while (n == 0 || m == 0 || n == 1 || m == 1);

		cout << "Номер стрелка:" << n << "\n Сделал выстрелов:" << m << "\n";

		

		{

			for (int j = 0; j < m; j++)

			{

				printf("%5d", a[i][j]);

			}

			cout << endl;

		}

		int* result;

		result = new int[n];

		RES(a, result, n, m);

		WIN(result, n);
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

void RES(int** n, int* n1, int a, int b)

{

	int s;

	for (int i = 0; i < a; i++)

	{

		s = 0;

		for (int j = 0; j < b; j++)

			s += n[i][j];

		n1[i] = s;

	}

	cout << "\nРезультат: ";

	for (int i = 0; i < a; i++)

		cout << n1[i] << " ";

}

void WIN(int* n, int a)

{

	int max, maxI;

	max = n[0];

	for (int i = 0; i < a; i++)

	{

		if (n[i] > max)

			max = n[i];

	}

	cout << "\n" << max << "\nПобедитель(ли):\n";

	for (int i = 0; i < a; i++)

	{

		if (n[i] == max)

		{

			cout << "Номер стрелка " << i + 1 << endl;

		}

	}

}