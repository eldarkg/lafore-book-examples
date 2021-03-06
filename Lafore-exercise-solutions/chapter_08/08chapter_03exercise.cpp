﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 08chapter_03exercise.cpp
// модифицировать класс time из 3-го упражнения 6-й главы так, чтобы вместо метода add
// можно было использовать операцию бинарного сложения (+) для сложения двух объектов
// класса time (значений или отрезков времени)

#include <locale>
#include <iostream>
using namespace std;

class time // класс, представляющий время
{
private:
	int hours;   // часы
	int minutes; // минуты
	int seconds; // секунды
public:
	// конструктор без параметров, инициализирующий поля нулями
	time() : hours(0), minutes(0), seconds(0)
		{ }
	// конструктор с параметрами, инициализирующий поля заданными значениями
	time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
		{ }
	// константный метод выводит значения полей на экран
	void display() const
		{ wcout << hours << L":" << minutes << L":" << seconds; }
	// метод, складывающий два заданных значения времени и сохраняющий результат
	// в поля объекта, от которого вызван метод
	void add(time, time); // прототип
	// оператор бинарного сложения (+) двух значений (или отрезков) времени
	time operator+ (time) const; // прототип
};

// метод класса time, складывающий два заданных значения времени и сохраняющий результат
// в поля объекта, от которого вызван метод
void time::add(time t1, time t2)
{
	long totalsecs; // для хранения времени в секундах
	// переводим заданные значения времени в секунды и складываем
	totalsecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds +
	            t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
	// переводим сумму секунд обратно в часы, минуты и секунды и сохраняем в поля текущего объекта
	hours =    totalsecs / 3600;
	minutes = (totalsecs % 3600) / 60;
	seconds = (totalsecs % 3600) % 60;
}

// оператор бинарного сложения (+) двух значений (или отрезков) времени
time time::operator+ (time t) const
{
	long totalsecs; // для хранения времени в секундах
	// переводим заданные значения времени в секунды и складываем
	totalsecs = hours * 3600 + minutes * 60 + seconds +
	            t.hours * 3600 + t.minutes * 60 + t.seconds;
	// переводим сумму секунд обратно в часы, минуты и секунды, и создаем с помощью
	// конструктора с тремя параметрами временный безымянный объект класса time,
	// который и возвращаем в качестве результата сложения
	return time( totalsecs / 3600,
	            (totalsecs % 3600) / 60,
	            (totalsecs % 3600) % 60);
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	// создание двух инициализированных константных объектов класса time
	const time t1(16, 30, 45),
	           t2( 5, 50, 20);
	// создание двух объектов класса time с полями, инициализированными нулями
	time t3, t4;

	// складываем два объекта-значения времени и присваиваем результат третьему объекту
	// (используется метод add класса time)
	t3.add(t1, t2);

	// складываем два объекта-значения времени и присваиваем результат четвертому объекту
	// (используется оператор бинарного сложения (+) класса time)
	t4 = t1 + t2;

	// выводим третий и четвертый объекты (результаты сложения) на экран
	wcout << L"Результат (метод add) : "; t3.display(); wcout << endl;
	wcout << L"Результат (оператор +): "; t4.display(); wcout << endl;

	return 0;
}