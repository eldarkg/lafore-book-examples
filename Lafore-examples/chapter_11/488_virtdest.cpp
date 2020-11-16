// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// virtdest.cpp
// тест невиртуальных и виртуальных деструкторов

#include <locale>
#include <iostream>   // для функций ввода/вывода
using namespace std;

class Base                     // базовый класс
{
public:
	~Base()                    // невиртуальный деструктор
	// virtual ~Base()         // виртуальный деструктор
		{ wcout << L"Часть объекта (базовый класс) удалена\n"; }
};

class Derv : public Base       // производный класс
{
public:
	~Derv()
		{ wcout << L"Часть объекта (производный класс) удалена\n"; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	Base* pBase = new Derv;
	delete pBase;

	return 0;
}