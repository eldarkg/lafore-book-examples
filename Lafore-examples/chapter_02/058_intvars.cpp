// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// intvars.cpp
// работа с переменными целого типа

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int var1;                     // описание переменной var1
	int var2;                     // описание переменной var2
	var1 = 20;                    // присвоение значения переменной var1
	var2 = var1 + 10;             // присвоение значения переменной var2
	wcout << L"var1 + 10 равно "; // вывод строки
	wcout << var2 << endl;        // вывод значения переменной var2

	return 0;
}
