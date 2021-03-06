﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// advenand.cpp
// применение операции логического И

#include <locale>
#include <iostream>
// #include <process.h> // для функции exit() не понадобился
// #include <conio.h> // для функции _getwche не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	wchar_t dir = L'a';
	int x = 10, y = 10;
	wcout << L"Нажмите Enter для выхода...\n";
	while (dir != L'\r')           // пока не будет нажата клавиша Enter
	{
		wcout << L"\nВаши координаты: " << x << L", " << y;
		wcout << L"\nВыберите направление (с, ю, в, з): ";
		dir = _getwche();          // ввод направления
		switch (dir)
		{
			case L'с': y++; break; // обновление координат
			case L'ю': y--; break;
			case L'в': x++; break;
			case L'з': x--; break;
			case L'\r': wcout << L"\nВыход...\n"; break; // нажатие Enter
			default: wcout << L"\nПопробуйте еще";       // нажатие других клавиш
		}                          // конец оператора switch
		if (x == 7 && y == 11)     // если x равно 7 и y равно 11
		{
			wcout << L"\nВаши координаты: " << x << L", " << y;
			wcout << L"\nВы нашли сокровище! Конец игры.\n";
			exit(0);               // выход из программы
		}
	}                              // конец цикла while

	return 0;
}                                  // конец функции main()