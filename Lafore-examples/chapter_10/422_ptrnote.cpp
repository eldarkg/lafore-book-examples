// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptrnote.cpp
// доступ к элементам массива через указатель

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int intarray[5] = { 31, 54, 77, 52, 93 }; // массив из пяти целых чисел

	for (int j = 0; j < 5; j++)               // для каждого элемента массива
		wcout << *(intarray + j) << endl;     // выведем на экран его значение

	return 0;
}