// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 05chapter_01exercise.cpp
// написать функцию circarea, вычисляющую площадь круга

#include <locale>
#include <iostream>
using namespace std;

float circarea(float r); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	float rad; // радиус круга
	wcout << L"Введите радиус круга: ";
	wcin >> rad;
	wcout << L"Площадь круга равна " << circarea(rad) << endl;

	return 0;
}

// функция возвращает площадь круга с радиусом r
float circarea(float r)
{
	const float PI = 3.14159F; // число Пи
	return PI * r * r;
}