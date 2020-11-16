﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 15chapter_09exercise.cpp
// Требуется написать программу, которая ищет заданную строку в контейнере,
// в котором элементы являются строками. Для этого требуется использовать
// заданное выражение, включающее алгоритм find_if, функциональный объект
// equal_to<> и функциональный адаптер (переходник) bind2nd. В итоге программа
// должна вывести на экран позицию в контейнере заданной строки (если она там
// есть).

// Отмечу, что хоть в моей среде разработки «Visual Studio Community 2017»
// функциональные адаптеры bind1st и bind2nd прекрасно работают, но со стандарта
// C++11 применение этих адаптеров не одобряется, а в стандарте C++17 они
// вообще удалены из языка C++. Вместо них предлагается использовать
// функциональный адаптер std::bind.

#include <locale>
#include <iostream>
#include <vector>     // для контейнера vector
#include <string>     // для класса wstring
#include <algorithm>  // для алгоритма find_if
#include <functional> // для функционального адаптера bind2nd
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	vector<wstring> vect;                         // создадим вектор строк
	vect.push_back(L"Колобок");                   // и заполним его строками
	vect.push_back(L"Старик");
	vect.push_back(L"Старуха");
	vect.push_back(L"Заяц");
	vect.push_back(L"Волк");
	vect.push_back(L"Медведь");
	vect.push_back(L"Хитрая лисичка");

	wcout << L"Вектор строк, которых всего " << vect.size() << L":\n";
	for (int i = 0; i < vect.size(); i++)         // выведем все строки вектора
		wcout << L" " << i << L". " << vect[i] << endl; // на экран

	wstring searchStr;                            // получим от пользователя
	wcout << L"\nВведите строку для поиска: ";    // строку для поиска
	getline(wcin, searchStr);

	vector<wstring>::iterator iter;               // создадим итератор,
	iter = find_if(vect.begin(), vect.end(),      // найдем заданную строку
		bind2nd(equal_to<wstring>(), searchStr)); // в заданном контейнере
	
	if (iter == vect.end())                       // выведем результат на экран
		wcout << L"\nЗаданная строка в векторе отсутствует.\n";
	else
		wcout << L"\nЗаданная строка в векторе найдена. "
			"Номер ее позиции: " << iter - vect.begin() << L".\n";

	return 0;
}