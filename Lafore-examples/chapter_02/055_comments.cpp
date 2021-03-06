﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// comments.cpp
// демонстрирует использование комментариев

#include <locale>
#include <iostream>  // директива препроцессора
using namespace std; // директива using

int main() // функция с именем main
{ // начало тела функции
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));  // оператор

	wcout << L"У каждой эпохи свой язык\n"; // оператор
	return 0;                               // оператор
} // конец тела функции
