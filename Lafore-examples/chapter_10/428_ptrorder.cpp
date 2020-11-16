﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptrorder.cpp
// упорядочивает по возрастанию пары чисел, передаваемых в функцию по указателю
// (на основе программы 190_reforder.cpp из главы 5 «Функции»)

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	void order(int*, int*); // прототип функции

	int n1 = 99, n2 = 11; // неупорядоченная пара
	int n3 = 22, n4 = 88; // упорядоченная пара

	order(&n1, &n2); // упорядочивание обеих пар
	order(&n3, &n4);
	
	wcout << L"n1 = " << n1 << endl; // вывод результатов на экран
	wcout << L"n2 = " << n2 << endl;
	wcout << L"n3 = " << n3 << endl;
	wcout << L"n4 = " << n4 << endl;

	return 0;
}

// функция упорядочивает два числа по возрастанию
void order(int* numb1, int* numb2)
{
	if (*numb1 > *numb2)   // если первое число больше второго,
	{
		int temp = *numb1; // то меняем их местами
		*numb1 = *numb2;
		*numb2 = temp;
	}
}