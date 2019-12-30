#include "pch.h"

void main()
{

	setlocale(LC_ALL, "Russian");

	int row= 3; //cout << "\n  количество уравнений: "; //cin >> row;
	int column = 4;// cout << "\n  количество неизвестных уравнений: "; //cin >> column; column++;
	cout << "Matrix : " << endl;

	double **A = createMatrix(row, column);
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
	out.close();*/
		
	ifstream in("file.txt");
	enterMatrix(A, row, column, in);
	in.close();

	double **B = createMatrix(row, column);
	copyMatrix(A, B, row, column);
	cout << endl << endl;
	viewMatrix(B, row, column);

	double *Answer = new double[row];

	double *K = new double[row];


	if (Gauss(Answer, B, row, column) == 1)
	{
		cout << endl << " Ответ\n\n";
		viewAnswer(Answer, row);

		double *Nev = new double[row];
		VecNev(Nev, Answer, A, row, column);
		delete Nev;


		copyMatrix(A, B, row, column);
		Perez(Answer, B, row, column);

		//viewMatrix(B, row, column);

		double *Answer1 = new double[row];
		if (Gauss(Answer1, B, row, column) == 1)
		{
			//viewAnswer(Answer1, row);
			double pogr = Pogresh(Answer, Answer1, row);

			cout << "Относительная погрешность " << pogr << endl;
			delete Answer1;
		}
		
			
	  
	}
	else cout << "\n Система не имеет решений!\n\n";

	

	delete Answer;
	deleteMatrix(B, row);
	deleteMatrix(A, row);

	system("pause");



}

double** createMatrix(int x, int y)
{
	double **A = new double*[x];
	for (int i = 0; i < x; i++)
		A[i] = new double[y];
	return A;
}

void deleteMatrix(double **X, int x)
{
	for (int i = 0; i < x; i++)
		delete X[i];
	delete[] X;
}

void enterMatrix(double **X, int x, int y, ifstream &in)
{
	for (int i = 0; i < x; i++)
	{
		//cout << i + 1 << " equation\n";
		for (int j = 0; j < y; j++)
		{
			double element; in >> element;
			X[i][j] = element;
			//A[i][j] = rand() % 4;
			//cin >> X[i][j];
		}
	}
}

void viewMatrix(double **X, int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cout << setw(12) << X[i][j];
		cout << endl;
	}
	cout << endl << endl;
}

void viewAnswer(double *X, int x)
{
	for (int i = 0; i < x; i++)
		cout << setw(12) << X[i];
	cout << endl;
}
void copyMatrix(double **X, double **copyX, int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			copyX[i][j] = X[i][j];
	}
}
int Gauss(double *An, double **X, int row, int column)
{

	//cout << " Преобразование матрицы методом Гаусса " << endl;

	for (int k = 0; k < row; k++)
	{
		double max = fabs(X[k][k]);
		int remeber = k;		            //запоминаем строку, чтобы не поменять саму себя
		for (int i = k + 1; i < row; i++)
		{
			if (max < fabs(X[i][k]))		//находим максимальный по модулю элемент в столбце
			{
				max = fabs(X[i][k]);
				remeber = i;
			}
		}

		if (fabs(max - 0) < 1e-6)
		{
			return 0;
		}

		if (k != remeber)				//меняем строки местами
		{
			double *temp = X[k];
			X[k] = X[remeber];
			X[remeber] = temp;
			
		}

		//viewMatrix(X, row, column);

		double lead = X[k][k];			//запоминаем ведущий элемент
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
		//viewMatrix(X, row, column);
	}

	An[row - 1] = X[row - 1][column - 1];				//обратный ход
	for (int i = row - 2; i >= 0; i--)
	{
		An[i] = X[i][column - 1];
		for (int j = i + 1; j < column - 1; j++)
		{
			An[i] -= X[i][j] * An[j];
		}
	}
	return 1;
}

void VecNev(double *Nev, double *An, double **X, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		double sum = 0;
		for (int j = 0; j < column - 1; j++)
		{
			sum += X[i][j] * An[j];
		}
		Nev[i] = sum - X[i][column - 1];
	}
	// норма : 
	double nev = fabs(Nev[0]);
	for (int i = 1; i < row; i++)
		if (nev < fabs(Nev[i]))
			nev = fabs(Nev[i]);

	cout << "\n Норма :    " << nev << endl << endl;
	cout << "\n Вектор невязки :   "  << endl;
	viewAnswer(Nev, row);
}

void Perez(double *An, double **X, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		double sum =0;
		for (int j = 0; j < column - 1; j++)
		{
			sum += X[i][j] * An[j];                    // в штрих
		}
		X[i][column - 1] = sum;
		
	}
	

}
double Pogresh(double*A, double*A1, int row)
{
	double max = A[0] - A1[0];
	double max1 = A[0];

	for (int i = 1; i < row; i++)
		if (max < (A[i] - A1[i]))
			max = (A[i] - A1[i]);
	for (int i = 1; i < row; i++)
		if (max < (A[i]))
			max = (A[i]);
	
	return(max / max1);
}



