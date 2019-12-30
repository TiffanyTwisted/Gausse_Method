// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#ifndef PCH_H
#define PCH_H
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

double** createMatrix(int , int );
void deleteMatrix(double **, int );
void enterMatrix(double **, int, int, ifstream &);
void viewMatrix(double **, int , int);
void viewAnswer(double *, int );
void copyMatrix(double **, double **, int , int );
int Gauss(double *, double **, int , int );
void VecNev(double *, double *, double **, int , int );
double Pogresh(double *, double *, int );
void Perez(double *, double **, int , int );




// TODO: add headers that you want to pre-compile here

#endif //PCH_H
