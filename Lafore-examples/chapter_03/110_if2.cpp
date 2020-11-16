// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// if2.cpp
// использование нескольких операторов в теле ветвления if

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
	{
		wcout << L"Число " << x;
		wcout << L" больше, чем 100\n";
	}

	return 0;
}