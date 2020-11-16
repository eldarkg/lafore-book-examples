﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// misq.cpp
// решение задачи возведения объекта класса Distance в квадрат
// с помощью добавления в класс обычного метода square
// 
// (возвращает возведенную в квадрат длину, хранящуюся в объекте класса)
// (единица измерения возвращаемого значения — квадратный фут)

#include <locale>
#include <iostream>
using namespace std;

class Distance // длина в английской системе
{
private:
	int feet;     // футы (1 фут = 12 дюймов)
	float inches; // дюймы
public:
	// конструктор без аргументов
	Distance() : feet(0), inches(0.0)
		{ }
	// конструктор с двумя аргументами
	Distance(int ft, float in) : feet(ft), inches(in)
		{ }
	void showdist() const // вывод полей на экран
		{ wcout << feet << L"\'-" << inches << L'\"'; }
	// обычный метод для возведения длины в квадрат
	float square() const; // прототип
};

// обычный метод для возведения длины в квадрат
float Distance::square() const
{
	float fltfeet = feet + inches / 12; // конвертируем объект в значение типа float,
	float feetsqrd = fltfeet * fltfeet; // возводим в квадрат
	return feetsqrd;                    // и возвращаем результат
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	Distance dist(3, 6.0); // зададим длину в 3 фута и 6 дюймов
	float sqft;            // переменная для результата возведения в квадрат

	sqft = dist.square();  // вычислим квадрат нашей длины
	
	// выведем на экран нашу длину и ее квадрат
	wcout << L"Длина = "; dist.showdist();
	wcout << L"\nКвадрат длины = " << sqft << L" кв. футов\n";

	return 0;
}