// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// divdo2.cpp
// применение оператора continue

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
	do	{
		wcout << L"Введите делимое: "; wcin >> dividend;
		wcout << L"Введите делитель: "; wcin >> divisor;
		if (divisor == 0) // при попытке
		{                 // деления на ноль
			wcout << L"Некорректный делитель!\n"; // вывод сообщения
			continue;                             // возврат в начало цикла
		}
		wcout << L"Частное равно " << dividend / divisor;
		wcout << L", остаток равен " << dividend % divisor;
		wcout << L"\nЕще раз? (д/н): ";
		wcin >> ch;
	} while (ch != L'н');

	return 0;
}