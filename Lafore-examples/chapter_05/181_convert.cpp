// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// convert.cpp
// демонстрирует механизм возврата значения функцией

#include <locale>
#include <iostream>
using namespace std;

float lbstokg(float); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	float lbs, kgs;
	wcout << L"Введите вес в фунтах: ";
	wcin >> lbs;
	kgs = lbstokg(lbs);
	wcout << L"Вес в килограммах равен " << kgs << endl;

	return 0;
}

// функция lbstokg()
// переводит фунты в килограммы
float lbstokg(float pounds)
{
	float kilograms = 0.453592 * pounds;
	return kilograms;
}