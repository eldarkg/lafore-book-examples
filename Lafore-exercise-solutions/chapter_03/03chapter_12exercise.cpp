﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 03chapter_12exercise.cpp
// Программа-калькулятор, выполняющая четыре арифметических действия над
// обыкновенными дробями (вида a/b)

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int a, b, c, d; // числители и знаменатели обыкновенных дробей
	wchar_t slash;  // знак дроби
	wchar_t oper;   // знак операции
	wchar_t ch;
	
	do {
		wcout << L"Введите первую дробь, знак операции и вторую дробь: ";
		wcin >> a >> slash >> b >> oper >> c >> slash >> d;

		switch (oper)
		{
		case '+':
			wcout << L"Результат операции: " << a * d + b * c << L"/" << b * d << endl;
			break;
		case '-':
			wcout << L"Результат операции: " << a * d - b * c << L"/" << b * d << endl;
			break;
		case '*':
			wcout << L"Результат операции: " << a * c << L"/" << b * d << endl;
			break;
		case '/':
			wcout << L"Результат операции: " << a * d << L"/" << b * c << endl;
			break;
		default: wcout << L"Введен неверный знак операции! Попробуйте еще." << endl;
		}

		wcout << L"Выполнить еще одну операцию (д/н) ? "; wcin >> ch;
	} while (ch != L'н');

	return 0;
}