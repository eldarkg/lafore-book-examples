﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// charvars.cpp
// применение символьных констант

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	wchar_t charvar1 = L'А';  // символьная переменная со значением 'А' (русская буква)
	wchar_t charvar2 = L'\t'; // символьная переменная со значением символа табуляции
	wcout << charvar1;        // вывод переменной на экран
	wcout << charvar2;        // вывод переменной на экран
	charvar1 = L'Б';          // присваивание константного значения (русская буква) символьной переменной
	wcout << charvar1;        // вывод переменной на экран
	wcout << L'\n';           // переход на следующую строку

	return 0;
}
