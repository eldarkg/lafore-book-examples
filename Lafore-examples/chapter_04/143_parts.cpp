// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// parts.cpp
// структура для хранения информации о деталях изделий

#include <locale>
#include <iostream>
using namespace std;

struct part          // объявление структуры
{
	int modelnumber; // номер модели изделия
	int partnumber;  // номер детали
	float cost;      // стоимость детали
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	part part1;               // определение структурной переменной
	
	part1.modelnumber = 6244; // инициализация полей
	part1.partnumber = 373;   // переменной part1
	part1.cost = 217.55F;

	// вывод значений полей на экран
	wcout << L"Модель " << part1.modelnumber;
	wcout << L", деталь " << part1.partnumber;
	wcout << L", стоимость $" << part1.cost << endl;

	return 0;
}