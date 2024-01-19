#include "Matrix_struct.h"//заголовочный файл
#include <iostream> //ввод-вывод
#include <iomanip> //красивый вывод     //author Yudin 
#include <stdlib.h>//подключение srand,rand
#include <vector> //все вектора //author Yudin
#include <cmath> //математика в обр. матрице
#include <stdexcept> //стд аргументы try-catch
#include <cassert> //ассерты в тесте
using namespace std;


//стандартный конструктор, заполняет нулями матрицу 3x3
Matrix::Matrix() {
	unsigned int n = 3;
	Matr.resize(n);
	for (unsigned int i = 0; i < n; i++) {
		Matr[i].resize(n);
	}
}

//конструктор с параметрами, заполняет нулями матрицу rowXcol
Matrix::Matrix(unsigned int row, unsigned int col) {
	if (row < 1 || col < 1) {  //ГЄГЁГ¤Г ГҐГ¬ ГЁГ±ГЄГ«ГѕГ·ГҐГ­ГЁГҐ, ГҐГ±Г«ГЁ Г°Г Г§Г¬ГҐГ° Г¬Г ГІГ°ГЁГ¶Г» ГЇГ® Г±ГІГ°Г®ГЄГ Г¬ ГЁГ«ГЁ Г±ГІГ®Г«ГЎГ¶Г Г¬ < 1
		throw invalid_argument("Incorrect parameters of matrix size");
	}
	else {
		Matr.resize(row);
		for (unsigned int i = 0; i < row; i++) {
			Matr[i].resize(col);
		}
	}
}

//Деструктор()
Matrix::~Matrix() {
	//вектор сам освобождает память
	//cout << "~Matrix" << endl;
}


//геттер матрицы - вектора из векторов типа double
std::vector<std::vector<double>> Matrix::Get_Matr()const {
	return Matr;
}
//вывод матрицы на экран
void Matrix::Output_Matrix() const {
	cout << endl;
	for (unsigned int i = 0; i < Matr.size(); i++) {
		cout.precision(2);
		for (unsigned int j = 0; j < Matr[i].size(); j++) {
			cout << setfill(' ') << setw(12) << fixed << Matr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//геттер элемента матрицы row col
double Matrix::Get_Element(unsigned int row, unsigned int col) const{
	if ((row < 0 || row > Matr.size()) || (col < 0 || col > Matr[0].size())) { //ГЄГЁГ¤Г ГҐГ¬ ГЁГ±Г«ГѕГ·ГҐГ­ГЁГҐ, ГҐГ±Г«ГЁ ГўГўГҐГ¤ГҐГ­Г» Г­ГҐГЇГ°Г ГўГЁГ«ГјГ­Г»ГҐ ГЄГ®Г®Г°Г¤ГЁГ­Г ГІГ» Гў Г¬Г ГІГ°ГЁГ¶ГҐ
		throw std::invalid_argument("Incorrect Matrix coordinate");
	}
	else
	{
		return Matr[row][col];
	}
}

//сеттер элемента матрицы по его передаваемому в параметрах положению в матрице¤Г ГўГ ГҐГ¬Г®Г¬Гі Гў ГЇГ Г°Г Г¬ГҐГІГ°Г Гµ ГЇГ®Г«Г®Г¦ГҐГ­ГЁГѕ Гў Г¬Г ГІГ°ГЁГ¶ГҐ
void Matrix::Set_Element(unsigned int row, unsigned int col, double param) {  
	if ((row < 0 || row > Matr.size()) || (col < 0 || col > Matr[0].size())) { //ГЄГЁГ¤Г ГҐГ¬ ГЁГ±Г«ГѕГ·ГҐГ­ГЁГҐ, ГҐГ±Г«ГЁ ГўГўГҐГ¤ГҐГ­Г» Г­ГҐГЇГ°Г ГўГЁГ«ГјГ­Г»ГҐ ГЄГ®Г®Г°Г¤ГЁГ­Г ГІГ» Гў Г¬Г ГІГ°ГЁГ¶ГҐ
		throw std::invalid_argument("Incorrect Matrix coordinate");
	}
	else 
	{
		Matr[row][col] = param;
	}
}

//геттер строки матрицы по ее номеру row 
std::vector<double> Matrix::Get_Str(unsigned int row) const {
	if (row < 0 || row > Matr.size()) {  //ГЄГЁГ¤Г ГҐГ¬ ГЁГ±ГЄГ«ГѕГ·ГҐГ­ГЁГҐ, ГҐГ±Г«ГЁ Г­ГҐГЇГ°Г ГўГЁГ«ГјГ­Г® ГЇГҐГ°ГҐГ¤Г Г­ Г­Г®Г¬ГҐГ° Г±ГІГ°Г®ГЄГЁ
		throw std::invalid_argument("Incorrect row number");
	}
	else {
		return Matr[row];
	}
}

//сеттер строки матрицы по ее номеру благодаря вектору той же длины типа double
void Matrix::Set_Str_By_Vector(unsigned int row, const std::vector<double> str) {
	if (row < 0 || row >= Matr.size()) {  //проверяем правильно ли введен номер строки
		throw std::invalid_argument("Incorrect row number");
	}
	else if (str.size() != Matr[row].size()) { //проверяем длину вводимой строки
		throw std::length_error("Incorrect new string length");
	}
	else
	{
		for (unsigned int i = 0; i < Matr[row].size(); i++) {
			Matr[row][i] = str[i];
		}
	}
}

//сеттер строки матрицы по ее номеру вводом с клавиатуры
void Matrix::Set_Str_By_Keyboard(unsigned int row) {
	if (row < 0 || row >= Matr.size()) {  //проверяем правильно ли введен номер строки
		throw std::invalid_argument("Incorrect row number");
	}
	else
	{
		cout << "Input elements:" << endl;
		for (unsigned int i = 0; i < Matr[row].size(); i++) {
			cin >> Matr[row][i]; //вводим с клавиатуры значения элементов строки матрицы
		}
	}
}

//заполнение всей матрицы числом number
void Matrix::Fill_With(double number) {
	for (unsigned int i = 0; i < Matr.size(); i++) {
		for (unsigned int j = 0; j < Matr[i].size(); j++) {
			Matr[i][j] = number;
		}
	}
}

//заполнение рандомными числами из диапазона min - max
void Matrix::Fill_Random(double min, double max) {
	if (min > max || min == max) {  //проверяем чтобы были правильно введены диапазоны
		throw std::range_error("Incorrect random range input. Correct examples: (10, 20),  (1.12, 2.56)");
	}
	else
	{
		for (unsigned int i = 0; i < Matr.size(); i++) {
			for (unsigned int j = 0; j < Matr[i].size(); j++) {
				Matr[i][j] = (1.0 * rand() / RAND_MAX * (max - min) + min);// по формуле заполняем числами из диапазона
			}
		}
	}
}

//умножение матрицы на число number
void Matrix::Matr_X_Number(double number) {
	for (unsigned int i = 0; i < Matr.size(); i++) {
		for (unsigned int j = 0; j < Matr[i].size(); j++) {
			Matr[i][j] = Matr[i][j] * number;
		}
	}
}

//Транспонирование матрицы
void Matrix::Transposition() {
	std::vector<std::vector<double>> T;   //создание доп матрицы для работы
	T.resize(Matr[0].size());  //доп матрица Т транспонированной размерности
	for (unsigned int i = 0; i < Matr[0].size(); i++) {
		T[i].resize(Matr.size());
	}

	//транспонированно заполняем матрицу Т из исходной
	for (unsigned int i = 0; i < Matr.size(); i++) {
		for (unsigned int j = 0; j < Matr[i].size(); j++) {
			T[j][i] = Matr[i][j];
		}
	}

	//меняем размер исходной матрицы на транспонированную
	Matr.resize(T.size());
	for (unsigned int i = 0; i < T.size(); i++) {
		Matr[i].resize(T[i].size());
	}

	//записываем полученные значения в Matr
	for (unsigned int i = 0; i < T.size(); i++) {
		for (unsigned int j = 0; j < T[i].size(); j++) {
			Matr[i][j] = T[i][j];
		}
	}

}

//создание диагональной матрицы из исходной
void Matrix::Diagonal() {
	for (unsigned int i = 0; i < Matr.size(); i++) {
		for (unsigned int j = 0; j < Matr[i].size(); j++) {
			if(i != j)
				Matr[i][j] = 0.0;//оставляем только элементы на диагонали
		}
	}
}

//оператор сложения матриц(передается другая матрица в формате вектора векторов double)
//чтобы сложить с другим объектом этого класса нужно использовать на прибавляемом объекте метод Get_Matr
void Matrix::operator+= (const Matrix &Matr2) {
	if (Matr2.Matr.size() != this->Matr.size() || Matr2.Matr[0].size() != this->Matr[0].size()) { //кидаем исключение, если матрицы разного размера
		throw std::length_error("Incorrect size of Matrix you want to add");
	}
	else
	{
		for (unsigned int i = 0; i < Matr.size(); i++) {
			for (unsigned int j = 0; j < Matr[i].size(); j++) {
				Matr[i][j] = Matr[i][j] + Matr2.Matr[i][j];
			}
		}
	}
}

//оператор вычитания матриц(передается другая матрица в формате вектора векторов double)
//чтобы вычесть другой объект этого класса нужно использовать на прибавляемом объекте метод Get_Matr
void Matrix::operator-= (const Matrix &Matr2) {
	if (Matr2.Matr.size() != this->Matr.size() || Matr2.Matr[0].size() != this->Matr[0].size()) {  //кидаем исключение на разные размеры матриц
		throw std::length_error("Incorrect size of Matrix you want to add");
	}
	else
	{
		for (unsigned int i = 0; i < Matr.size(); i++) {
			for (unsigned int j = 0; j < Matr[i].size(); j++) {
				Matr[i][j] = Matr[i][j] - Matr2.Matr[i][j];
			}
		}
	}
}

//оператор вычитания матриц(передается другая матрица в формате вектора векторов double)
//чтобы вычесть другой объект этого класса нужно использовать на прибавляемом объекте метод Get_Matr
//помним, что row первой матрицы должно быть количеству col второй 
void Matrix::operator*= (const Matrix& Matr2) {
	if (this->Matr[0].size() != Matr2.Matr.size()) {
		throw std::length_error("Incorrect size of Matrix you want to multiply by. Correct: col of Matrix1 = row of Matrix2");
	}
	else
	{
		std::vector<std::vector<double>> Matr_count;//доп матрица для вычислений
		Matr_count.resize(Matr2.Matr.size());
		for (unsigned int i = 0; i < Matr2.Matr.size(); i++)
		{
			Matr_count[i].resize(Matr2.Matr[i].size());
		}
		double count = 0.0; int a = 0; //переменные для вычисления
		for (unsigned int i = 0; i < Matr2.Matr.size(); i++) {
			for (unsigned int j = 0; j < Matr2.Matr[i].size(); j++) {
				a = 0; count = 0.0;
				while (a < Matr2.Matr.size()) {
					count = count + (Matr[i][a] * Matr2.Matr[a][j]);
					a++;
				}

				Matr_count[i][j] = count;//полученное в итоге значение записываем во временную матрицу 
			}
		}

		//меняем размер исходной матрицы на вторую при необходимости
		if (Matr2.Matr[0].size() != Matr[0].size()) {
			Matr.resize(Matr2.Matr.size());
			for (unsigned int i = 0; i < Matr2.Matr.size(); i++) {
				Matr[i].resize(Matr2.Matr[i].size());
			}
		}

		//меняем исходную матрицу на получившуюся
		for (unsigned int i = 0; i < Matr_count.size(); i++) {
			for (unsigned int j = 0; j < Matr_count[i].size(); j++) {
				Matr[i][j] = Matr_count[i][j];
			}
		}
	}
}

//обратная матрица методом LU разложения
void Matrix::Reverse_Matrix() {
	if (Matr.size() != Matr[0].size()) {
		throw std::length_error("Incorrect size of Matrix you want to find determinant");
	}
	else
	{
		double pairsum, sqsum;
		unsigned int const n = Matr.size();
		std::vector<std::vector<double>> l;  l.resize(n); //создание матриц, необходимых для вычислений
		std::vector<std::vector<double>> y;  y.resize(n);
		std::vector<std::vector<double>> u;  u.resize(n);
		std::vector<std::vector<double>> x;  x.resize(n);
		for (unsigned int i = 0; i < n; i++) {
			l[i].resize(n); y[i].resize(n); u[i].resize(n); x[i].resize(n);
		}
		//заполнение матриц, необходимых для вычислений нулями
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				u[i][j] = Matr[i][j];
				l[i][j] = Matr[i][j];
				y[i][j] = 0.0;
				x[i][j] = 0.0;
			}
		}

		//первичное заполнение нулями
		int k = 0;
		while (k < n) {
			for (int i = 0; i < n; i++) {
				for (int j = n - 1 - k; j < n; j++) {
					if (j > i) {
						u[i][j] = 0.0;
					}
					if (j == i) {
						u[i][j] = 1.0;
					}
					if (j < i) {
						l[i][j] = 0.0;
					}
				}
			}
			k = k + 1;
		}


		//прямой ход
		for (int i = 0; i < n; i++) {
			l[i][0] = Matr[i][0];
		}
		for (int j = 1; j < n; j++) {
			u[0][j] = Matr[0][j] / l[0][0];
		}


		for (int k = 1; k < n; k++) {
			for (int i = k; i < n; i++) {
				l[i][k] = Matr[i][k];
				for (int m = 0; m < k; m++) {
					l[i][k] = (l[i][k] - l[i][m] * u[m][k]);
				}
			}
			if (k <= n - 2) {
				for (int j = k + 1; j < n; j++) {
					u[k][j] = Matr[k][j];
					for (int m = 0; m < k; m++) {
						u[k][j] = u[k][j] - l[k][m] * u[m][j];
					}
					u[k][j] = u[k][j] / l[k][k];
				}
			}
		}


		//вычисление Y
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j > i) {
					y[i][j] = 0.0;
				}
				else if (j == i) {
					y[i][j] = 1.0 / l[i][i];
				}
				else if (j < i) {
					y[i][j] = 0.0;
					for (int m = j; m < i; m++) {
						y[i][j] = y[i][j] - l[i][m] * y[m][j];
					}
					y[i][j] = y[i][j] / l[i][i];
				}
			}
		}


		//вычисление x
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (j < i) {
					x[i][j] = 0.0;
				}
				else if (j == i) {
					x[i][j] = 1.0;
				}
				else if (j > i) {
					x[i][j] = 0.0;
					for (int m = i + 1; m <= j; m++) {
						x[i][j] = x[i][j] - u[i][m] * x[m][j];
					}
				}
			}
		}


		//вычисл обратной матрицы
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				Matr[i][j] = 0.0;
				for (int m = 0; m < n; m++) {
					Matr[i][j] = Matr[i][j] + x[i][m] * y[m][j];
				}
			}
		}

	}
}

//определитель для квадратных матриц любого порядка 
double Matrix::Determinant() const { 
	if (Get_Row_count() != Get_Col_count()) {
		throw std::length_error("Incorrect size of Matrix you want to find determinant");
	}
	else
	{
	  //this - указатель на объект this* - ссылка на указатель на объект (РАЗИМЕНОВАНИЕ)
		return Determinant_Func(*this, Get_Row_count());
	}
}

//функция для нахождения определителя(необходима для того, чтобы рекурсивный метод класса не вызывался множество раз, а все выполнялось в отдельной функции)
double Determinant_Func(const Matrix &Matr, int rang){
	if (Matr.Get_Row_count() == 1) {
		return Matr.Get_Element(0, 0); //для матрицы 1х1
	}

	if (Matr.Get_Row_count() == 2) {
		return(Matr.Get_Element(0, 0) * Matr.Get_Element(1, 1) - Matr.Get_Element(0, 1) * Matr.Get_Element(1, 0));
	}                                   //для матрицы 2х2

	if (Matr.Get_Row_count() > 2) //для матриц большей размерности
	{
		Matrix Between(Matr.Get_Row_count(), Matr.Get_Col_count());
		double Det = 0;
		for (int i = 0; i < rang; i++)
		{
			Between = Between.Del_Row_Col(Matr, 0, i); //удаляем строки и столбца матрицы чтобы искать определитель матриц меньшего порядка
			Det = Det + pow(-1, i + 1 + 1) * Matr.Get_Element(0, i) * Determinant_Func(Between, rang - 1); //рекурсия для вычисления определителя
			Between.~Matrix(); //как бы очищаем амять после окончания работы 
		}
		return Det;
	}
}

//геттер количества строк матрицы
unsigned int Matrix::Get_Row_count() const{
	return Matr.size();
}

//геттер количества столбцов матрицы
unsigned int Matrix::Get_Col_count()const {
	return Matr[0].size();
}

//удаление строки и столбца матрицы по координатам(на выход объект с матрицей без этого столбца и строки)
Matrix Matrix::Del_Row_Col(Matrix Matr, int row, int col) {
	Matrix result(Matr.Get_Row_count() - 1, Matr.Get_Col_count() - 1);
	for (int i = 0; i < Matr.Get_Row_count(); i++)
	{
		for (int j = 0; j < Matr.Get_Col_count(); j++)
		{
			if (i < row && j < col) { result.Set_Element(i, j, Matr.Get_Element(i, j)); };
			if (i < row && j > col) { result.Set_Element(i, j - 1, Matr.Get_Element(i, j)); };
			if (i > row && j < col) { result.Set_Element(i - 1, j, Matr.Get_Element(i, j)); };
			if (i > row && j > col) { result.Set_Element(i - 1, j - 1, Matr.Get_Element(i, j)); };
		}
	}
	return result;
}


//блок с тестами методов класса матрицы
void Test() {

	//(try-catch)
	try {
		Matrix M(1, 3); //проверка создания матрицы
	}
	catch (const std::invalid_argument a) {
		cout << a.what() << endl; //вывод ошибки при необходимости
	}


	//блок assert
	Matrix M(2, 2); //создаем матрицу 2х2
	M.Fill_With(2); //заполняем двойками
	M.Output_Matrix(); //проверка вывода
	assert(M.Get_Element(0, 0) == 2 && M.Get_Element(0, 1) == 2 && M.Get_Element(1, 0) == 2 && M.Get_Element(1, 1) == 2); //проверка вывода элементов

	M.Set_Element(0, 1, 3);
	assert(M.Get_Element(0, 1) == 3); //проверка сеттера элементов

	std::vector<double> V{1, 1};
	M.Set_Str_By_Vector(0, V);
	assert(M.Get_Element(0, 0) == 1 && M.Get_Element(0, 1) == 1 && M.Get_Element(1, 0) == 2 && M.Get_Element(1, 1) == 2); //проверка сеттера строк

	M.Fill_Random(10, 20); //проверка рандома
	for (unsigned int i = 0; i < 2; i++) {
		for (unsigned int j = 0; j < 2; j++) {
			assert(M.Get_Element(0, 0) >= 10 && M.Get_Element(0, 0) <= 20 && M.Get_Element(0, 1) > 10 && M.Get_Element(0, 1) < 20 && M.Get_Element(1, 0) > 10 && M.Get_Element(1, 0) < 20 && M.Get_Element(1, 1) > 10 && M.Get_Element(1, 1) < 20);
		}
	}

	M.Fill_With(1); //заполняем матрицу единицами и умножаем на 3
	M.Matr_X_Number(3);
	assert(M.Get_Element(0, 0) == 3 && M.Get_Element(1, 0) == 3 && M.Get_Element(0, 1) == 3 && M.Get_Element(1, 1) == 3); //проверка умнож на число

	M.Diagonal();
	assert(M.Get_Element(0, 0) == 3 && M.Get_Element(1, 0) == 0 && M.Get_Element(0, 1) == 0 && M.Get_Element(1, 1) == 3);//проверка диаональной матрицы

	M.Transposition();  //транспонируем матрицу
	assert(M.Get_Element(0, 0) == 3 && M.Get_Element(1, 0) == 0 && M.Get_Element(0, 1) == 0 && M.Get_Element(1, 1) == 3);//проверка транспонированной матрицы

	Matrix N(2, 2);
	N.Fill_With(2);
	M.Fill_With(3);
	M += N;  //проверка обратной матрицы
	assert(M.Get_Element(0, 0) == 5 && M.Get_Element(1, 1) == 5 && M.Get_Element(0, 1) == 5 && M.Get_Element(1, 1) == 5); //проверка операторов
	M -= N;
	assert(M.Get_Element(0, 0) == 3 && M.Get_Element(1, 1) == 3 && M.Get_Element(0, 1) == 3 && M.Get_Element(1, 1) == 3);
	M *= N;
	assert(M.Get_Element(0, 0) == 12 && M.Get_Element(1, 1) == 12 && M.Get_Element(0, 1) == 12 && M.Get_Element(1, 1) == 12);

	assert(M.Determinant() == 0); //проверка определителя

	M.Fill_With(2); M.Set_Element(0, 0, 1);
	M.Reverse_Matrix();  //проверка обратной матрицы
	assert(M.Get_Element(0, 0) == -1 && M.Get_Element(1, 1) == -0.5 && M.Get_Element(0, 1) == 1 && M.Get_Element(1, 0) == 1);
	M.Output_Matrix();

	Matrix F(1, 3);
	F.Fill_With(3);  //проверка матрицы - строки
	assert(F.Get_Element(0, 0) == F.Get_Element(0, 1) && F.Get_Element(0, 1) == F.Get_Element(0, 2));

	//отдельная проверка определителя для матрицы 4х4
	Matrix O(4, 4);
	O.Fill_With(1);
	for (int i = 0; i < O.Get_Col_count(); i++)
		O.Set_Element(i, i, 2);
	assert(5 == O.Determinant());  //определитель матрицы одинаковых элементов = 0

	//отдельная проверка обратной матрицы для матрицы 4х4(используем ту же матрицу 'O')
	//заполним матрицу единицами, а главную диагональ двойками


	O.Reverse_Matrix();
	for (int i = 0; i < O.Get_Row_count(); i++) {
		for (int j = 0; j < O.Get_Col_count(); j++) {
			if (i != j)
				assert(O.Get_Element(i, j) - (- 0.2) < 0.01);
			else
				assert(O.Get_Element(i, j) - 0.8 < 0.01);
		}
	}
	//правильной должна быть следующая матрица
	/*0.8 - 0.2 -0.2 -0.2
	-0.2  0.8 -0.2 -0.2
	-0.2 -0.2  0.8 -0.2
	-0.2 -0.2 -0.2	0.8*/

}