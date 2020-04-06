#include <iostream>
#include <math.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <random>
#include <Windows.h>
using namespace std;


void RES(int** n, int* n1, int a, int b);

void WIN(int* n, int a);


void pokazpolya(int** a, int n, int m);

int lifepoints(int** a, int n, int m);

void XYsosedey(int nb[][2], int x, int y);

int livinsosedy(int** a, int n, int m, int x, int y);

void NewGeneration(int** a, int** a1, int n, int m);

void Copy(int** a, int** a1, int n, int m);

int SravPole(int** a, int** a1, int n, int m);

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
		cout << "1: Состязания по стрельбе\n";

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
			break;
		case 2:

			break;
		case 3:
			cout << "Введите n и m\n";

			cin >> n;
			cin >> m;

			while (n < 4 || m < 4);

			cout << "\nSize of the field: " << n << " rows and " << m << " columns\n";

			int** field; //задаем поле (многомерный массив)

			field = new int* [n];

			for (int i = 0; i < n; i++)

				field[i] = new int[m];

			std::random_device rd; //заполнение случайно точками

			std::mt19937 gen(rd());

			std::uniform_int_distribution<> dis(1, 10000);

			for (int i = 0; i < n; i++)

				for (int j = 0; j < m; j++)

				{

					int num = dis(gen);

					if (num % 2 == 0)

						field[i][j] = 1;

					else

						field[i][j] = 0;

				}

			int** PreviousField; //задаем поле для запоминания предыдущего поколения

			PreviousField = new int* [n];

			for (int i = 0; i < n; i++)

				PreviousField[i] = new int[m];

			int livingpoints = -1;

			bool Edem = false;

			do

			{

				pokazpolya(field, n, m); //показ поля

				Copy(field, PreviousField, n, m); //копируем поле

				NewGeneration(field, PreviousField, n, m); //генерируем новое

				Edem = SravPole(field, PreviousField, n, m) == 0; //сравниваем поля

				livingpoints = lifepoints(field, n, m); //проверяем количество живых клеток

				if (Edem)

					cout << "Edem Garden\n"; //Эдемов сад

				if (livingpoints == 0)

					cout << "YOU DIED\n"; //все здохли. конец.

				Sleep(2000); //прерывание цикла, чтобы пользователь успел увидеть поле

			} while (livingpoints != 0 || !Edem);
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


void pokazpolya(int** a, int n, int m)

{

	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < m; j++)

		{

			if (a[i][j] == 1)

				cout << '*';

			else

				cout << ' ';

			cout << ' ';

		}

		cout << endl;

	}

}

int lifepoints(int** a, int n, int m)

{

	int count = 0;

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

			if (a[i][j] == 1)

				count++;

	return count;

}

void XYsosedey(int nb[][2], int x, int y)

{

	int k = 0;

	for (int i = x - 1; i <= x + 1; i++)

		for (int j = y - 1; j <= y + 1; j++)

		{

			if (i == x && j == y)

				continue;

			nb[k][0] = i;

			nb[k][1] = j;

			k++;

		}

}

int livinsosedy(int** a, int n, int m, int x, int y)

{

	int count = 0;

	int nb[8][2];

	int x_, y_;

	XYsosedey(nb, x, y);

	for (int i = 0; i < 8; i++)

	{

		x_ = nb[i][0];

		y_ = nb[i][1];

		if (x_ < 0 || y_ < 0)

			continue;

		if (x_ >= n || y_ >= m)

			continue;

		if (a[x_][y_] == 1)

			count++;

	}

	return count;

}

void NewGeneration(int** a, int** a1, int n, int m)

{

	int livingNB, p;

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

		{

			p = a1[i][j];

			livingNB = livinsosedy(a1, n, m, i, j);

			if (p == 0)

			{

				if (livingNB == 3)

					a[i][j] = 1;

			}

			else

				if (livingNB < 2 || livingNB > 3)

					a[i][j] = 0;

		}

}

void Copy(int** a, int** a1, int n, int m)

{

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

			a1[i][j] = a[i][j];

}

int SravPole(int** a, int** a1, int n, int m)

{

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

			if (a != a1)

				return -1;

	return 0;

}