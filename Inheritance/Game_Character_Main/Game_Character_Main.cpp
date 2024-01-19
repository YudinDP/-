#include "Game_Character_Struct.h"//заголовочный файл с классом и его наследниками
#include <iostream>//ввод-вывод
using namespace std;

int main()
{   
    Test_Classes();


    Magician Harry; //класс мага
    Swordsman Zoro;

    
    Character Man2 = Harry;      //присваиваем объекту персонажа объекта мага
    Man2.Output();                          //полиморфный вывод - спокойно все выводит
    Man2.Small_Magic_Spell(Zoro);           //метод принадлежащий только магу не работает

    Character* Man = &Harry;     //присваиваем указателю на объект ссылку на объект класса мага

    Man->Output();                          //полиморфный вывод - спокойно все выводит, ему все равно на класс, так как он есть в начальном, а это главное
    Man->Small_Magic_Spell(Zoro);           //метод принадлежащий наследуемому классу так же не работает

    ((Swordsman*)Man)->Sword_Hit(Zoro);

    dynamic_cast<Magician*>(Man)->Small_Magic_Spell(Zoro);//динамическое преобразование типа - во время работы программы
    //позволяет использовать методы наследумых классов
    static_cast<Magician*>(Man)->Small_Magic_Spell(Zoro);//статичесое преобразование типа - во время компиляции todo:doc

    Zoro.Output();
}

