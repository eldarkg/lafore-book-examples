﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 09chapter_03exercise.cpp
// Предполагается, что в программе уже есть классы publication (издание),
// book (бумажная книга) и tape (аудиокнига), взятые из упражнения 1 главы 9.
// Требуется добавить базовый класс sales, представляющий сведения о выручке
// от продаж изданий конкретного вида (бумажной книги или аудиокниги) за каждый
// из последних 3 месяцев.

// Задание для упражнения 1 главы 9:
// Создать класс, представляющий издание, результат работы издательской компании.
// Создать еще два класса, производных от первого. Один из них должен представлять
// бумажную книгу, другой — аудиокнигу. Программа должна для проверки работы
// классов создавать объекты этих классов, запрашивать данные для объектов у
// пользователя и выводить данные объектов на экран.

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

// класс, представляющий сведения о выручке от продаж за 3 месяца
class sales
{
private:
	float sales_sum[3]; // массив из трех чисел, каждое из которых представляет
	                    // собой выручку от продаж за один месяц
public:
	void getdata()
	{
		wcout << L" введите выручку от продаж за 3 месяца (через пробел): ";
		wcin >> sales_sum[0] >> sales_sum[1] >> sales_sum[2];
	}
	void putdata() const
	{
		wcout << L" выручка от продаж за последние 3 месяца: "
			<< sales_sum[0] << L" " << sales_sum[1] << L" " << sales_sum[2] << endl;
	}
};

// класс, представляющий бумажную книгу
// (производный от класса, представляющего издание, и от класса со сведениями о выручке от продаж)
class book : public publication, public sales
{
private:
	int pages; // количество страниц в книге
public:
	void getdata()
	{
		publication::getdata();
		wcout << L" введите количество страниц в книге: "; wcin >> pages;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		wcout << L" количество страниц в книге: " << pages << endl;
		sales::putdata();
	}
};

// класс, представляющий аудиокнигу
// (производный от класса, представляющего издание, и от класса со сведениями о выручке от продаж)
class tape : public publication, public sales
{
private:
	float playing_time; // время проигрывания аудиокниги в минутах
public:
	void getdata()
	{
		publication::getdata();
		wcout << L" введите время проигрывания аудиокниги в минутах: "; wcin >> playing_time;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		wcout << L" время проигрывания аудиокниги в минутах: " << playing_time << endl;
		sales::putdata();
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