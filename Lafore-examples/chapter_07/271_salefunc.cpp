﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// salefunc.cpp
// передача массива в виде параметра

#include <locale>
#include <iostream>
#include <iomanip> // для манипуляторов setiosflags, setprecision, setw
using namespace std;

const int DISTRICTS = 4; // количество отделов
const int MONTHS = 3;    // количество месяцев работы отделов

void display(double[DISTRICTS][MONTHS]); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	// создание двумерного массива и определение значений его элементов
	double sales[DISTRICTS][MONTHS] =
	{
		{  1432.07,   234.50,   654.01 },
		{   322.00, 13838.32, 17589.88 },
		{  9328.34,   934.00,  4492.30 },
		{ 12838.29,  2332.63,    32.93 }
	};

	// вывод определенных выше данных в форме таблицы
	display(sales);
	wcout << endl;

	return 0;
}

// функция для вывода на экран двумерного массива в виде таблицы
void display(double funsales[DISTRICTS][MONTHS])
{
	int d, m;
	wcout << L"                        Месяц\n";       // перед словом 24 пробела
	wcout << L"                1         2         3"; // перед цифрами 16, 9 и 9 пробелов
	for (d = 0; d < DISTRICTS; d++)
	{
		wcout << L"\nОтдел " << d + 1;
		for (m = 0; m < MONTHS; m++)
			wcout << setiosflags(ios::fixed)     // нормальный неэкспоненциальный вид
			      << setiosflags(ios::showpoint) // всегда показывать десятичную точку
			      << setprecision(2)             // два знака после запятой
			      << setw(10)                    // ширина вывода в 10 символов (всё целиком)
			      << funsales[d][m];             // само число
	}
}