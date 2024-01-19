#include <iostream>//ввод-вывод 
#include "Matrix_struct.h"//заголовочный файл с классом
#include <stdlib.h>// определяет функции srand,rand //author Yudin
#include <vector>  //для векторов
//author Yudin

using namespace std;
//СЧЕТ КООРДИНАТ В МАТРИЦЕ ДЛЯ ЛЮБЫХ МЕТОДОВ НАЧИНАЕТСЯ С 0. НАПРИМЕР (0,1) - ВТОРОЙ ЭЛЕМЕНТ ПЕРВОЙ СТРОКИ
int main()
{
	Test();

	Matrix L(4, 4);
	L.Fill_Random(10, 20);
	cout << L.Determinant();
}
