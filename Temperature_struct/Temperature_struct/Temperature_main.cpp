//пример 1
//нужно ввести информацию о 23 градусах по цельсию, уменьшить температуру на 296.15 и вывести это в Кельвинах
//author Yudin

//пример 2
//ввести 0 градусов по кельвину, прибавить 10, вывести как Фаренгейты и как Цельсии

//пример 3
//создать массив из 3-х объектов и занести в них значение (их номера)температуры по цельсию после чего прибавить к каждому (их номер) градусов

//пример 4
//создать динамический объект, задать ему 0 градусов по цельсию, затем прибавить 10 и вывести

//пример 5
//создать массив из 3-х динамических объектов и занести в них значение (их номера)температуры по цельсию после чего прибавить к каждому (их номер) градусов

//пример 6
//создать объект, задать ему 10.32 градусов по цельцию и записать его в файл


#include "Tempareture.h"  //модуль с классом
#include <iostream>//ввод вывод
#include <string>
#include <fstream>  //ввод-вывод в файл

using namespace std;

int main(int argc, char* argv[])
{
    Test_Temp();//функция проверяющая корректную работу всех методов класса
    
    setlocale(0, "Russian");
    

    //пример 1
    Temperature deg; //переменная вбстрактного типа
    deg.Set_degreesС(23);//вводим температуру в цельсиях

    deg.Add_degrees(-296.15);//уменьшаем на 296.15

    cout << "Correct: 0" << endl;
    cout << "Ex.1 Temp:  " << deg.Get_degreesK() << endl << endl << endl; //выводим в кельвинах, правильный ответ - 0


    //пример 2 
    deg.Set_degreesK(0);//вводим 0 в Кельвинах

    deg.Add_degrees(10);//прибавляем 10
    cout << "Correct: -449.67    -263.15" << endl;
    cout << "Ex.2 Temp:  " << deg.Get_degreesF() << endl;
    cout << "Ex.2 Temp:  " << deg.Get_degreesС() << endl;  //вывод в Фаренгейтах и Цельсиях

    cout << endl << endl;


    //пример 3
    Temperature mas_deg[3];//массив объектов

    cout << "Examp 3  Correct: 0 2 4" << endl;
    for (int i = 0; i < 3; i++) {
        mas_deg[i].Set_degreesС(i);//заполняем объекты значениями
        mas_deg[i].Add_degrees(i);//добавляем значения к имеющимся
        cout << mas_deg[i].Output() << "    ";  //выводим на экран
    }
    cout << endl << endl << endl;


    //пример 4
    cout << "Examp 4  Correct: 10" << endl;
    //dyn от слова dynamic
    Temperature* dyn_deg = new Temperature;//создание динамического объекта можно писать = new temperature
    dyn_deg->Set_degreesС(0);   // знак -> равносилен знаку . для статичных объектов
    dyn_deg->Add_degrees(10);
    cout << dyn_deg->Output() << endl;
    cout << endl << endl;
    delete dyn_deg;  //освобождаеи память по окончанию работы


    //пример 5
    cout << "Examp 5  Correct: 4 4 4" << endl;
    Temperature* mas_dyn[3]; //массив из указателей
    for (int i = 0; i < 3; i++) {
        mas_dyn[i] =  new Temperature;
        mas_dyn[i]->Set_degreesС(2);
        mas_dyn[i]->Add_degrees(2);
        cout << mas_dyn[i]->Output() << endl;
    }
    cout << endl;


    //пример 6
    cout << "Examp 6 Correct: 10.32  C" << endl;
    //передача имени файла для записи объекта (имя файла Temp)
    std::string Filename = argv[1];//записали в имя файла cmd arg
    Temperature tempFoFile;
    tempFoFile.Set_degreesС(10.32);
    double transit; //переменная для ввода данных температуры
    char trans;

    //вывод
    std::ofstream out; //определение потока вывода в файл
    out.open(Filename); //открытие файла
    if (out.is_open()) {  //проверка открытия
        out << tempFoFile.Get_degreesС() << endl; //вывод объекта
        out << tempFoFile.Get_measure(); //вывод меры измерения
    }
    out.close();//закрытие файла

    //ввод
    std::ifstream in; //поток на ввод
    in.open(Filename); //открытие файла
    if (in.is_open()) { //проверка открытия файла
        in >> transit; //запись температуры в переменную
        in >> trans;
       tempFoFile.Set_degreesС(transit); //запись в поле объекта
        
    }
    in.close(); //закрыли в файл
    cout << tempFoFile.Get_degreesС() << "  " << trans;//выводим для проверки

}

