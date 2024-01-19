#pragma once
#include <string>
using namespace std;
//класс игрового персонажа
class Character{
	protected:
		int HP, SP, MP; //поля: HP - Health Points - здоровье персонажа(по умолчанию 100)
						//      SP - Stamina Points - выносливость персонажа(по умолчанию 100)
						//      MP - Magic Points - мана персонажа(по умолчанию 100)
						//      Все величины целочисленные

	public:
		//конструктор - по умолчанию задает всем характеристикам значение 100 
		Character();

		//деструктор(срабатывает еще в случае, когда HP объекта <= 0)
		~Character();

		//геттер HP
		int Get_HP();

		//геттер SP
		int Get_SP();

		//геттер MP
		int Get_MP();

		//Прибавляет к HP значение change(не может быть < 0 и > 100)
		void Add_HP(int change);

		//Прибавляет к SP значение change(не может быть < 0 и > 100)
		void Add_SP(int change);

		//Прибавляет к MP значение change(не может быть < 0 и > 100)
		void Add_MP(int change);

		//выпить зелье здоровья - увеличивает поле HP на 15
		void Drink_Health_Potion();

		//выпить зелье cnfvbys - увеличивает поле HP на 25
		void Drink_Stamina_Potion();

		//выпить зелье маны - увеличивает поле MP на 20
		void Drink_Mana_Potion();

		//полиморфный вывод полей класса Character, применим к наследуемым классам
		virtual void Output() const;

		//обычный удар. Возвращаемое значение - наносимый урон(то же свойство сохраняется для других методов связанных с нанисением урона)
		void Default_Punch(Character &Enemy);

		
};


//класс мага, основанный на классе персонажа
class Magician : public Character{
	private:
		//поле - урон посоха мага
		int Magic_Stick_Damage;
	public:

		//using Character::Character;
		// 
		//конструктор класса мага
		Magician();

		//вывод полей класса Character
		void Output() const override;

		//маленькое заклинание
		void Small_Magic_Spell(Character &Enemy);

};


//класс мечника основанный на классе персонажа
class Swordsman : public Character {
	private:
		//поле - урон меча
		int Sword_Damage;
	public:

		//конструктор класса мечника
		Swordsman();

		//вывод полей класса Мечник
		void Output() const override;

		//удар мечем по передаваемому объекту класса персонажа
		void Sword_Hit(Character& Enemy);

};

//Тестирование всех методов всех классов на корректность работы
void Test_Classes();