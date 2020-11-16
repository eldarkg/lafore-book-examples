// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptrtostr.cpp
// массив указателей на строки

#include <locale>
#include <iostream>
using namespace std;

const int DAYS = 7; // количество указателей на строки в массиве

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	// массив указателей на строки
	const wchar_t* arrptrs[DAYS] =
	{
		L"Понедельник", L"Вторник", L"Среда", L"Четверг",
		L"Пятница", L"Суббота", L"Воскресенье"
	};

	// вывод всех строк на экран
	for (int j = 0; j < DAYS; j++)
		wcout << arrptrs[j] << endl;

	return 0;
}