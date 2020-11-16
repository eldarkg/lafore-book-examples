// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// sort.cpp
// сортирует массив целых чисел

#include <locale>
#include <iostream>
#include <algorithm> // для алгоритма sort
using namespace std;

// тестовый массив целых чисел
int arr[] = { 45, 2, 22, -17, 0, -30, 25, 55 };

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	sort(arr, arr + 8);          // сортировка

	for (int j = 0; j < 8; j++)  // вывести отсортированный массив на экран
		wcout << arr[j] << L' ';
	wcout << endl;
	
	return 0;
}