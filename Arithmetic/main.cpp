//author Yudin D.
//задача 11г https://ivtipm.github.io/Programming/Glava01/index01.htm#z11
#include <iostream>  //cin cout
using namespace std; //пространство имен для cin cout
#include "a_and_b_count.h" //модуль
#include <cassert>//для ассертов
#include <stdlib.h>
 //author Yudin D.
int main(int argc, char* argv[]){
  double x, y, z, a1 = 1, b1 = 1;
	assert(a(0, 0, 0) == 0);
	assert(a(1, 1, 1) == 2);
  assert( 1.29845 < b(1, 1, 1) < 1.29847);

if(argv[1] == "help" || argv[4] == "help"){
  cout << "На вход программе подается 3 действительных числа, а правильный ответ 2 действительных числа a и b";
}
  //cmd arg
  if(argc == 4){
    //argv[0] - имя файла
    x = stod(argv[1]);
    y = stod(argv[2]);
    z = stod(argv[3]);
  }
  else{
    std::cout << "Введите x, y, z:" << std::endl;
        std::cin >> x >> y >> z;  //ввод значение начальных
  }  

     setlocale(LC_ALL, "Russian");  //Русская локализация
       
     std::cout << "a = " << a(x, y, z) << endl;

     std::cout << "b = " << b(x, y, z);  //вывод ответов
  }