﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 12chapter_07exercise.cpp
// Имеется класс name из упражнения 6 к этой (12-й) главе. Требуется переписать
// этот класс, сделав поток статическим полем этого класса. Функциональность
// должна остаться той же. Нужно добавить статическую функцию для открытия файла
// и статическую функцию для установки файлового указателя в начало файла.
// Программу в main требуется переписать в соответствии с этими изменениями.

////// Задание к упражнению 6 главы 12 /////////////////////////////////////////
// Требуется создать класс с названием name, содержащий поля из упражнения 4
// (имя, отчество, фамилия, номер работника) к этой (12-й) главе. Также
// требуется написать к этому классу методы, один из которых записывает данные
// в конец файла, а другой — извлекает из файла данные по заданному номеру
// записи. При работе с файлами требуется использовать форматированный ввод и
// вывод. В функции main нужно дать пользователю возможность ввести несколько
// объектов нашего класса, записывая их в файл по мере ввода пользователем.
// Затем программа должна вывести на экран записи, хранящиеся в файле.
//
// Кроме требуемых в задании методов пришлось добавить методы для доступа к
// полям класса (getData, showData), чтобы соблюсти принцип сокрытия данных.
// И еще добавлен метод, возвращающий число записей в файле.
////////////////////////////////////////////////////////////////////////////////

#include <locale>
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
// #include <string> // для работы с классом wstring не понадобился
#include <codecvt>   // для работы с фасетом codecvt_utf8 локали
// #include <locale> // не понадобился
using namespace std;

class name // класс, представляющий паспорт работника
{
private:
	wstring name, middle, surname; // имя, отчество, фамилия
	unsigned long empnum;          // номер работника
	static wfstream file;          // статическое поле класса, содержащее поток,
	                               // который может использоваться и для чтения,
	                               // и для записи в файл
public:
	void getData()          // получить данные от пользователя
	{
		wcout << L"Введите номер работника: "; wcin >> empnum;
		wcout << L"Введите имя, отчество и фамилию работника: "; // через пробел
		wcin >> name >> middle >> surname;
	}
	void showData()         // вывести данные на экран
	{
		wcout << L"Работник " << empnum << L": "
			<< name << L' ' << middle << L' ' << surname;
	}
	static void diskOpen();  // открытие файла на диске для записи и чтения
	static void diskReset(); // переставить указатель в начало файла для чтения
	void diskOut();          // запись данных в файл на диске
	void diskIn(int nrec);   // чтение данных из файла на диске (по номеру записи)
	static int diskCount();  // возвращает число записей в файле
};

wfstream name::file; // определение статической переменной класса обязательно

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	name id;    // паспорт работника
	wchar_t ch; // для ответа пользователя (д/н)

	name::diskOpen(); // откроем файл для записи в конец/чтения

	// получим данные от пользователя и запишем в файл
	do {
		id.getData(); // получаем от пользователя данные работника
		id.diskOut(); // записываем полученные данные в файл на диске
		// запрашиваем пользователя об окончании ввода
		wcout << L"\nПродолжить ввод (д/н)? ";
		wcin >> ch;
	} while (ch == L'д'); // выход по 'н'

	// прочтем данные из файла и покажем их на экране
	int N = name::diskCount(); // получим количество записей в файле
	wcout << L"\nВ файле " << N << L" запись(ей)\n";
	for (int j = 1; j <= N; j++)
	{
		wcout << L"\nЗапись " << j << L"\n ";
		id.diskIn(j);      // прочитать данные работника из файла по номеру записи
		id.showData();     // вывести эти данные на экран
	}
	wcout << endl;

	return 0;
}

void name::diskOpen() // открытие файла на диске для записи и чтения
{
	// создаем константу, содержащую локаль с нужным фасетом для
	// преобразования символов при записи в файл (чтении из него) в кодировке UTF-8
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
	file.imbue(utf8_locale); // связываем наш поток с нужной локалью
	// открываем файл для записи данных в конец файла и чтения из него
	file.open(L"файл с данными.txt", ios::app | ios::out | ios::in);
	// проверка на ошибку при открытии файла
	if (!file)
	{
		wcout << L"Не получается открыть файл с данными!";
		exit(-1);
	}
}

void name::diskReset() // переставить указатель в начало файла для чтения
{
	file.seekg(0);
}

void name::diskOut() // запись данных в файл на диске
{
	file << empnum << name << L' ' << middle << L' ' << surname << L' ';
}

void name::diskIn(int nrec) // чтение данных из файла на диске (по номеру записи)
{
	file.seekg(0); // поставим указатель в начало файла для чтения
	int count = 1; // номер текущей записи в файле
	while (file >> empnum >> name >> middle >> surname
		&& count != nrec)
		count++;
}

int name::diskCount() // возвращает число записей в файле
{
	// данная функция статическая, поэтому не имеет доступа к нестатическим данным
	// класса, поэтому создадим локальные переменные для чтения данных из файла
	wstring name, middle, surname; // имя, отчество, фамилия
	unsigned long empnum;          // номер работника
	// найдем количество записей в файле и возвратим его
	file.seekg(0); // поставим указатель в начало файла для чтения
	int count = 0; // если в файле нет записей, функция возвратит нуль
	while (file >> empnum >> name >> middle >> surname)
		count++;
	file.clear(); // очистить биты ошибок (в вышеизложенном цикле установился
	              // бит ошибки конца файла; если его не сбросить, работа с файлом
	              // будет далее невозможна)
	return count;
}