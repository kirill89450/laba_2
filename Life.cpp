#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <random>
#include <Windows.h>

using namespace std;


void pole(int** a, int n, int m); //показывание поля

int lifepoints(int** a, int n, int m); //живые точки

void nbPoints(int nb[][2], int x, int y); //соседние точки

int lifeNBpoints(int** a, int n, int m, int x, int y);

void NewGeneration(int** a, int** a1, int n, int m); 

void CopyLastPole(int** a, int** a1, int n, int m); 

int Sravnenie(int** a, int** a1, int n, int m); 

int main()

{
	setlocale(LC_ALL, "Russian");
	int n, m;


	n = rand() % 21;

	m = rand() % 21;


	while (n < 4 || m < 4);

	cout << "\nРазмер поля: \n" << " длинна " << n <<" ширина "<< m << "\n";

	int** field; 

	field = new int* [n];

	for (int i = 0; i < n; i++)

		field[i] = new int[m];

	std::random_device rd; 

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

	int** PreviousField; 

	PreviousField = new int* [n];

	for (int i = 0; i < n; i++)

		PreviousField[i] = new int[m];

	int livingpoints = -1;

	bool ideal = false;

	do

	{

		pole(field, n, m); 

		CopyLastPole(field, PreviousField, n, m); 

		NewGeneration(field, PreviousField, n, m); 

		ideal = Sravnenie(field, PreviousField, n, m) == 0; 

		livingpoints = lifepoints(field, n, m); 

		if (ideal)

			cout << "Идеально\n"; 

		if (livingpoints == 0)

			cout << "GameOver\n"; 

		Sleep(2000); 

	} while (livingpoints != 0 || !ideal);

	return 0;

}



void pole(int** a, int n, int m) 

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

void nbPoints(int nb[][2], int x, int y) 

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

int lifeNBpoints(int** a, int n, int m, int x, int y) 

{

	int count = 0;

	int nb[8][2];

	int x_, y_;

	nbPoints(nb, x, y);

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

			livingNB = lifeNBpoints(a1, n, m, i, j);

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

void CopyLastPole(int** a, int** a1, int n, int m)

{

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

			a1[i][j] = a[i][j];

}

int Sravnenie(int** a, int** a1, int n, int m) 

{

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

			if (a != a1)

				return -1;

	return 0;
}