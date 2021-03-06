﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 03chapter_05exercise.cpp
// При помощи цикла for изобразить на экране пирамиду из символов 'X' (кирпичики пирамиды).
// Высота пирамиды — 20 строк (рядов).

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int N;             // высота пирамиды в строках (рядах)
	// в условиях упражнения высота пирамиды фиксирована в 20 строк, но я запрашиваю у пользователя
	wcout << L"Введите высоту пирамиды в строках: "; wcin >> N;
	int S = 2 * N - 1; // ширина пирамиды в символах (количество кирпичиков в нижнем ряду)

	// построение пирамиды
	for (int i=1; i <= N; i++) // цикл строк (рядов)
	{
		// количество пробелов в ряду-строке
		// (из ширины пирамиды вычитаем количество кирпичиков пирамиды в текущем ряду)
		int P = S - (2 * i - 1);

		for (int j=1; j <= S; j++) // вывод ряда-строки
		{
			wcout << ((j <= P) ? L' ' : L'X');
		}
		wcout << endl; // переход на следующий ряд-строку
	}

	return 0;
}