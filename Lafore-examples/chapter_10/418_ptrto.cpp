﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptrto.cpp
// еще один пример доступа к переменной через указатель

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int var1, var2;        // две целочисленные переменные
	int* ptr;              // указатель на целое

	ptr = &var1;           // пусть ptr указывает на var1
	*ptr = 37;             // то же самое, что var1 = 37
	var2 = *ptr;           // то же самое, что var2 = var1

	wcout << var2 << endl; // убедимся, что var2 равно 37

	return 0;
}