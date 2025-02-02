#include <iostream> //����-�����
#include <time.h>//��� ������ �����
#include <stdlib.h>// ���������� ������� srand,rand
#include <fstream>  //����-����� � ����
#include <cmath>  //����������
#include <string>  //��� ������������� �����
#include <typeinfo> //���������� � ������ ������ ��� �������� ����� ������� try-catch
#include <stdexcept>  //���������� exception
using namespace std;


//���� ������� ������� a(�� ������� ����� ��� try-catch)
int ReadArrLength() {
	int len;
	cin >> len;
	if ((len <= 0) || (len >= 32769)) {
		throw std::length_error("(len <= 0) || (len >= 32769)");
	}
	if (typeid(len) != typeid(int)) {
		throw std::invalid_argument("����� ������� ������������� ����");

	}
	return len;
}

///��������� ������ a �������� n ���������� �������
void mass_fill(double* a, unsigned n) {
	srand(time(NULL));

	for (unsigned i = 0; i < n; i++) {
		a[i] = (1.0 * rand() / RAND_MAX * 200 - 100); //((rand() % 100) + rand()%100/100.0);
		//author Yudin D. 
	};
}


///����� ��������� ������� a
double mass_sum(double* a, unsigned n) {
	double Msum = 0.0;
	for (unsigned i = 0; i < n; i++) {
		Msum = Msum + a[i];
	}
	return Msum;
}


///������� ������ a � ��������� ����
void file_output(double* a, unsigned n, const std::string& Fname) {
	std::ofstream out; //����������� ������ ������ � ����
	out.open(Fname);  //�������� �����
	if (out.is_open()) {   //�������� �������� �����
		for (unsigned i = 0; i < n; i++) {
			out << a[i] << endl;  //��� �����
		}
	}
	out.close();  //��������� ���� �����
}


///������� ���-�� �����/��������� ������� � �����
int File_str_count(const std::string& Fname) {
	int count = 0;
	std::string s;
	std::ifstream f(Fname, ios::in);
	if (f.is_open()) {
		while (!f.eof()) {
			count++;//���� ���� �� ���������� ������ ������ � ����������� �������
			getline(f, s);
		}
	}
	return count;
}


///��������� ������ a �������� n �� ���������� �����, � ������� �� ��� ����� �������
void file_input(double* a, unsigned n, const std::string& Fname) {
	std::ifstream in(Fname);
	if (in.is_open()) {
		for (unsigned i = 0; i < File_str_count(Fname); i++) {
			in >> a[i];
		}
	}
	in.close();
}
