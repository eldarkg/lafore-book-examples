// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 02chapter_03exercise.cpp
// вывести три числа: числовую константу и два результата заданных операций

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int number = 10;

	wcout << 10 << endl; // вывод числовой константы
	number += 10;
	wcout << number << endl;   // вывод переменной после арифметического сложения с присваиванием
	wcout << --number << endl; // вывод переменной после операции декремента

	return 0;
}
