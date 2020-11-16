// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// inline.cpp
// применение встраиваемых (подставляемых) функций

#include <locale>
#include <iostream>
using namespace std;

// функция переводит фунты в килограммы
inline float lbstokg(float pounds)
{
	return 0.453592 * pounds;
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	float lbs;
	wcout << L"Введите вес в фунтах: "; wcin >> lbs;
	wcout << L"Вес в килограммах равен " << lbstokg(lbs) << endl;

	return 0;
}