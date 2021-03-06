﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 610_namespace3.cpp

namespace geo                     // определение пространства имен
{
	const double PI = 3.14159;    // объявление, определение
	                              // и инициализация константы

	double circumf(double radius) // объявление и определение функции
	{
		return 2 * PI * radius;
	}
}

int main()
{
	using namespace geo;
	double c = circumf(10);       // теперь всё в порядке, ошибки нет
}