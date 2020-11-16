﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// tablearg.cpp
// демонстрирует передачу аргументов в функцию

#include <locale>
#include <iostream>
using namespace std;

void repchar(wchar_t, int); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	repchar(L'-', 45); // вызов функции
	wcout << L"Тип данных |             Диапазон" << endl;
	repchar(L'=', 45); // вызов функции
	wcout << L"char       |           -128 ... 127" << endl
		  << L"short      |        -32'768 ... 32'767" << endl
		  << L"int        |        системно-зависимый" << endl
		  << L"long       | -2'147'483'648 ... 2'147'483'647" << endl;
	repchar(L'-', 45); // вызов функции

	return 0;
}

// определение функции repchar()
void repchar(wchar_t ch, int n) // заголовок функции
{
	for (int j = 0; j < n; j++) // тело функции
		wcout << ch;
	wcout << endl;
}