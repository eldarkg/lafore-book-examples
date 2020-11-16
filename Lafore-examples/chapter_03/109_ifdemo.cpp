// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ifdemo.cpp
// применение оператора if

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int x;
	wcout << L"Введите число: ";
	wcin >> x;
	if (x > 100)
		wcout << L"Это число больше, чем 100\n";

	return 0;
}