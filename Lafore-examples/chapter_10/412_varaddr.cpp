// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// varaddr.cpp
// адреса переменных

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int var1 = 11;         // определим три переменных
	int var2 = 22;         // и присвоим им некоторые значения
	int var3 = 33;

	wcout << &var1 << endl // выведем на экран адреса этих переменных
	      << &var2 << endl
	      << &var3 << endl;

	return 0;
}