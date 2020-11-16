// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// endono.cpp
// применение цикла while

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int n = 99;    // n не должна быть равна 0 перед началом цикла
	while (n != 0) // цикл, пока значение n не равно 0
		wcin >> n;  // считывание n с клавиатуры
	wcout << endl;

	return 0;
}