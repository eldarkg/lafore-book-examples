﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// countpp3.cpp
// операция ++ (префиксный инкремент) с использованием недекларированной переменной

#include <locale>
#include <iostream>
using namespace std;

class Counter                 // класс, реализующий счетчик
{
private:
	unsigned int count;       // значение счетчика
public:
	Counter() : count(0)      // конструктор без аргументов
		{ }
	Counter(int c) : count(c) // конструктор с одним аргументом
		{ }
	unsigned int get_count()  // получение значения счетчика
		{ return count; }
	Counter operator++ ()     // увеличить значение счетчика
	{
		++count;
		return Counter(count);
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	// определение двух объектов класса Counter (счетчик)
	// с инициализацией (благодаря конструктору)
	Counter c1, c2;
	
	wcout << L"c1 = " << c1.get_count();   // вывод значений двух счетчиков на экран
	wcout << L"\nc2 = " << c2.get_count();

	++c1;      // увеличиваем на 1 счетчик c1
	c2 = ++c1; // c1 = 2, c2 = 2
	
	wcout << L"\nc1 = " << c1.get_count(); // вывод значений двух счетчиков на экран
	wcout << L"\nc2 = " << c2.get_count();
	wcout << endl;

	return 0;
}