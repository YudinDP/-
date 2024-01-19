#include <iostream> //ввод-вывод
#include <time.h>//для рандом чисел
#include <stdlib.h>// определяет функции srand,rand
#include <fstream>  //ввод-вывод в файл
#include <cmath>  //математика
#include <string>  //для использования строк
#include <typeinfo> //библиотека с типами данных для проверки длины массива try-catch
#include <stdexcept>  //исключения exception
using namespace std;


//ввод размера массива a(по большей части для try-catch)
int ReadArrLength() {
	int len;
	cin >> len;
	if ((len <= 0) || (len >= 32769)) {
		throw std::length_error("(len <= 0) || (len >= 32769)");
	}
	if (typeid(len) != typeid(int)) {
		throw std::invalid_argument("Длина массива некорректного типа");

	}
	return len;
}

///заполняет массив a размером n рандомными числами
void mass_fill(double* a, unsigned n) {
	srand(time(NULL));

	for (unsigned i = 0; i < n; i++) {
		a[i] = (1.0 * rand() / RAND_MAX * 200 - 100); //((rand() % 100) + rand()%100/100.0);
		//author Yudin D. 
	};
}


///сумма элементов массива a
double mass_sum(double* a, unsigned n) {
	double Msum = 0.0;
	for (unsigned i = 0; i < n; i++) {
		Msum = Msum + a[i];
	}
	return Msum;
}


///выводит массив a в текстовый файл
void file_output(double* a, unsigned n, const std::string& Fname) {
	std::ofstream out; //определение потока вывода в файл
	out.open(Fname);  //открытие файла
	if (out.is_open()) {   //проверка открытия файла
		for (unsigned i = 0; i < n; i++) {
			out << a[i] << endl;  //сам вывод
		}
	}
	out.close();  //закрываем файл ввода
}


///считает кол-во строк/элементов массива в файле
int File_str_count(const std::string& Fname) {
	int count = 0;
	std::string s;
	std::ifstream f(Fname, ios::in);
	if (f.is_open()) {
		while (!f.eof()) {
			count++;//пока файл не закончился читаем строки и увеличиваем счетчик
			getline(f, s);
		}
	}
	return count;
}


///заполняет массив a размером n из текстового файла, в который он был ранее записан
void file_input(double* a, unsigned n, const std::string& Fname) {
	std::ifstream in(Fname);
	if (in.is_open()) {
		for (unsigned i = 0; i < File_str_count(Fname); i++) {
			in >> a[i];
		}
	}
	in.close();
}
