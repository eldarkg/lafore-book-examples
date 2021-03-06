﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 08chapter_10exercise.cpp
// Создать класс Polar для хранения полярных координат. Перегрузить операцию сложения (+)
// для сложения двух объектов класса Polar.

// В прямоугольной системе координат каждая точка задается двумя числами: координатой по
// горизонтальной оси (x) и координатой по вертикальной оси (y). Точка пересечения этих
// осей является началом координат. Если масштабы обеих осей одинаковы, то такая
// прямоугольная система координат называется декартовой.

// В полярной системе координат каждая точка задается двумя числами: радиусом и углом.
// Радиус всегда больше или равен нулю (это расстояние от начала системы координат (полюса)
// до точки). Угол может измеряться в градусах или радианах (это угол между горизонтальной
// линией, проведенной через полюс и линией, проведенной через полюс и нашу точку).

// Угол в классе будем хранить в радианах, так как встроенные тригонометрические и обратные
// тригонометрические функции требуют задания аргументов в радианах. Однако, при приеме
// данных от пользователя сделаем возможность задать угол и в радианах, и в градусах. Оба
// варианта должны быть доступны и при выводе данных объекта класса на экран.

#include <locale>
#include <iostream>
using namespace std;

const double PI = acos(-1.0); // число Пи (один из способов получения)

class Polar // класс для хранения полярных координат
{
private:
	double radius; // радиус (должен быть больше или равен нулю)
	double angle;  // угол (в радианах)
public:
	// конструктор без аргументов
	Polar() : radius(0.0), angle(0.0)
		{ }
	// метод для получения данных объекта от пользователя
	void get(bool in_radians)
	{
		wcout << L"   введите радиус: "; wcin >> radius;
		if (radius < 0)
		{
			wcout << L"Ошибка! Радиус не может быть меньше нуля." << endl; exit(1);
		}

		if (in_radians) // true
		{
			wcout << L"   введите угол (в радианах): "; wcin >> angle;
		}
		else // false
		{
			wcout << L"   введите угол (в градусах): "; int deg; wcin >> deg;
			angle = deg * PI / 180; // переводим в радианы
		}
	}
	// метод для отображения данных объекта на экране
	void put(bool in_radians)
	{
		wcout << L"   радиус: " << radius << endl;
		
		if (in_radians) // true
		{
			wcout << L"   угол (в радианах): " << angle << endl;
		}
		else // false
		{
			wcout << L"   угол (в градусах): " << angle * 180 / PI << endl;
		}
	}
	// перегрузка операции сложения (+) для сложения двух объектов класса
	Polar operator+ (Polar p) const; // прототип
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	Polar p1, p2, res; // точки на плоскости в полярных координатах

	wcout << L"Введите первую точку в полярных координатах:\n"; p1.get(false);
	wcout << L"Введите вторую точку в полярных координатах:\n"; p2.get(false);

	res = p1 + p2;

	wcout << L"Результат сложения:\n"; res.put(false);

	return 0;
}

// перегрузка операции сложения (+) для сложения двух объектов класса
Polar Polar::operator+ (Polar p) const
{
	// переводим полярные координаты первой точки в декартовы
	double x = radius * cos(angle);
	double y = radius * sin(angle);

	// переводим полярные координаты второй точки в декартовы
	// и складываем с декартовыми координатами первой точки
	x += p.radius * cos(p.angle);
	y += p.radius * sin(p.angle);

	// переводим декартовы координаты новой точки в полярные
	Polar res;
	res.radius = sqrt(x * x + y * y);
	res.angle = atan2(y, x);

	return res;
}