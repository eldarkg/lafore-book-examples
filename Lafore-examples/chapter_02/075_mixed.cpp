// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// mixed.cpp
// использование смешанных выражений

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int count = 7;
	float avgWeight = 155.5F;
	double totalWeight = count * avgWeight;
	wcout << L"Вес равен " << totalWeight << endl;

	return 0;
}
