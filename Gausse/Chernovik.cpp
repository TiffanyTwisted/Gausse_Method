#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
/*
using namespace std;

double** creatematr(int, int);
void deletematr(double**, int);
void entermatr(double **, int, int /*, ifstream&);
void viewmatr(double**, int , int );
void viewansw(double*, int );
void copymatr(double** , double** , int , int );
int  Gausse(double *, double **, int, int);
void vector(double*, double *, double**, int, int);


void main()
{
	int row, column; 

	setlocale(LC_ALL, "Russian");
	cout << "Введите кол-во уравнений : "; cin >> row;
	cout << "Введите кол-во неизвестных : "; cin >> column;

	column++;

	double**A = creatematr( row,column);
	/*ofstream out("file.txt");
	int chis;
	for (int i = 0; i < row; i++)
	{
		cout << " neizvestnie " << i + 1 << " ypavnenia\n";
		for (int j = 0; j < column; j++)
		{
			cin >> chis;
			out << chis << endl;
		}
	}
	out.close(); */

	//ifstream in("file.txt");
	//entermatr(A, row, column /*,in);
	//in.close();
	/*viewmatr(A, row, column);

	double **B = creatematr(row, column);
	copymatr(A, B, row, column);
	cout << endl << endl;
	viewmatr(B, row, column);


	double *Answ = new double[row];

	if (Gausse(Answ, B, row, column) == 1)
	{
		cout << endl << " Answer\n\n";
		viewansw(Answ, row);

		double *Nev = new double[row];
		vector(Nev, Answ, A, row, column);

		delete Nev;
	}
	else cout << "\n The system has no solutions!\n\n";
	delete Answ;
	deletematr(B, row);
	deletematr(A, row);

};

// создание матрицы
//double** creatematr(int x, int y)
{
	double**A = new double*[x];
	for (int i = 0; i < x; i++)
		A[i] = new double[y];
	return A;
}

// заполнение марицы из файла  
void entermatr(double **X, int x, int y/*, ifstream&in)
{
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) {
			double element;
			//in >> element;
			//X[i][j] = element;
			cin >> X[i][j];
		}
}

// отображение матрицы 
void viewmatr(double**X, int x, int y)
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			cout << setw(12) << X[i][j];
		cout << endl;
	}
	cout << endl << endl;

}

// копирование матрицы
void copymatr(double** copy, double** X, int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			copy[i][j] = X[i][j];
	}
}


//освобождение памяти 
void deletematr(double**X, int x)
{
	for (int i = 0; i < x; i++)
		delete X[i];
	delete[] X;
}


// отображение  ответа 
void viewansw(double*X, int x)
{
	for (int i = 0; i < x; i++)
		cout << setw(12) << X[i];
	cout << endl << endl;
}
// Метод Гаусса
int  Gausse(double *A, double ** X, int row, int column)
{
	for (int k = 0; k < row; k++)
	{
		double max = fabs(X[k][k]);
		int remember = k;   // запоминаем строчку 

		// поиск максимального элемента
		for (int i = k + 1; i < row; i++) {
			if (max < fabs(X[i][k]))
			{
				max = fabs(X[i][k]);
				remember = i;
			}

		}

		if (fabs(max - 0) < 1e-6)
		{
			return 0;

		}

		if (k != remember)
		{
			double*temp = X[k];
			X[k] = X[remember];
			X[remember] = temp;
		}

		double lead = X[k][k];          //запоминаем ведущий элемент
		for (int r = k; r < column; r++)
		{
			X[k][r] /= lead;
		}

		//начиная со следующей строки выполняем преобразование Гаусса
		for (int i = k + 1; i < row; i++)
		{
			double temp = X[i][k];
			for (int j = k; j < column; j++)
			{
				X[i][j] -= X[k][j] * temp;

			}
		}
		//viewmatr(A, n, m);
	}


	A[row - 1] = X[row - 1][column - 1];      //обратный ход
	for (int i = row - 2; i >= 0; i--)
	{
		A[i] = X[i][column - 1];
		for (int j = i + 1; j < column - 1; j++)
		{
			A[i] -= X[i][j] * A[j];
		}
	}

	return 1;

}
// вектор
void vector(double*A,double *B,  double**X, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		double sum =0;
		for (int j = 0; j < column - 1; j++)
		{
			sum += X[i][j] * A[j];
		}

		B[i] = sum - X[i][column-1];

	}

	double nev = fabs(B[0]);
	for (int i = 1; i < row; i++)
		if (nev < fabs(B[i]))
			nev = B[i];
}

*/