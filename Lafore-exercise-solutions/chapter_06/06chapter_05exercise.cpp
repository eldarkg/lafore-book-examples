﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 06chapter_05exercise.cpp
// создать класс date (дата), используя структуру из упражнения 5 главы 4

#include <locale>
#include <iostream>
using namespace std;

class date // класс, представляющий дату
{
private:
	int day;   // день
	int month; // месяц
	int year;  // год
public:
	// метод для получения данных класса от пользователя с клавиатуры
	void get()
	{
		wchar_t slash; // для косой черты
		wcout << L"Введите день, месяц и год через косую черту (/): ";
		wcin >> day >> slash >> month >> slash >> year;
	}
	// константный метод выводит значения полей на экран
	void display() const
		{ wcout << day << L"/" << month << L"/" << year; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	date d; // создание объекта класса date

	// получим с клавиатуры день, месяц, год
	d.get();

	// вывод даты на экран
	wcout << L"Вы ввели дату: "; d.display(); wcout << endl;

	return 0;
}