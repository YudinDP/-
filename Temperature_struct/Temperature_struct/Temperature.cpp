#include "Tempareture.h" //заголовки и обьявление класса
#include <stdexcept>  //для выбрасывания исключений
#include <conio.h>  
#include <cassert>  //ассерты для проверки
#include <cmath> //математика
using namespace std;
//конструктор
//author Yudin
Temperature::Temperature(unsigned int deg_std, char meas_std) {
	degrees = deg_std; //
	measure = meas_std;//по умолчанию градусы по Цельсию(подробнее в .h)
}

///геттер градусов - базовый в Цельсиях
double Temperature::Get_degreesС() {
	if (measure == 'C') {
		return degrees;
	}
	if (measure == 'F') {
		return (degrees - 32) / 1.8;//для всегда правильного вывода из любой системы счисления
	}
	if (measure == 'K') {
		return degrees - 273.15;
	}
}

///геттер градусов - Фаррингейты
double Temperature::Get_degreesF() {
	if (measure == 'C') {
		return (degrees*1.8) + 32;
	}
	if (measure == 'F') {
		return degrees;   //для всегда правильного вывода из любой системы счисления
	}
	if (measure == 'K') {
		return (degrees * (9/5) - 459.67);
	}
}

///геттер градусов - Кельвины
double Temperature::Get_degreesK() {
	if (measure == 'C') {
		return degrees + 273.15;
	}
	if (measure == 'F') {
		return (degrees + 459.67) * 5/9;//для всегда правильного вывода из любой системы счисления
	}
	if (measure == 'K') {
		return degrees;
	}
}


///геттер меры измерения
char Temperature::Get_measure(){
	return measure;
}


///сеттер градусов в Цельсиях
void Temperature::Set_degreesС(double new_degrees) {
	if (new_degrees < -273.15)//try-catch на енправильно введенное число
		throw std::invalid_argument("Некорректный аргумент");
	degrees = new_degrees;
	measure = 'C';//даем программе понять новую меру измерения
}

///сеттер градусов в Фарренгейтах
void Temperature::Set_degreesF(double new_degrees) {
	if (new_degrees < -459.67)//try-catch на енправильно введенное число
		throw std::invalid_argument("Некорректный аргумент");
	degrees = new_degrees;
	measure = 'F';//даем программе понять новую меру измерения
}

///сеттер градусов в Кельвинах
void Temperature::Set_degreesK(double new_degrees) {
	if (new_degrees < 0)//try-catch на енправильно введенное число
		throw std::invalid_argument("Некорректный аргумент");
	degrees = new_degrees;
	measure = 'K';//даем программе понять новую меру измерения
}

///изменение градусов на change единиц
void Temperature::Add_degrees(double change) {
	if (((measure == 'C') && (degrees + change < -273.15)) || ((measure == 'F') && (degrees + change < -459.67)) || ((measure == 'K') && (degrees + change < 0)))
		throw std::invalid_argument("Некорректный аргумент");//провекрка для любой меры измерения, try-catch
	degrees = degrees + change;
}

//возвращает значение температуры вместе с нынешней мерой измерения
std::string Temperature::Output() {
	std::string measure_return = "";
	if(measure == 'C')
		measure_return = measure_return + to_string(Get_degreesС()) + " " + measure + "°";
	if (measure == 'F')
		measure_return = measure_return + to_string(Get_degreesF()) + " " + measure + "°";
	if (measure == 'K')
		measure_return = measure_return + to_string(Get_degreesK()) + " " + measure + "°";

	measure_return.erase(measure_return.length()-2, 1);		// к сожалению символ температуры кодируется 2-мя знаками, так что приходится удалять лишний
	return (measure_return);
}


//блок с assert-ами, проверяет все функции работы с классом
void Test_Temp() {
		Temperature test_degC;
		test_degC.Set_degreesС(10);
	assert(test_degC.Get_degreesС() == 10);
		test_degC.Add_degrees(10);
	assert(test_degC.Get_degreesС() == 20);
		test_degC.Add_degrees(-20);
	assert(test_degC.Get_degreesС() == 0);
	assert((test_degC.Get_degreesF() - 32) < 0.001);
	assert((test_degC.Get_degreesK() == 273.15));

		Temperature test_degF;
		test_degF.Set_degreesF(1);
	assert(test_degF.Get_degreesF() == 1);
		test_degF.Add_degrees(1);
	assert(test_degF.Get_degreesF() == 2);
		test_degF.Add_degrees(-2);
	assert(test_degF.Get_degreesF() == 0);
	assert((test_degF.Get_degreesС() + 17.78) < 0.01);
	assert((test_degF.Get_degreesK() - 255.37) < 0.01);

	Temperature test_degK;
	test_degK.Set_degreesK(1);
	assert(test_degK.Get_degreesK() == 1);
	test_degK.Add_degrees(1);
	assert(test_degK.Get_degreesK() == 2);
	test_degK.Add_degrees(-2);
	assert(test_degK.Get_degreesK() == 0);
	assert((test_degK.Get_degreesС() + 273.15) < 0.01);
	assert((test_degK.Get_degreesF() + 459.67) < 0.01);
}