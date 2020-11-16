﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// arrover1.cpp
// демонстрация создания безопасного массива, проверяющего
// свои индексы при использовании
// (используются отдельные функции для установки и получения значения)

#include <locale>
#include <iostream>
using namespace std;
// #include <process.h> // для функции exit не понадобился

const int LIMIT = 100; // размер массива

class safearray // класс, реализующий «безопасный» массив
{
private:
	int arr[LIMIT];
public:
	// установка значения элемента массива
	void putel(int n, int elvalue)
	{
		if (n < 0 || n >= LIMIT)
			{ wcout << L"Ошибочный индекс!"; exit(1); }
		arr[n] = elvalue;
	}
	// получение значения элемента массива
	int getel(int n) const
	{
		if (n < 0 || n >= LIMIT)
			{ wcout << L"Ошибочный индекс!"; exit(1); }
		return arr[n];
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	safearray sa1;

	// задаем значения элементов
	for (int j = 0; j < LIMIT; j++)
		sa1.putel(j, j * 10);

	// показываем элементы
	for (int j = 0; j < LIMIT; j++)
	{
		int temp = sa1.getel(j);
		wcout << L"Элемент " << j << L" равен " << temp << endl;
	}

	return 0;
}