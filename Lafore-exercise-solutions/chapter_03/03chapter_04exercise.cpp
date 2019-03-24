﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 03chapter_04exercise.cpp
// Программа-калькулятор, выполняющая 4 основных арифметических операции.
// Программа должна запрашивать у пользователя первый операнд, знак операции и второй операнд.
// Для хранения операндов использовать переменные вещественного типа.
// Выбор операции осуществить с помощью оператора switch.
// Результат вычисления вывести на экран.

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	wchar_t ch, z; // вводимый пользователем символ, знак операции
	double n1, n2, n; // первый операнд, второй операнд, результат вычисления
	do {
		wcout << L"Введите первый операнд, операцию и второй операнд: ";
		wcin >> n1 >> z >> n2;
		switch (z)
		{
		case L'+': n = n1 + n2; break;
		case L'-': n = n1 - n2; break;
		case L'/': n = n1 / n2; break;
		case L'*': n = n1 * n2; break;
		default:   n = 0;
		}
		wcout << L"Результат равен: " << n << endl;
		wcout << L"Выполнить еще одну операцию? (д/н): "; wcin >> ch;
	} while (ch != L'н');

	return 0;
}