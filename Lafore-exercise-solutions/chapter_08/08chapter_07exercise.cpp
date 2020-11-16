﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 08chapter_07exercise.cpp
// Модифицировать класс fraction (обыкновенная дробь) из упражнения 11 главы 6 так, чтобы
// он использовал перегруженные операции сложения, вычитания, умножения и деления. Также
// перегрузить операции сравнения «равно» (==) и «не равно» (!=) и использовать их для
// выхода из цикла, если пользователь введет значения 0/1 и 0/1 для обеих вводимых
// дробей. Добавить возвращение преобразованной дроби в методе lowterms, чтобы можно было
// использовать его в перегруженных операциях сложения, вычитания, умножения и деления.

#include <locale>
#include <iostream>
using namespace std;

class fraction // класс, представляющий обыкновенную дробь
{
private:
	int num; // числитель
	int den; // знаменатель
public:
	// конструктор без аргументов
	fraction()
		{ }
	// конструктор с двумя аргументами
	fraction(int n, int d) : num(n), den(d)
		{ }
	// метод для получения данных класса от пользователя с клавиатуры
	void get()
	{
		wchar_t slash; // для косой черты
		wcout << L"Введите обыкновенную дробь (в формате числитель/знаменатель): ";
		wcin >> num >> slash >> den;
	}
	// константный метод выводит поля объекта класса на экран
	void display() const
	{
		wcout << L"Результат операции: " << num << L'/' << den << endl;
	}
	// перегрузка операции сложения (+) для сложения двух обыкновенных дробей
	fraction operator+ (fraction f) const
	{
		// создаем временный безымянный объект нашего класса с результатом сложения
		// заданных обыкновенных дробей, применяем к нему сокращение до несократимого вида
		// и возвращаем результат
		return fraction(num * f.den + f.num * den,
		                den * f.den).lowterms();
	}
	// перегрузка операции вычитания (-) для нахождения разности двух обыкновенных дробей
	fraction operator- (fraction f) const
	{
		return fraction(num * f.den - f.num * den,
		                den * f.den).lowterms();
	}
	// перегрузка операции умножения (*) для нахождения произведения двух обыкновенных дробей
	fraction operator* (fraction f) const
	{
		return fraction(num * f.num,
		                den * f.den).lowterms();
	}
	// перегрузка операции деления (/) для нахождения частного от деления
	// одной обыкновенной дроби на другую
	fraction operator/ (fraction f) const
	{
		return fraction(num * f.den,
		                den * f.num).lowterms();
	}
	// перегрузка операции сравнения «равно» (==) для обыкновенных дробей
	bool operator== (fraction f) const
	{
		if ((num == f.num) && (den == f.den))
			return true;
		else
			return false;
	}
	// перегрузка операции сравнения «не равно» (!=) для обыкновенных дробей
	bool operator!= (fraction f) const
	{
		if ((num == f.num) && (den == f.den))
			return false;
		else
			return true;
	}
	// метод (прототип) для сокращения дроби до несократимого вида
	// (возвращение преобразованной дроби добавлено, чтобы можно было использовать
	// этот метод в перегруженных операциях сложения, вычитания, умножения и деления)
	fraction lowterms();
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	fraction fr1, fr2, fr3; // для хранения обыкновенных дробей
	wchar_t oper;           // знак операции
	fraction fr(0, 1);      // обыкновенная дробь 0/1
	
	wcout << L"Для выхода из программы введите значение 0/1 для первой и для второй дробей.\n\n";

	do {
		fr1.get(); // получим от пользователя первую обыкновенную дробь
		wcout << L"Введите знак операции (+, -, *, /): "; wcin >> oper;
		fr2.get(); // получим от пользователя вторую обыкновенную дробь

		// если пользователь ввел в качестве и первой, и второй дроби дробь 0/1
		if ((fr1 == fr) && (fr2 == fr))
			break; // то выйти из цикла

		switch (oper)
		{
		case L'+':
			fr3 = fr1 + fr2; fr3.display(); break;
		case L'-':
			fr3 = fr1 - fr2; fr3.display(); break;
		case L'*':
			fr3 = fr1 * fr2; fr3.display(); break;
		case L'/':
			fr3 = fr1 / fr2; fr3.display(); break;
		default: wcout << L"Введен неверный знак операции! Попробуйте еще." << endl;
		}

	} while (true); // бесконечный цикл

	return 0;
}

// метод для сокращения дроби до несократимого вида
// (возвращение преобразованной дроби добавлено, чтобы можно было использовать
// этот метод в перегруженных операциях сложения, вычитания, умножения и деления)
fraction fraction::lowterms()
{
	long tnum, tden, // две временные переменные для хранения числителя и знаменателя
		 temp,       // временная переменная для хранения значения при обмене
		 gcd;        // наибольший общий делитель, который нужно найти (greatest common divisor)

	tnum = labs(num); // возьмем значения числителя и знаменателя по модулю
	tden = labs(den); // (заголовочный файл cmath для функции labs не понадобился)
	
	if (tden == 0) // проверка знаменателя на 0
		{ wcout << L"Недопустимый знаменатель!"; exit(1); }
	else if (tnum == 0) // проверка числителя на 0
		{ num = 0; den = 1; return fraction(num, den);	}

	// нахождение наибольшего общего делителя (Алгоритм Евклида)
	while (tnum != 0)
	{
		// добьемся, чтобы числитель был больше
		if (tnum < tden)                               // если числитель меньше знаменателя,
			{ temp = tnum; tnum = tden; tden = temp; } // меняем их местами
		
		tnum = tnum - tden;
	}
	gcd = tden;

	num = num / gcd; // делим числитель и знаменатель на
	den = den / gcd; // полученный наибольший общий делитель

	// (возвращение преобразованной дроби добавлено, чтобы можно было использовать
	// этот метод в перегруженных операциях сложения, вычитания, умножения и деления)
	return fraction(num, den);
}