// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// friclass.cpp
// дружественные классы

#include <locale>
#include <iostream>   // для функций ввода/вывода
using namespace std;

class alpha
{
private:
	int data1;
public:
	alpha() : data1(99) { } // конструктор без аргументов
	friend class beta;      // дружественный класс
};

class beta
{                           // все методы этого класса имеют доступ
public:                     // к скрытым данным класса alpha
	void func1(alpha a) { wcout << L"data1 = " << a.data1 << endl; }
	void func2(alpha a) { wcout << L"data1 = " << a.data1 << endl; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	alpha a;
	beta b;

	b.func1(a);
	b.func2(a);

	return 0;
}