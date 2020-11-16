// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// fahren.cpp
// применение wcin и \n

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int ftemp; // температура по Фаренгейту
	wcout << L"Введите температуру по Фаренгейту: ";
	wcin >> ftemp;
	int ctemp = (ftemp - 32) * 5 / 9;
	wcout << L"Температура no Цельсию равна " << ctemp << endl;

	return 0;
}
