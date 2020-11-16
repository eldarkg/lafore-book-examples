// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// sstrchar.cpp
// доступ к символам в строке стандартного класса string

#include <locale>
#include <iostream>
#include <string> // для стандартного класса string в языке C++
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	wchar_t charray[80];
	wstring word;
	
	// демонстрация обращения к отдельным символам в строке стандартного класса string
	wcout << L"Введите слово: ";
	wcin >> word;
	int wlen = word.length();        // длина строки в символах
	wcout << L"По одному символу: ";
	for (int j = 0; j < wlen; j++)
		wcout << word.at(j);         // тут будет проверка на выход за пределы строки
		// wcout << word[j];         // а тут проверки не будет
	
	word.copy(charray, wlen, 0);     // копируем строку word в массив charray
	                                 // wlen — кол-во символов из строки word для копирования
	                                 // 0 — индекс символа строки word, с которого копировать
	
	charray[wlen] = 0;               // строка в виде массива символов должна заканчиваться
	                                 // нулевым символом
	wcout << L"\nМассив содержит: " << charray << endl;

	return 0;
}