#pragma once
//author Yudin D.

///������� ���-�� �����/��������� ������� a � �����
int File_str_count(const std::string& Fname);

///������ ����� ������� a, ��� �� ����� ��� try catch
int ReadArrLength();

///��������� ������ a �������� n ���������� �������
void mass_fill(double* a, unsigned n);

///���������� ����� ��������� ������� a �������� n
double mass_sum(double* a, unsigned n);

///������� ������ a � ��������� ����
void file_output(double* a, unsigned n, const std::string& Fname);

///��������� ������ a �������� n �� ���������� �����, � ������� �� ��� ����� �������
void file_input(double* a, unsigned n, const std::string& Fname);