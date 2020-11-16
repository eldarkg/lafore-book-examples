// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englobj.cpp
// длины в английской системе в качестве объектов

#include <locale>
#include <iostream>
using namespace std;

class Distance // длина в английской системе
{
private:
	int feet;     // футы
	float inches; // дюймы
public:
	void setdist(int ft, float in) // установка значений полей
	{ feet = ft; inches =in; }
	void getdist() // ввод полей с клавиатуры
	{
		wcout << L"Введите число футов: "; wcin >> feet;
		wcout << L"Введите число дюймов: "; wcin >> inches;
	}
	void showdist() // вывод полей на экран
	{ wcout << feet << L"\'-" << inches << L'\"'; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	Distance dist1, dist2; // объявление объектов, представляющих две длины

	dist1.setdist(11, 6.25); // установка значений для dist1
	dist2.getdist();         // ввод значений для dist2

	// вывод длин на экран
	wcout << L"dist1 = "; dist1.showdist();
	wcout << L"\ndist2 = "; dist2.showdist();
	wcout << endl;

	return 0;
}