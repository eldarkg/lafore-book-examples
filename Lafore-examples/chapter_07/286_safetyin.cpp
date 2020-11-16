﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// safetyin.cpp
// избежание переполнения буфера

#include <locale>
#include <iostream>
#include <iomanip> // для манипулятора setw
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	const int MAX = 10; // максимальный размер строки
	wchar_t str[MAX];   // сама строка

	// ввод строки
	wcout << L"Введите строку: ";
	wcin >> setw(MAX) >> str; // ввод не более чем MAX символов

	// 1. Нужно учитывать, что при вводе, к примеру, строки "Пам-парам-парам" (15 символов)
	// в массив str попадут только MAX-1 символов, а не MAX символов, как можно было бы
	// подумать, так как один элемент массива str должен быть отведен под нулевой символ,
	// означающий конец строки, то есть (при MAX = 10) в массив str попадет строка
	// "Пам-парам" (9 символов), а не "Пам-парам-" (10 символов).

	// 2. Нужно учитывать, что объект wcin с помощью оператора извлечения из потока (>>)
	// считывает строку, содержащую пробелы, только до первого пробела. Например,
	// при вводе строки "Мама мыла раму" в массив str попадут только символы
	// до первого пробела, то есть "Мама". Чтобы считать строку полностью, можно,
	// к примеру, использовать метод getline объекта wcin вместо оператора извлечения
	// из потока (>>).

	// пример:
	// wcin.getline(str, MAX); // вместо wcin >> setw(MAX) >> str;
	
	// показ результата
	wcout << L"Вы ввели: " << str << endl;

	return 0;
}