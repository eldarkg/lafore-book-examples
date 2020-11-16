// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// divdo.cpp
// применение цикла do

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	long dividend, divisor;
	wchar_t ch;
	do                 // начало цикла do
	{                  // действия
		wcout << L"Введите делимое: "; wcin >> dividend;
		wcout << L"Введите делитель: "; wcin >> divisor;
		wcout << L"Частное равно " << dividend / divisor;
		wcout << L", остаток равен " << dividend % divisor;
		wcout << L"\nЕще раз? (y/n): ";
		wcin >> ch;
	}
	while (ch != L'n'); // условие цикла

	return 0;
}