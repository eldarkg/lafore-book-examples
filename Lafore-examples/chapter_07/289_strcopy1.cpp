﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// strcopy1.cpp
// посимвольное копирование строки с использованием цикла

#include <locale>
#include <iostream>
// #include <cstring> // для функции wcslen (длина строки в символах) не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	// исходная строка
	wchar_t str1[] = L"Маленькой елочке холодно зимой,";

	const int MAX = 80; // максимальная длина новой строки
	wchar_t str2[MAX];  // сама новая строка
	
	int j; // счетчик цикла (объявляем вне цикла,
	       // так как он будет использоваться и вне цикла)
	
	for (j = 0; j < wcslen(str1); j++) // копируем wcslen(str1) символов
		str2[j] = str1[j];             // из str1 в str2 посимвольно
	
	// Следует отметить, что функция wcslen определяет длину строки без учета
	// нулевого символа. К примеру, длина строки L"Маленькой елочке холодно зимой,"
	// составляет 31 символ. А в массиве str1 содержится 32 элемента, так как
	// последний (добавочный) элемент отведен под нулевой символ L'\0'.
	// В данном случае wcslen(str1) вернет число 31.

	str2[j] = L'\0';                   // завершаем строку нулевым символом
	
	wcout << str2 << endl;             // и выводим скопированную строку на экран

	return 0;
}