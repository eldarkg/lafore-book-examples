﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// formato.cpp
// запись форматированного вывода в файл с помощью операции вставки (<<)

// я добавил в программу две строки для работы с локалью, чтобы можно было
// записать в файл русские буквы в кодировке UTF-8

#include <locale>
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
#include <string>    // для работы с классом wstring
#include <codecvt>   // для работы с фасетом codecvt_utf8 локали
// #include <locale> // не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	// создаем константу, содержащую локаль с нужным фасетом для
	// преобразования символов при сохранении в файл в кодировке UTF-8
	const locale utf8_locale = locale(locale(),	new codecvt_utf8<wchar_t>());

	wchar_t ch = L'ы';                        // русская буква 'ы'
	int j = 77;
	double d = 6.02;
	wstring str1 = L"Kafka";                  // две строки (одна — с латинскими буквами,
	wstring str2 = L"Пруст";                  // другая — с русскими) без пробелов

	wofstream outfile(L"файл с данными.txt"); // создать объект класса wofstream
	outfile.imbue(utf8_locale);               // связываем наш поток с нужной локалью
	
	outfile << ch                             // вставить (записать) данные
	        << j
	        << L' '                           // числа разделим пробелом
	        << d
	        << str1
	        << L' '                           // строки тоже разделим пробелом
	        << str2;
	
	wcout << L"Файл записан\n";

	return 0;
}