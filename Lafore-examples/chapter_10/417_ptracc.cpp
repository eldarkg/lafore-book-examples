﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptracc.cpp
// доступ к переменной через указатель

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int var1 = 11;              // две целочисленные переменные
	int var2 = 22;

	int* ptr;                   // указатель на целое

	ptr = &var1;                // помещаем в ptr адрес переменной var1
	wcout << *ptr << endl;      // выведем на экран содержимое переменной через указатель

	ptr = &var2;                // помещаем в ptr адрес переменной var2
	wcout << *ptr << endl;      // выведем на экран содержимое переменной через указатель

	return 0;
}