// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// relat.cpp
// применение операций отношения

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int numb;
	wcout << L"Введите число: ";
	wcin >> numb;
	wcout << L"numb<10 равно  " << (numb < 10)  << endl;
	wcout << L"numb>10 равно  " << (numb > 10)  << endl;
	wcout << L"numb==10 равно " << (numb == 10) << endl;

	return 0;
}