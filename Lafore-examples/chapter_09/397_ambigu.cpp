// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ambigu.cpp
// демонстрация неопределенности при множественном наследовании

#include <locale>
#include <iostream>
using namespace std;

class A
{
public:
	void show()
		{ wcout << L"Класс A\n"; }
};

class B
{
public:
	void show()
		{ wcout << L"Класс B\n"; }
};

class C : public A, public B
	{ };

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	C objC;         // объявляем объект класса C

	// objC.show(); // ошибка: неопределенность — программа не скомпилируется
	objC.A::show(); // так можно
	objC.B::show(); // так можно

	return 0;
}