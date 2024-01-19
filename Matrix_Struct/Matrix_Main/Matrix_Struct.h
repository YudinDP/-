#pragma once
#include <vector>
//����� �������
class Matrix {

private:
	//����
	std::vector<std::vector <double>> Matr;//���� ������� �������������� ������ �������� ���� double

	//author Yudin

public: 
	//������ ������ 
	
	//����������� �� ��������� - ��������� ������ ������� 3x3, ���� ��� ���������� �� ���� ������� �������
	Matrix();

	//����������� � ����������� - ��������� ������ ������� rowXcol
	Matrix(unsigned int row, unsigned int col);

	//���������� 
	~Matrix();

	//������ ������� � ���� ������� �� �������� ���� double
	std::vector<std::vector<double>> Get_Matr() const;

	//����� ������� �� �����
	void Output_Matrix ()const;

	//������ �������� ������� �� ��� ������������� � ���������� ��������� � �������
	double Get_Element(unsigned int row, unsigned int col) const;

	//������ �������� ������� �� ��� ������������� � ���������� ��������� � �������
	void Set_Element(unsigned int row, unsigned int col, double param);

	//������ ������ ������� �� �� ������(�� ����� �������� double ������)
	std::vector<double> Get_Str(unsigned int row) const;

	//������ ������ ������� �� �� ������ � ������������� ������� ���� double �� �� �����������
	void Set_Str_By_Vector(unsigned int row, std::vector<double> str);

	//������ ������ ������� �� �� ������ � ������������� ������� ���� double �� �� �����������
	void Set_Str_By_Keyboard(unsigned int row);

	//���������� ������� ����� ������������ ������ number
	void Fill_With(double number);

	//���������� ������� ���������� ������� �� ��������� min - max
	void Fill_Random(double min, double max);

	//��������� ������� �� ����� number
	void Matr_X_Number(double number);

	//���������������� �������� �������(�������� ������ ��� ����������)
	void Transposition();

	//��������� ������������ ������� �� ��������
	void Diagonal();

	//�������� �������� ������(������������ ��� ������ - ������ �� �������� ���� double)
	void operator+= (const Matrix& Matr2);

	//�������� ��������� ������(������������ ��� ������ - ������ �� �������� ���� double)
	void operator-= (const Matrix &Matr2);

	//�������� ��������� ������(������������ ��� ������ - ������ �� �������� ���� double)
	void operator*= (const Matrix& Matr2);

	//���������� �������� ������� � �������� ������� ������(������ ��� ���������� ������!!!)
	void Reverse_Matrix();

	//���������� ������������ ���������� �������
	double Determinant() const;

	//������ ���������� ����� �������
	unsigned int Get_Row_count() const;

	//������ ���������� �������� �������
	unsigned int Get_Col_count() const;
	//�������� ������ � ������� ������� �� �����������(�� ����� ������ � �������� ��� ����� ������� � ������)
	Matrix Del_Row_Col(Matrix Matr2, int row, int col);
};

//������� ��� ���������� ������������(���������� ��� ����, ����� ����������� ����� ������ �� ��������� ��������� ���, � ��� ����������� � ��������� �������)
double Determinant_Func(const Matrix &Matr, int rang);

//�������� ���� ������� ������ �������
void Test();

