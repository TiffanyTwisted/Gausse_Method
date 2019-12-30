// Gausse.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <cassert>    
/*
using namespace std;
int  gaussemethod(
	int n,             //число строк 
	int m,             //число столбцов 
	double*a,          // адрес массива
	double eps         //точность метода 
);

int main()
{
	setlocale(LC_ALL, "Russian");
	int i, j, k, rank, m, n;
	double eps = 0.00001;
	cout << "Размер матрицы n*m" << endl;
	cin >> n >> m;

	double* a = new double[m*n];
	double* c = a;


	cout << " Введите элементы матрицы" << endl;


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i*m + j];

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j) {
			cout << setw(3) << a[i*m + j];
		}
		cout << "\n";

	}

	cout << "Введите точность " << endl;
	cin >> eps;


	rank = gaussemethod(n, m, a, eps);

	cout << " Ступеньчатый вид матрицы " << endl;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j) {
			cout << setw(5) << a[i*m + j];
		}
		cout << "\n";

	}


	cout << "Rank" << rank;


	delete[] a;
	return 0;


}

int  gaussemethod(int n, int m, double * a, double eps)
{
	int i, j, k, l;
	double r;
	i = 0; j = 0;
	while (i < n && j < m)
	{
		r = 0.0;
		for (k = i; k < n; ++k)                    // poisk max
		{
			if (fabs(a[k*m + j]) > r) {
				l = k;                              // запомним номер строки 
				r = fabs(a[k*m + j]);                 //и макс. элемент     
			}
		}


		if (r <= eps)   // проверочка на точность(удаляем лишний мусор,если он есть)
		{
			for (k = i; k < n; ++k) {
				a[k*m + j] = 0.0;
			}

			++j;
			continue;    //следующая интеракция
		}


		if (l != i)
		{//меняем местами i  и l  строки, макс элемент ставим на первое место
			for (k = j; k < m; ++k)
			{
				r = a[i*m + k];
				a[i*m + k] = a[l*m + k];
				a[l*m + k] = (-r);
			}

		}


		r = a[i*m + j];//разрешающий элемент 
		assert(fabs(r) > eps); //функция assert используется, чтобы прервать выполнение программы,если ошибка в значении

		//for (int p = i; p < n; i++)
		//{
		//	a[p*n + j] /= r;

		 //}
		//   Обнуляем  j-ый столбец,начиная со строки  i+1,
		// применяя элемент. преобразования 2-го рода
		//

		for (k = i + 1; k < n; ++k)
		{
			double c = (-a[k*m + j]) / r;       // коэффициент на который нужно умножать строчечки 
			// к к-ой строке прибавляем  i-ую ,умноженную на с
			a[k*m + j] = 0.0;
			for (l = j + 1; l < m; ++l)
			{
				a[k *m + l] += c * a[i *m + l];
			}

		}
		++i; ++j;
	}
	return i;
}

*/