﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// chcount.cpp
// подсчет числа слов и символов в строке

#include <locale>
#include <iostream>
// #include <conio.h> // для функции _getwche не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int chcount = 0;     // число непробельных символов
	int wdcount = 1;     // число пробелов
	wchar_t ch = L'a';   // ch должна иметь определенное значение
	wcout << L"Введите строку: ";
	while (ch != L'\r')  // цикл, пока не будет нажата клавиша Enter
	{
		ch = _getwche(); // считывание символа
		if (ch == L' ')  // если символ является пробелом,
			wdcount++;   // то инкрементируем число слов
		else             // в противном случае
			chcount++;   // инкрементируем число символов
	}
	// вывод результатов на экран
	wcout << L"\nCлов: " << wdcount << endl;
	wcout << L"Букв: " << (chcount-1) << endl;

	return 0;
}