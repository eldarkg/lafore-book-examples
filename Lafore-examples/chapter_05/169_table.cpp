﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// table.cpp
// пример использования простой функции, которая печатает
// строку из 45 символов '*' (звездочка)

#include <locale>
#include <iostream>
using namespace std;

void starline(); // объявление функции (прототип)

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	starline(); // вызов функции
	wcout << L"Тип данных *             Диапазон" << endl;
	starline(); // вызов функции
	wcout << L"char       *           -128 ... 127" << endl
		  << L"short      *        -32'768 ... 32'767" << endl
		  << L"int        *        системно-зависимый" << endl
		  << L"long       * -2'147'483'648 ... 2'147'483'647" << endl;
	starline(); // вызов функции

	return 0;
}

// определение функции starline()
void starline() // заголовок функции
{
	for (int j = 0; j < 45; j++) // тело функции
		wcout << L'*';
	wcout << endl;
}