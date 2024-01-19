#pragma once
#include <vector>
//класс матрицы
class Matrix {

private:
	//поля
	std::vector<std::vector <double>> Matr;//сама матрица представляющая вектор векторов типа double

	//author Yudin

public: 
	//методы класса 
	
	//конструктор по умолчанию - заполняет нулями матрицу 3x3, если при объявлении не были введены размеры
	Matrix();

	//конструктор с параметрами - заполняет нулями матрицу rowXcol
	Matrix(unsigned int row, unsigned int col);

	//деструктор 
	~Matrix();

	//геттер матрицы в виде вектора из векторов типа double
	std::vector<std::vector<double>> Get_Matr() const;

	//вывод матрицы на экран
	void Output_Matrix ()const;

	//геттер элемента матрицы по его передаваемому в параметрах положению в матрице
	double Get_Element(unsigned int row, unsigned int col) const;

	//сеттер элемента матрицы по его передаваемому в параметрах положению в матрице
	void Set_Element(unsigned int row, unsigned int col, double param);

	//геттер строки матрицы по ее номеру(на выход подается double вектор)
	std::vector<double> Get_Str(unsigned int row) const;

	//сеттер строки матрицы по ее номеру и передаваемому вектору типа double то же размерности
	void Set_Str_By_Vector(unsigned int row, std::vector<double> str);

	//сеттер строки матрицы по ее номеру и передаваемому вектору типа double то же размерности
	void Set_Str_By_Keyboard(unsigned int row);

	//заполнение матрицы одним передаваемым числом number
	void Fill_With(double number);

	//заполнение матрицы случайными числами из диапазона min - max
	void Fill_Random(double min, double max);

	//умножение матрицы на число number
	void Matr_X_Number(double number);

	//транспонирование исходной матрицы(работает только для квадратной)
	void Transposition();

	//получение диагональной матрицы из исходной
	void Diagonal();

	//оператор сложения матриц(передаваемый тип данных - вектор из векторов типа double)
	void operator+= (const Matrix& Matr2);

	//оператор вычитания матриц(передаваемый тип данных - вектор из векторов типа double)
	void operator-= (const Matrix &Matr2);

	//оператор умножения матриц(передаваемый тип данных - вектор из векторов типа double)
	void operator*= (const Matrix& Matr2);

	//вычисление обратной матрицы к исходной методом корней(только для квадратных матриц!!!)
	void Reverse_Matrix();

	//вычисление определителя квадратной матрицы
	double Determinant() const;

	//геттер количества строк матрицы
	unsigned int Get_Row_count() const;

	//геттер количества столбцов матрицы
	unsigned int Get_Col_count() const;
	//удаление строки и столбца матрицы по координатам(на выход объект с матрицей без этого столбца и строки)
	Matrix Del_Row_Col(Matrix Matr2, int row, int col);
};

//функция для нахождения определителя(необходима для того, чтобы рекурсивный метод класса не вызывался множество раз, а все выполнялось в отдельной функции)
double Determinant_Func(const Matrix &Matr, int rang);

//проверка всех методов класса матрицы
void Test();

