#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;


void RES(int** n, int* n1, int a, int b);

void WIN(int* n, int a);
int main()

{
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "Введите сколько спортсменов и сколько каждый из них сделал выстрелов\n";
	cin >> n;
	cin >> m;

	while (n == 0 || m == 0 || n == 1 || m == 1);

	cout << "Номер стрелка:" << n << "\n Сделал выстрелов:" << m << "\n";

	int** a;

	a = new int* [n];

	for (int i = 0; i < n; i++)

		a[i] = new int[m];

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

			a[i][j] = rand() % 11;

	for (int i = 0; i < n; i++)

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