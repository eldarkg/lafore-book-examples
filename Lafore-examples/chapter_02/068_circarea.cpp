// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// circarea.cpp
// работа с переменными вещественного типа

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	float rad; // переменная вещественного типа
	const float PI = 3.14159F; // вещественная константа
	wcout << L"Введите радиус окружности: "; // запрос
	wcin >> rad; // получение радиуса
	float area = PI * rad * rad; // вычисление площади круга
	wcout << L"Площадь круга равна " << area << endl; // вывод результата на экран

	return 0;
}
