﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// comline.cpp
// демонстрация работы с аргументами командной строки

// в стандарте C++ определена функция main как точка, с которой начинается работа
// программы; wmain в стандарте C++ не определена, но она определена для программ,
// компилируемых в системах компании Microsoft, и этот вариант может принимать
// в качестве аргументов командной строки строки из широких символов wchar_t
// (main принимает в качестве аргументов командной строки только строки из символов
// типа char)

#include <locale>
#include <iostream>
using namespace std;

int wmain(int argc, wchar_t* argv[])
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	wcout << L"\nargc = " << argc << endl; // количество аргументов

	for (int j = 0; j < argc; j++)         // вывести на экран аргументы
		wcout << L"Аргумент " << j << L" = " << argv[j] << endl;
	
	return 0;
}