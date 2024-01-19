#pragma once
//author Yudin D.

///считает кол-во строк/элементов массива a в файле
int File_str_count(const std::string& Fname);

///вводит длину массива a, так же нужна для try catch
int ReadArrLength();

///заполняет массив a размером n случайными числами
void mass_fill(double* a, unsigned n);

///возвращает сумму элементов массива a размером n
double mass_sum(double* a, unsigned n);

///выводит массив a в текстовый файл
void file_output(double* a, unsigned n, const std::string& Fname);

///заполняет массив a размером n из текстового файла, в который он был ранее записан
void file_input(double* a, unsigned n, const std::string& Fname);