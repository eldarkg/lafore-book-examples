﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 04chapter_06exercise.cpp
// Определить перечисление, представляющее должность сотрудника.
// Реализовать в программе ввод должности с клавиатуры по первой букве должности
// и вывод названия должности на экран в текстовом виде.

#include <io.h> // для функции _setmode
#include <fcntl.h> // для константы _O_U16TEXT
#include <iostream>
// #include <process.h> // для функции exit() не понадобился
using namespace std;

// должность сотрудника (перечисление)
enum etype {рабочий, секретарь, менеджер, бухгалтер, директор, исследователь};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);

	etype pos; // должность сотрудника
	wchar_t ch; // вводимый с клавиатуры символ

	// получим от пользователя первую букву должности
	wcout << L"Введите первую букву должности сотрудника\n"
		  << L"(рабочий, секретарь, менеджер, бухгалтер, директор, исследователь): ";
	wcin >> ch;

	// по введенному символу присвоим соответствующее значение
	// переменной pos перечисляемого типа etype
	switch (ch)
	{
	case L'р': pos = рабочий; break;
	case L'с': pos = секретарь; break;
	case L'м': pos = менеджер; break;
	case L'б': pos = бухгалтер; break;
	case L'д': pos = директор; break;
	case L'и': pos = исследователь; break;
	default: wcout << L"Такой должности в нашей компании нет.\n"; exit(0);
	}

	// вывод значения переменной pos перечисляемого типа etype на экран в текстовом виде
	wcout << L"Полное название должности: ";
	switch (pos)
	{
	case рабочий: wcout << L"рабочий"; break;
	case секретарь: wcout << L"секретарь"; break;
	case менеджер: wcout << L"менеджер"; break;
	case бухгалтер: wcout << L"бухгалтер"; break;
	case директор: wcout << L"директор"; break;
	case исследователь: wcout << L"исследователь"; break;
	}
	wcout << endl;

	return 0;
}