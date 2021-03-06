﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// stringin.cpp
// простая строковая переменная

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	const int MAX = 80; // максимальный размер строки
	wchar_t str[MAX];   // сама строка

	// ввод строки
	wcout << L"Введите строку: ";
	wcin >> str;

	// Нужно учитывать, что объект wcin с помощью оператора извлечения из потока (>>)
	// считывает строку, содержащую пробелы, только до первого пробела. Например,
	// при вводе строки "Мама мыла раму" в массив str попадут только символы
	// до первого пробела, то есть "Мама". Чтобы считать строку полностью, можно,
	// к примеру, использовать метод getline объекта wcin вместо оператора извлечения
	// из потока (>>).

	// пример:
	// wcin.getline(str, MAX); // вместо wcin >> str;
	
	// показ результата
	wcout << L"Вы ввели: " << str << endl;

	return 0;
}