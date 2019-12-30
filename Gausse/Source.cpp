// Gausse.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
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
	int n,             //����� ����� 
	int m,             //����� �������� 
	double*a,          // ����� �������
	double eps         //�������� ������ 
);

int main()
{
	setlocale(LC_ALL, "Russian");
	int i, j, k, rank, m, n;
	double eps = 0.00001;
	cout << "������ ������� n*m" << endl;
	cin >> n >> m;

	double* a = new double[m*n];
	double* c = a;


	cout << " ������� �������� �������" << endl;


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

	cout << "������� �������� " << endl;
	cin >> eps;


	rank = gaussemethod(n, m, a, eps);

	cout << " ������������ ��� ������� " << endl;
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
				l = k;                              // �������� ����� ������ 
				r = fabs(a[k*m + j]);                 //� ����. �������     
			}
		}


		if (r <= eps)   // ���������� �� ��������(������� ������ �����,���� �� ����)
		{
			for (k = i; k < n; ++k) {
				a[k*m + j] = 0.0;
			}

			++j;
			continue;    //��������� ����������
		}


		if (l != i)
		{//������ ������� i  � l  ������, ���� ������� ������ �� ������ �����
			for (k = j; k < m; ++k)
			{
				r = a[i*m + k];
				a[i*m + k] = a[l*m + k];
				a[l*m + k] = (-r);
			}

		}


		r = a[i*m + j];//����������� ������� 
		assert(fabs(r) > eps); //������� assert ������������, ����� �������� ���������� ���������,���� ������ � ��������

		//for (int p = i; p < n; i++)
		//{
		//	a[p*n + j] /= r;

		 //}
		//   ��������  j-�� �������,������� �� ������  i+1,
		// �������� �������. �������������� 2-�� ����
		//

		for (k = i + 1; k < n; ++k)
		{
			double c = (-a[k*m + j]) / r;       // ����������� �� ������� ����� �������� ��������� 
			// � �-�� ������ ����������  i-�� ,���������� �� �
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