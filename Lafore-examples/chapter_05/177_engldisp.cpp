// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// engldisp.cpp
// передача структурных переменных в функцию

#include <locale>
#include <iostream>
using namespace std;

struct Distance // длина в английской системе
{
	int feet;
	float inches;
};

void engldisp(Distance); // объявление функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	Distance d1, d2; // определение двух длин
	
	// ввод значений полей d1
	wcout << L"Введите число футов: "; wcin >> d1.feet;
	wcout << L"Введите число дюймов: "; wcin >> d1.inches;
	// ввод значений полей d2
	wcout << L"Введите число футов: "; wcin >> d2.feet;
	wcout << L"Введите число дюймов: "; wcin >> d2.inches;
	
	wcout << L"d1 = ";
	engldisp(d1); // вывод значения d1
	wcout << L"\nd2 = ";
	engldisp(d2); // вывод значения d2
	wcout << endl;

	return 0;
}

// функция engldisp(), отображающая значения
// полей структурной переменной типа Distance
void engldisp(Distance dd) // параметр dd типа Distance
{
	wcout << dd.feet << L"\'-" << dd.inches << L"\"";
}