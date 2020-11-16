﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// search.cpp
// ищет последовательность, заданную одним контейнером, в другом контейнере

#include <locale>
#include <iostream>
#include <algorithm> // для алгоритма search
using namespace std;

int source[] =  { 11, 44, 33, 11, 22, 33, 11, 22, 44 }; // где ищем
int pattern[] = { 11, 22, 33 };                         // что ищем

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	int* ptr;
	
	ptr = search(source, source + 9, pattern, pattern + 3);

	if (ptr == source + 9) // если указатель указывает на позицию за
	                       // концом массива, в котором искали
		wcout << L"Совпадения не найдено\n";
	else
		wcout << L"Совпадение в позиции " << (ptr - source) << endl;
	
	return 0;
}