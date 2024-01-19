#include "Game_Character_Struct.h" //заголовочный файл с классом и его наследниками
#include <iostream>
#include <cassert>
using namespace std;

//конструктор - по умолчанию задает всем характеристикам значение 100 
Character::Character() {
	HP = MP = SP = 100;
}

//деструктор(не нужен в данном случае тк отсутствует new и память отчищать не от чего)
//поэтому сделан для галочки
Character::~Character() {
	//delete HP, SP, MP;
}
//геттер HP
int Character::Get_HP() {
	return HP;
}

//геттер SP
int Character::Get_SP() {
	return SP;
}

//геттер MP
int Character::Get_MP() {
	return MP;
}

//Прибавляет к HP значение change
void Character::Add_HP(int change) {
	if (HP <= 0) {
		cout << "Enemy died" << endl;
		HP = 0;
		return;
	}
	if (HP + change > 100) {
		HP = 100;
		return;
	}

	HP = HP + change;

	if (HP <= 0) {  //проверка на хп < 0
		HP = 0;
	}
}

//Прибавляет к SP значение change
void Character::Add_SP(int change) {
	if (SP <= 0) {
		SP = 0;
	}
	if (SP + change > 100) {
		SP = 100;
		return;
	}

	SP = SP + change;

	if (SP <= 0) {  //проверка на стамину < 0
		cout << "Out of Stamina" << endl;
		SP = 0;
	}
}

//Прибавляет к MP значение change
void Character::Add_MP(int change) {
	if (MP <= 0) {
		MP = 0;
	}
	if (MP + change > 100) {
		MP = 100;
		return;
	}

	MP = MP + change;

	if (MP <= 0) {  //проверка на ману < 0
		cout << "Out of Mana" << endl;
		MP = 0;
	}
}

//выпить зелье здоровья - увеличивает поле HP на 15
void Character::Drink_Health_Potion() {
	Add_HP(15);
}

//выпить зелье стамины - увеличивает поле SP на 25
void Character::Drink_Stamina_Potion() {
	Add_SP(25);
}

//выпить зелье маны - увеличивает поле MP на 20
void Character::Drink_Mana_Potion() {
	Add_MP(20);
}

//вывод полей класса Character(не меняет полей, поэтому константный метод)
 void Character::Output() const{
	cout << endl;
	cout << "     Character:  " << endl;
	cout << "     HP:  " << HP << endl;
	cout << "     SP:  " << SP << endl;
	cout << "     MP:  " << MP << endl;
	cout << endl;
}

//обычный удар. Возвращаемое значение - наносимый урон(то же свойство сохраняется для других методов связанных с нанисением урона)
void Character::Default_Punch(Character &Enemy) {
	Enemy.Add_HP(-5);
	SP = SP - 10; //расходует 10 выносливости объекта
	if (Enemy.Get_HP() <= 0) {
		Enemy.~Character();
	}
}



//НАСЛЕДУЕМЫЙ КЛАСС МАГА//
// 
//конструктор класса мага
Magician::Magician() {
	Magic_Stick_Damage = 10;
}

//вывод полей класса Magician
void Magician::Output() const  {
	cout << endl;
	cout << "     Magician:  " << endl;
	cout << "     HP:  " << HP << endl;
	cout << "     SP:  " << SP << endl;
	cout << "     MP:  " << MP << endl;
	cout << "     Stick Damage:  " << Magic_Stick_Damage << endl;
	cout << endl;
}

//маленькое заклинаниепо по передаваемому объекту класса персонажа
void Magician::Small_Magic_Spell(Character &Enemy) {
	Enemy.Add_HP(-10 * (Magic_Stick_Damage/10));
	MP = MP - 10; //расходует 10 выносливости объекта
	if (Enemy.Get_HP() <= 0) {
		Enemy.~Character();
		cout << "Enemy died" << endl;
	}
}


//КЛАСС МЕЧНИКА//
// 
//конструктор класса мечника
Swordsman::Swordsman() {
	Sword_Damage = 10;
};

//вывод полей класса Мечник
void Swordsman::Output() const {
	cout << endl;
	cout << "     Swordsman:  " << endl;
	cout << "     HP:  " << HP << endl;
	cout << "     SP:  " << SP << endl;
	cout << "     MP:  " << MP << endl;
	cout << "     Sword Damage:  " << Sword_Damage << endl;
	cout << endl;
};

//удар мечем по передаваемому объекту класса персонажа
void Swordsman::Sword_Hit(Character& Enemy) {
	Enemy.Add_HP(-10 * (Sword_Damage / 10));
	SP = SP - 10;
};

//Тестирование всех методов всех классов на корректность работы
void Test_Classes() {
	Character Human; //создаем объект исходного класса
	assert(Human.Get_HP() == 100 && Human.Get_SP() == 100 && Human.Get_MP() == 100);
	Human.Add_HP(-50); Human.Add_SP(-50); Human.Add_MP(-50);
	assert(Human.Get_HP() == 50 && Human.Get_SP() == 50 && Human.Get_MP() == 50);
	Human.Drink_Health_Potion(); Human.Drink_Mana_Potion(); Human.Drink_Stamina_Potion();  //Тестирование общих методов(родительского класса)
	assert(Human.Get_HP() == 65 && Human.Get_SP() == 75 &&  Human.Get_MP() == 70);			//На классе Character

	Magician Wizard;  //создаем объект  класса Magician
	assert(Wizard.Get_HP() == 100 && Wizard.Get_SP() == 100 && Wizard.Get_MP() == 100);
	Wizard.Add_HP(-50); Wizard.Add_SP(-50); Wizard.Add_MP(-50);
	assert(Wizard.Get_HP() == 50 && Wizard.Get_SP() == 50 && Wizard.Get_MP() == 50);
	Wizard.Drink_Health_Potion(); Wizard.Drink_Mana_Potion(); Wizard.Drink_Stamina_Potion();  //Тестирование общих методов(родительского класса)
	assert(Wizard.Get_HP() == 65 && Wizard.Get_SP() == 75 && Wizard.Get_MP() == 70);			//На классе Magician
	
	Swordsman Warrior;
	assert(Warrior.Get_HP() == 100 && Warrior.Get_SP() == 100 && Warrior.Get_MP() == 100);
	Warrior.Add_HP(-50); Warrior.Add_SP(-50); Warrior.Add_MP(-50);
	assert(Warrior.Get_HP() == 50 && Warrior.Get_SP() == 50 && Warrior.Get_MP() == 50);
	Warrior.Drink_Health_Potion(); Warrior.Drink_Mana_Potion(); Warrior.Drink_Stamina_Potion();  //Тестирование общих методов(родительского класса)
	assert(Warrior.Get_HP() == 65 && Warrior.Get_SP() == 75 && Warrior.Get_MP() == 70);			  //На классе Swordsman
	
	Human.Add_HP(100); Human.Add_SP(100); Human.Add_MP(100);
	Wizard.Add_HP(100); Wizard.Add_SP(100); Wizard.Add_MP(100);
	Warrior.Add_HP(100); Warrior.Add_SP(100); Warrior.Add_MP(100);

	Human.Default_Punch(Wizard);
	assert(Wizard.Get_HP() == 95);
	assert(Human.Get_SP() == 90);

	Wizard.Small_Magic_Spell(Human);		//Тестирование методов, меняющих поля у других объектов(наносящих урон)
	assert(Human.Get_HP() == 90);

	Warrior.Sword_Hit(Wizard);
	assert(Wizard.Get_HP() == 85);
}