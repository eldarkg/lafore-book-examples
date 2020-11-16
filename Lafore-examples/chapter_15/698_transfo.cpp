// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// transfo.cpp
// использует алгоритм transform для преобразования массива значений в дюймах
// в массив значений в сантиметрах

#include <locale>
#include <iostream>
#include <algorithm> // для алгоритма transform
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	// тестовый массив значений в дюймах
	double inches[] = { 3.5, 6.2, 1.0, 12.75, 4.33 };
	
	double centi[5];            // принимающий контейнер (массив)
	double in_to_cm(double);    // прототип функции
	
	// трансформируем массив inches (дюймы) в массив centi (сантиметры)
	transform(inches, inches + 5, centi, in_to_cm);

	for (int j = 0; j < 5; j++) // вывод на экран массива centi
		wcout << centi[j] << L' ';
	wcout << endl;
	
	return 0;
}

double in_to_cm(double in) // перевод дюймов в сантиметры
{
	return (in * 2.54);    // вернуть результат
}