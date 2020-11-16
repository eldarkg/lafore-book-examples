﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 09chapter_09exercise.cpp
// Имеются классы publication (издание), book (бумажная книга) и tape (аудиокнига),
// созданные в упражнении 1 главы 9 (последние два класса — производные от первого).
// Требуется создать класс publication2, производный от publication, и включить в
// него новое поле, содержащее дату публикации издания. Классы book и tape требуется
// сделать производными от нового класса publication2. Для реализации даты
// следует взять класс date, созданный в упражнении 5 главы 6.

// Задание к упражнению 1 главы 9:
// Создать класс, представляющий издание, результат работы издательской компании.
// Создать еще два класса, производных от первого. Один из них должен представлять
// бумажную книгу, другой — аудиокнигу. Программа должна для проверки работы
// классов создавать объекты этих классов, запрашивать данные для объектов у
// пользователя и выводить данные объектов на экран.

#include <locale>
#include <iostream>
#include <string> // для работы со строками wstring
using namespace std;

class date // класс, представляющий дату (из упражнения 5 главы 6)
{
private:
	int day;   // день
	int month; // месяц
	int year;  // год
public:
	// метод для получения данных класса от пользователя с клавиатуры
	void get()
	{
		wchar_t slash; // для косой черты
		wcout << L"Введите день, месяц и год через косую черту (/): ";
		wcin >> day >> slash >> month >> slash >> year;
	}
	// константный метод выводит значения полей на экран
	void display() const
	{
		wcout << day << L"/" << month << L"/" << year;
	}
};

// класс, представляющий издание (результат работы издательской компании)
class publication
{
private:
	wstring title; // название издания
	float price;   // цена экземпляра издания
public:
	void getdata()
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
	void putdata() const
	{
		wcout << L"\n название издания: " << title;
		wcout << L"\n цена экземпляра издания: " << price << endl;
	}
};

// новый класс, представляющий издание (результат работы издательской компании)
// (производный от старого класса, представляющего издание)
class publication2 : public publication
{
private:
	date pub_date; // дата публикации издания
public:
	void getdata()
	{
		publication::getdata();
		wcout << L" введите дату публикации издания:\n  "; pub_date.get();
	}
	void putdata() const
	{
		publication::putdata();
		wcout << L" дата публикации издания: "; pub_date.display(); wcout << endl;
	}
};

// класс, представляющий бумажную книгу (производный от нового класса, представляющего издание)
class book : public publication2
{
private:
	int pages; // количество страниц в книге
public:
	void getdata()
	{
		publication2::getdata();
		wcout << L" введите количество страниц в книге: "; wcin >> pages;
	}
	void putdata() const
	{
		publication2::putdata();
		wcout << L" количество страниц в книге: " << pages << endl;
	}
};

// класс, представляющий аудиокнигу (производный от нового класса, представляющего издание)
class tape : public publication2
{
private:
	float playing_time; // время проигрывания аудиокниги в минутах
public:
	void getdata()
	{
		publication2::getdata();
		wcout << L" введите время проигрывания аудиокниги в минутах: "; wcin >> playing_time;
	}
	void putdata() const
	{
		publication2::putdata();
		wcout << L" время проигрывания аудиокниги в минутах: " << playing_time << endl;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	// создадим объекты для тестирования соответствующих классов
	book b1; // бумажная книга
	tape t1; // аудиокнига

	// получим от пользователя данные для тестируемых объектов
	wcout << L"Ввод данных опубликованной бумажной книги"; b1.getdata();
	wcout << L"\nВвод данных опубликованной аудиокниги"; t1.getdata();

	// выведем на экран данные тестируемых объектов
	wcout << L"\nДанные опубликованной бумажной книги"; b1.putdata();
	wcout << L"\nДанные опубликованной аудиокниги"; t1.putdata();

	return 0;
}