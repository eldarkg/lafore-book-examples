﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 04chapter_09exercise.cpp
// Создать структуру, представляющую время, с тремя полями: часы, минуты и секунды.
// Запросить у пользователя время, сохранить в структурную переменную, подсчитать
// и вывести это время в секундах

#include <locale>
#include <iostream>
using namespace std;

struct time // время
{
	int hours;   // часы
	int minutes; // минуты
	int seconds; // секунды
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	time t;         // для хранения времени в часах, минутах и секундах
	long totalsecs; // для хранения времени в секундах

	wcout << L"Введите время в часах, минутах и секундах (через пробел): ";
	wcin >> t.hours >> t.minutes >> t.seconds;

	totalsecs = t.hours * 3600 + t.minutes * 60 + t.seconds;
	wcout << L"Секунд во введенном времени: " << totalsecs << endl;

	return 0;
}