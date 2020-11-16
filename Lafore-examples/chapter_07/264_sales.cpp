// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// sales.cpp
// определение среднего дневного объема продаж

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	const int SIZE = 6;
	double sales[SIZE];
	
	wcout << L"Введите объем продаж (руб.) за каждый из шести дней:\n";
	for (int j = 0; j < SIZE; j++)
		wcin >> sales[j];
	
	double total = 0;
	for (int j = 0; j < SIZE; j++)
		total += sales[j];
	
	double average = total / SIZE;
	
	wcout << L"Средний объем: " << average << endl;

	return 0;
}