﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// vl_app.cpp
// вычисление факториала с помощью класса verylong, который представляет
// очень длинное целое число

#include "verylong.h" // заголовочный файл с описателем класса verylong

#include <locale>

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	unsigned long numb, j;
	verylong fact = 1;           // инициализируем переменную класса verylong

	wcout << L"Введите число: ";
	wcin >> numb;                // получим от пользователя число типа long int
	
	for (j = numb; j > 0; j--)   // вычислим факториал полученного числа
		fact = fact * j;
	wcout << L"Факториал = ";
	fact.putvl();                // выведем результат
	wcout << endl;
	return 0;
}