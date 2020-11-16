// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// vector.cpp
// демонстрирует применение методов вектора push_back, операции [], size

#include <locale>
#include <iostream>
#include <vector>    // для работы с контейнером vector
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	vector<int> v;                     // создаем вектор типа int

	v.push_back(10);                   // поместить значения в конец вектора
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);

	v[0] = 20;                         // заменить новыми значениями
	v[3] = 23;

	for (int j = 0; j < v.size(); j++) // вывести на экран содержимое вектора
		wcout << v[j] << L' ';         // 20 11 12 23
	wcout << endl;
	
	return 0;
}