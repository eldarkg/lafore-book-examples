// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 02chapter_01exercise.cpp
// программа, переводящая галлоны в кубические футы

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	float gallons, ft3;

	wcout << L"Введите число галлонов: "; wcin >> gallons;
	ft3 = gallons / 7.481F;
	wcout << L"В кубических футах это будет " << ft3 << endl;

	return 0;
}
