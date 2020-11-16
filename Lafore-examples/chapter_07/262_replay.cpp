// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// replay.cpp
// запоминание и вывод на экран информации, введенной пользователем

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int age[4];
	
	for (int j = 0; j < 4; j++)
	{
		wcout << L"Введите возраст: ";
		wcin >> age[j];
	}
	
	for (int j = 0; j < 4; j++)
		wcout << L"Вы ввели: " << age[j] << endl;

	return 0;
}