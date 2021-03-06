﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 11chapter_01exercise.cpp
// Заданы три класса, созданные ранее в упражнении 1 из 9-й главы:
// publication (издание) и производные от publication два класса:
// book (бумажная книга) и tape (аудиокассета с аудиокнигой).

// Требуется написать в main программу, создающую массив указателей на publication.
// При этом можно руководствоваться примером 483_virtpers.cpp этой (11-й) главы.
// Следует в цикле запрашивать у пользователя по его выбору данные бумажной книги
// или аудиокассеты с аудиокнигой, после чего использовать оператор new для выделения
// памяти соответствующему объекту. Указатель на новый объект следует сохранять в
// вышеуказанном массиве. После окончания ввода данных следует вывести все данные
// на экран.

// В исходном базовом классе publication функции getdata и putdata, естественно,
// делаем виртуальными, чтобы в main можно было использовать один и тот же вызов этих функций
// для объектов разных классов, производных от базового (полиморфизм).

#include <locale>
#include <iostream>
#include <string> // для работы со строками wstring
using namespace std;

// класс, представляющий издание (результат работы издательской компании)
class publication
{
private:
	wstring title; // название издания
	float price;   // цена экземпляра издания
public:
	virtual void getdata()
	{
		// Для получения названия издания используем функцию getline, чтобы
		// можно было вводить названия из нескольких слов (с пробелами), хотя
		// задание этого и не требует.

		// При вводе нескольких объектов функция getline при вводе второго
		// объекта будет использоваться после оператора извлечения (>>)
		// числа из потока wcin предыдущего объекта. При этом после оператора
		// извлечения (>>) в потоке wcin останется символ L'\n', из-за чего
		// не получится ввести название издания для второго объекта.
		// Чтобы избежать этой ситуации, используем функцию ws, которая удаляет
		// ведущие пробельные символы из входящего потока wcin.
		
		wcout << L"\n введите название издания: "; getline(ws(wcin), title);
		wcout << L" введите цену экземпляра издания: "; wcin >> price;
	}
	virtual void putdata() const
	{
		wcout << L"\n название издания: " << title;
		wcout << L"\n цена экземпляра издания: " << price << endl;
	}
};

// класс, представляющий бумажную книгу (производный от класса, представляющего издание)
class book : public publication
{
private:
	int pages; // количество страниц в книге
public:
	void getdata()
	{
		publication::getdata();
		wcout << L" введите количество страниц в книге: "; wcin >> pages;
	}
	void putdata() const
	{
		publication::putdata();
		wcout << L" количество страниц в книге: " << pages << endl;
	}
};

// класс, представляющий аудиокнигу (производный от класса, представляющего издание)
class tape : public publication
{
private:
	float playing_time; // время проигрывания аудиокниги в минутах
public:
	void getdata()
	{
		publication::getdata();
		wcout << L" введите время проигрывания аудиокниги в минутах: "; wcin >> playing_time;
	}
	void putdata() const
	{
		publication::putdata();
		wcout << L" время проигрывания аудиокниги в минутах: " << playing_time << endl;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	publication* pubPtr[100]; // массив указателей на объекты класса publication
	int n = 0;                // количество действительно занятых элементов массива
	wchar_t choice;           // символ, отражающий выбор пользователя

	// пользователь в цикле вводит данные изданий
	do {
		wcout << L"Вводим бумажную или аудиокнигу? (б/а): "; wcin >> choice;
		if (choice == L'б')       // поместить новый объект-бумажную книгу
			pubPtr[n] = new book; //     в массив
		else                      // поместить новый объект-аудиокассету
			pubPtr[n] = new tape; //     в массив
		wcout << L"Ввод данных издания " << n + 1 << L":";
		pubPtr[n++]->getdata();   // получим данные издания у пользователя
		wcout << L"\nВвести следующее издание? (д/н): "; wcin >> choice; wcout << endl;
	} while (choice == L'д'); // цикл выполняется, пока ответ «да»

	// выведем на экран данные введенных выше изданий
	for (int j = 0; j < n; j++)
	{
		wcout << L"Данные издания " << j + 1 << L":";
		pubPtr[j]->putdata();
	}

	return 0;
}