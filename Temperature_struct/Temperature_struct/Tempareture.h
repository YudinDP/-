#pragma once
#include <string>
//author Yudin
using namespace std;

///класс - температура
class Temperature {
private:
	//поля
	double degrees;///поле - градусы(по умолчанию в Цельсиях)

	char measure;  ///поле - мера измерения градусов, нужна чтобы программа понимала с какой мерой измерения она сейчас работает
	// C - цельсии  F - фаренгейты  K - кельвины

public:
	//конструктор с нач.значениями
	Temperature(unsigned int = 3, char = 'C');


	///геттер градусов - базовый(в цельсиях)
	double Get_degreesС();

	///геттер градусов - Фаррингейты
	double Get_degreesF();

	///геттер градусов - Кельвины
	double Get_degreesK();

	///геттер меры измерения
	char Get_measure();

	///сеттер градусов в Цельсиях(стандартный)
	void Set_degreesС(double new_degrees);

	///сеттер градусов в Фарренгейтах
	void Set_degreesF(double new_degrees);

	///сеттер градусов в Кельвинах
	void Set_degreesK(double new_degrees);
	
	///изменение градусов на change единиц
	void Add_degrees(double change);

	//возвращает значение температуры вместе с нынешней мерой измерения
	std::string Output();
};

	//блок с assert-ами, проверяет все функции работы с классом
	void Test_Temp();