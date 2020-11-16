// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// partinit.cpp
// инициализация структурных переменных

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

	part part1 = { 6244, 373, 217.55F }; // инициализация переменной
	part part2;                          // объявление переменной

	// вывод полей первой переменной
	wcout << L"Модель " << part1.modelnumber;
	wcout << L", деталь " << part1.partnumber;
	wcout << L", стоимость $" << part1.cost << endl;

	part2 = part1; // присваивание структурных переменных

	// вывод полей второй переменной
	wcout << L"Модель " << part2. modelnumber;
	wcout << L", деталь " << part2.partnumber;
	wcout << L", стоимость $" << part2.cost << endl;

	return 0;
}