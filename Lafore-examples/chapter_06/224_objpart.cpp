// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// objpart.cpp
// детали изделия в качестве объектов

#include <locale>
#include <iostream>
using namespace std;

class part           // определение класса
{
private:
	int modelnumber; // номер изделия
	int partnumber;  // номер детали
	float cost;      // стоимость детали
public:
	void setpart(int mn, int pn, float c) // установка данных
	{
		modelnumber = mn;
		partnumber = pn;
		cost = c;
	}
	void showpart()  // вывод данных
	{
		wcout << L"Модель " << modelnumber;
		wcout << L", деталь " << partnumber;
		wcout << L", стоимость $" << cost << endl;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	part part1; // определение объекта класса part

	part1.setpart(6244, 373, 217.55F); // вызов метода
	part1.showpart();                  // вызов метода

	return 0;
}