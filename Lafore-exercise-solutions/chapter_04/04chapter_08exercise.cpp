﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 04chapter_08exercise.cpp
// Запросить у пользователя две дроби в формате "1/2" (т.е. "числитель/знаменатель")
// и выдать на экран результат сложения этих двух дробей в таком же формате,
// для хранения дробей использовать структуру

#include <locale>
#include <iostream>
using namespace std;

struct fraction // обыкновенная дробь
{
	int num; // числитель
	int den; // знаменатель
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	fraction f1, f2; // для хранения вводимых пользователем дробей
	wchar_t slash;   // для косой черты

	wcout << L"Введите первую дробь: ";
	wcin >> f1.num >> slash >> f1.den;
	wcout << L"Введите вторую дробь: ";
	wcin >> f2.num >> slash >> f2.den;
	wcout << L"Сумма этих дробей равна: "
		  << f1.num * f2.den + f2.num * f1.den << L"/" << f1.den * f2.den << endl;

	return 0;
}