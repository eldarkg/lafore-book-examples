﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// times2.cpp
// программа перевода времени из 24-часового формата в 12-часовой
// с помощью конструктора с одним аргументом в классе, реализующем 12-часовой формат

#include <locale>
#include <iostream>
#include <string> // для стандартного класса wstring для работы со строками
using namespace std;

class time24 // класс, реализующий 24-часовой формат времени
{
private:
	int hours;   // часы: от 0 до 23
	int minutes; // минуты: от 0 до 59
	int seconds; // секунды: от 0 до 59
public:
	time24() : hours(0), minutes(0), seconds(0)
		{ }
	time24(int h, int m, int s) : hours(h), minutes(m), seconds(s)
		{ }
	void display() const
	{
		if (hours < 10) wcout << L'0';
		wcout << hours << L':';
		if (minutes < 10) wcout << L'0';
		wcout << minutes << L':';
		if (seconds < 10) wcout << L'0';
		wcout << seconds;
	}
	int getHrs()  const { return hours;   }
	int getMins() const { return minutes; }
	int getSecs() const { return seconds; }
};

class time12 // класс, реализующий 12-часовой формат времени
{
private:
	bool pm;  // true = pm, false = am
	int hrs;  // часы: от 1 до 12 (нуля быть не должно)
	int mins; // минуты: от 0 до 59
public:
	// конструктор без аргументов
	time12() : pm(true), hrs(0), mins(0)
		{ }
	// конструктор с одним аргументом
	time12(time24); // прототип
	// конструктор с тремя аргументами
	time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m)
		{ }
	void display() const
	{
		wcout << hrs << L':';
		if (mins < 10) wcout << L'0';
		wcout << mins << L' ';
		wstring am_pm = pm ? L"p.m." : L"a.m.";
		wcout << am_pm;
	}
};

// конструктор с одним аргументом, который мы используем
// для преобразования объекта класса time24 в объект класса time12
time12::time12(time24 t24)
{
	// получаем количество часов из исходного объекта класса time24
	int hrs24 = t24.getHrs();
	
	// в зависимости от количества часов 24-часового времени определяем
	// значение флага "до полудня" (a.m.) или "после полудня" (p.m.)
	pm = t24.getHrs() < 12 ? false : true;

	// округлим секунды до минут, так как в 12-часовом времени секунд нет
	mins = (t24.getSecs() < 30) ? t24.getMins() : t24.getMins() + 1;
	
	// если после округления минут стало ровно 60, то
	if (mins == 60)
	{
		mins = 0; // обнуляем минуты
		++hrs24;  // увеличиваем часы на 1
		// если после увеличения часов их значение стало равно 12 или 24, то
		if (hrs24 == 12 || hrs24 == 24)
			// меняем значение pm на противоположное
			pm = (pm == true) ? false : true;
	}
	// по часам 24-часового времени определяем часы 12-часового времени
	hrs = (hrs24 < 13) ? hrs24 : hrs24 - 12;

	// значение 00 часов в 24-часовом времени равно "12 a.m." в 12-часовом времени
	if (hrs == 0)
	{
		hrs = 12;
		pm = false;
	}
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int h, m, s;

	while (true) // бесконечный цикл
	{
		// для выхода из бесконечного цикла от пользователя требуется
		// введение значения часов большего, чем 23
		
		// получим от пользователя значение времени в 24-часовом формате
		wcout << L"Введите время в 24-часовом формате:\n";
		wcout << L" Часы (от 0 до 23): "; wcin >> h;
		// если пользователь ввел значение часов больше 23, то
		if (h > 23)
			return (1); // выйти из программы
		wcout << L" Минуты: "; wcin >> m;
		wcout << L" Секунды: "; wcin >> s;

		// создадим объект 24-часового формата времени со значением,
		// полученным выше, и выведем его на экран
		time24 t24(h, m, s);
		wcout << L"Вы ввели: ";
		t24.display();

		// преобразуем введенное пользователем время в 12-часовой формат
		time12 t12 = t24;

		// выведем результат преобразования на экран
		wcout << L"\nВ 12-часовом формате: ";
		t12.display();
		wcout << L"\n\n";
	}

	// до этой строки программа не дойдет, так как определенный выше цикл
	// является бесконечным
	return 0;
}