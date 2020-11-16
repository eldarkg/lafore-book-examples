﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptrstr.cpp
// вывод на экран строки, определенной через указатель

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	void dispstr(wchar_t*); // прототип функции
	wchar_t str[] = L"Ленивому всегда некогда.";

	dispstr(str);           // вызов функции для вывода на экран строки

	return 0;
}

// функция для вывода на экран заданной строки
void dispstr(wchar_t* ps)
{
	while (*ps)             // пока не встретим конец строки (нулевой символ)
		wcout << *ps++;     // будем посимвольно выводить ее на экран
	wcout << endl;
}