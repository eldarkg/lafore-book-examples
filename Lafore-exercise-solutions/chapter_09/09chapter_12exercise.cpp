﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 09chapter_12exercise.cpp
// Имеется класс sterling, созданный в упражнении 11 главы 8 (на базе структуры
// из упражнения 11 главы 5 и еще ранее из упражнения 10 главы 4).

// Информация из упражнения 11 главы 8:
// В старой английской системе денежные суммы представлялись фунтами стерлингов,
// шиллингами и пенсами (1 фунт = 20 шиллингов = 240 пенсов). Во второй половине
// XX века были введены десятичные фунты (1 фунт = 100 новых пенсов). Фунты в
// старой и новой системах равны друг другу. Для представления денежной суммы в
// старой английской системе использовалось выражение вида "£9.19.11" (фунты,
// шиллинги и пенсы через точку).

// Требуется создать новый класс sterfrac, производный от sterling. Этот новый класс
// будет представлять денежные суммы в старой английской системе через фунты,
// шиллинги и пенсы, как и раньше, только теперь требуется добавить возможность
// работы с частями пенсов (или "пенни"): полуфартингом, фартингом, полупенни и т.д.,
// так как существовали и такие монеты. То есть в новом классе добавляем новое поле
// eighths типа int, которое будет содержать количество 1/8 пенни, так как все монеты
// мельче пенни можно выразить в количестве 1/8 пенни. Например, полуфартинг —
// это 1/8 пенни, фартинг — это 2/8 (или 1/4) пенни и т.д. Для представления таких
// сумм будем использовать выражение вида "£9.19.11-1/4" (после дефиса указывается
// количество 1/8 пенни).

// Кроме этого, новый класс sterfrac должен содержать перегруженные методы для
// выполнения четырех основных арифметических действий над такими денежными суммами.
// Также следует перегрузить методы для ввода пользователем и вывода на экран таких
// денежных сумм.

#include <locale>
#include <iostream>
#include <iomanip> // для манипулятора setprecision
using namespace std;

class sterling // класс, представляющий денежную сумму в старой английской системе
{
protected:         // (изменил с private на protected для доступа из производного класса)
	long pounds;   // фунты (1 фунт = 20 шиллингов = 240 пенсов)
	int shillings; // шиллинги (1 шиллинг = 12 пенсов)
	int pences;    // пенсы
public:
	// конструктор без аргументов
	sterling() : pounds(0), shillings(0), pences(0)
		{ }
	// конструктор с одним аргументом
	// (для преобразования десятичных фунтов в денежную сумму в старой системе)
	sterling(double df)
	{
		// в этих формулах используется то обстоятельство, что при присвоении
		// целочисленной переменной вещественного значения дробная часть отбрасывается
		pounds = df;
		shillings = (df - pounds) * 20;
		// в случае пенсов необходимо округление до ближайшего целого (функция round),
		// а не отбрасывание дробной части
		pences = round(((df - pounds) * 20 - shillings) * 12);
	}
	// конструктор с тремя аргументами
	sterling(long ps, int s, int p) : pounds(ps), shillings(s), pences(p)
		{ }
	// метод для получения от пользователя денежной суммы в старой системе
	// в формате "£9.19.11"
	void getSterling()
	{
		// чтобы символ фунта отобразился в консоли, шрифт в консоли должен быть юникодным,
		// например, шрифт "Lucida Console" или "Consolas"

		wchar_t separator; // для точки, разделяющей фунты, шиллинги и пенсы
		wcout << L"Введите сумму (фунты, шиллинги и пенсы через точку): £";
		wcin >> pounds >> separator >> shillings >> separator >> pences;
	}
	// метод для вывода денежной суммы в старой системе на экран
	// в формате "£9.19.11"
	void putSterling() const
	{
		// чтобы символ фунта отобразился в консоли, шрифт в консоли должен быть юникодным,
		// например, шрифт "Lucida Console" или "Consolas"

		wcout << L"£" << pounds << L"." << shillings << L"." << pences;
	}
	// операция преобразования объекта класса (денежной суммы в старой системе)
	// в число типа double (денежную сумму в десятичных фунтах)
	operator double() const
	{
		// так как в этом арифметическом выражении используются вещественные числа
		// (по умолчанию это тип double), то результат выражения тоже будет приведен
		// к вещественному типу (double в данном случае)
		return (pounds + shillings / 20.0 + pences / 240.0);
	}
	// перегрузка операции сложения (+) для сложения двух объектов класса
	// (результат тоже будет объектом класса)
	sterling operator+ (sterling s) const
	{
		// 1) sterling(pounds, shillings, pences) — создание безымянного объекта класса
		// с помощью конструктора с тремя аргументами. Обозначим это выражение как s1

		// 2) double(s1) и double(s) — создание безымянных переменных типа double с
		// помощью операции преобразования объекта класса в число типа double,
		// определенной выше (сумма из старой системы преобразуется в десятичные фунты)

		// 3) sterling(double(s1) + double(s)) — создание безымянного объекта класса
		// с помощью конструктора с одним аргументом (из десятичных фунтов в сумму
		// в старой системе)

		return sterling(double(sterling(pounds, shillings, pences)) + double(s));
	}
	// перегрузка операции вычитания (-) для нахождения разности двух объектов класса
	// (результат тоже будет объектом класса)
	sterling operator- (sterling s) const
	{
		return sterling(double(sterling(pounds, shillings, pences)) - double(s));
	}
	// перегрузка операции умножения (*) для нахождения произведения объекта класса
	// и числа типа double (результатом будет объект класса)
	sterling operator* (double n) const
	{
		return sterling(double(sterling(pounds, shillings, pences)) * n);
	}
	// перегрузка операции деления (/) для нахождения частного от деления объекта
	// класса на другой объект класса (результатом будет число типа double)
	double operator/ (sterling s) const
	{
		return (double(sterling(pounds, shillings, pences)) / double(s));
	}
	// перегрузка операции деления (/) для нахождения частного от деления объекта
	// класса на число типа double (результатом будет объект класса)
	sterling operator/ (double n) const
	{
		return sterling(double(sterling(pounds, shillings, pences)) / n);
	}
};

// новый класс (производный от оригинального класса sterling), добавляющий возможность
// работы с монетами, представляющими части от пенни (полуфартинг, фартинг, полупенни и т.д.)
class sterfrac : public sterling
{
private:
	int eighths; // количество восьмушек (1/8) пенни

	// возможные значения:
	// 0                                    (0/8 пенни)
	// 1 — полуфартинг                      (1/8 пенни)
	// 2 — фартинг                          (2/8 пенни или 1/4 пенни)
	// 3 — фартинг и полуфартинг            (3/8 пенни)
	// 4 — полупенни                        (4/8 пенни или 1/2 пенни)
	// 5 — полупенни и полуфартинг          (5/8 пенни)
	// 6 — полупенни и фартинг              (6/8 пенни или 3/4 пенни)
	// 7 — полупенни, фартинг и полуфартинг (7/8 пенни)

public:
	// конструктор без аргументов
	sterfrac() : sterling(), eighths(0)
		{ }
	// конструктор с одним аргументом
	// (для преобразования десятичных фунтов в денежную сумму в старой системе)
	sterfrac(double df)
	{
		// в этих формулах используется то обстоятельство, что при присвоении
		// целочисленной переменной вещественного значения дробная часть отбрасывается
		pounds     = df;
		shillings = (df - pounds) * 20;
		pences   = ((df - pounds) * 20 - shillings) * 12;
		// round — округление до ближайшего целого, а не отбрасывание дробной части
		eighths = round((((df - pounds) * 20 - shillings) * 12 - pences) * 8);
	}
	// конструктор с четырьмя аргументами
	sterfrac(long ps, int s, int p, int e) : sterling(ps, s, p), eighths(e)
		{ }
	// метод для получения от пользователя денежной суммы в старой системе
	// в формате "£9.19.11-1/4"
	void getSterling()
	{
		// чтобы символ фунта отобразился в консоли, шрифт в консоли должен быть юникодным,
		// например, шрифт "Lucida Console" или "Consolas"

		wchar_t separator; // для точки, разделяющей фунты, шиллинги и пенсы;
		                   // а также для дефиса и косой черты (/)
		int num, den;      // числитель и знаменатель
		wcout << L"Введите сумму в формате '£9.19.11-1/4': £";
		wcin >> pounds >> separator >> shillings >> separator >> pences
			>> separator >> num >> separator >> den;
		// предполагаем, что пользователь вводит только правильные дроби, причем
		// знаменатель может быть равным только 2, 4 или 8, а числитель равен
		// значениям от 0 до 7
		if (den == 2) num = num * 4;
		if (den == 4) num = num * 2;
		eighths = num;
	}
	// метод для вывода денежной суммы в старой системе на экран
	// в формате "£9.19.11-1/4"
	void putSterling() const
	{
		sterling::putSterling();
		wcout << L"-";
		switch (eighths)
		{
		case 2: wcout << L"1/4"; break;
		case 4: wcout << L"1/2"; break;
		case 6: wcout << L"3/4"; break;
		default: wcout << eighths << L"/8";
		}
	}
	// операция преобразования объекта класса (денежной суммы в старой системе)
	// в число типа double (денежную сумму в десятичных фунтах)
	operator double() const
	{
		// формула выведена из соотношения:
		// 1 фунт = 20 шиллингов = 240 пенни (пенсов) = 1920 полуфартингов (восьмушек пенни)
		return (sterling::operator double() + eighths / 1920.0);
	}
	// перегрузка операции сложения (+) для сложения двух объектов класса
	// (результат тоже будет объектом класса)
	sterfrac operator+ (sterfrac s) const
	{
		// 1) sterfrac(pounds, shillings, pences, eighths) — создание безымянного объекта
		// класса с помощью конструктора с четырьмя аргументами. Обозначим это выражение
		// как s1

		// 2) double(s1) и double(s) — создание безымянных переменных типа double с
		// помощью операции преобразования объекта класса в число типа double,
		// определенной выше (сумма из старой системы преобразуется в десятичные фунты)

		// 3) sterfrac(double(s1) + double(s)) — создание безымянного объекта класса
		// с помощью конструктора с одним аргументом (из десятичных фунтов в сумму
		// в старой системе)

		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) + double(s));
	}
	// перегрузка операции вычитания (-) для нахождения разности двух объектов класса
	// (результат тоже будет объектом класса)
	sterfrac operator- (sterfrac s) const
	{
		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) - double(s));
	}
	// перегрузка операции умножения (*) для нахождения произведения объекта класса
	// и числа типа double (результатом будет объект класса)
	sterfrac operator* (double n) const
	{
		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) * n);
	}
	// перегрузка операции деления (/) для нахождения частного от деления объекта
	// класса на другой объект класса (результатом будет число типа double)
	double operator/ (sterfrac s) const
	{
		return (double(sterfrac(pounds, shillings, pences, eighths)) / double(s));
	}
	// перегрузка операции деления (/) для нахождения частного от деления объекта
	// класса на число типа double (результатом будет объект класса)
	sterfrac operator/ (double n) const
	{
		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) / n);
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	sterfrac s1, s2, s; // денежные суммы в старой английской системе
	double n;           // число типа double

	// запрашиваем у пользователя две денежные суммы в старой английской системе
	wcout << L"1. "; s1.getSterling();
	wcout << L"2. "; s2.getSterling(); wcout << endl;

	// покажем эти суммы в десятичных фунтах:
	wcout << L"1. В десятичных фунтах: " << fixed << setprecision(2) << double(s1) << endl;
	wcout << L"2. В десятичных фунтах: " << fixed << setprecision(2) << double(s2) << endl << endl;

	// ДЕМОНСТРАЦИЯ ПЕРЕГРУЖЕННЫХ ОПЕРАЦИЙ:

	// предположим, что денежные суммы s1 и s2 — выручка фирмы за первый и второй годы
	// ее существования, тогда выручка фирмы за 2 этих года составит s:
	s = s1 + s2;
	wcout << L"Результат сложения этих сумм: "; s.putSterling(); wcout << endl;

	// предположим, что s1 — денежная сумма на нашем расчетном счете, а s2 —
	// денежная сумма, перечисленная для оплаты счета поставщика, тогда у нас на
	// расчетном счете останется денежная сумма s:
	s = s1 - s2;
	wcout << L"Разность этих сумм: "; s.putSterling(); wcout << endl;

	// предположим, что s1 — денежная сумма вклада, который мы положили в банк, и
	// процентная ставка по вкладу согласно договора с банком составляет 5% за год,
	// тогда через год сумма нашего вклада вместе с процентами составит s:
	s = s1 * 1.05;
	wcout << L"Произведение первой суммы и числа 1,05: "; s.putSterling(); wcout << endl;

	// предположим, что s1 — денежная сумма, представляющая расходы на покупку грузовика,
	// а s2 — сумма ежегодной прибыли от его использования, определим тогда
	// число лет n, через которое грузовик окупится:
	n = s1 / s2;
	wcout << L"Частное от деления первой суммы на вторую: " << n << endl;

	// предположим, что s1 — денежная сумма, представляющая расходы на покупку грузовика,
	// и нам нужно узнать, сколько прибыли s необходимо получать ежегодно от использования
	// этого грузовика, чтобы он окупился за 3,5 года:
	s = s1 / 3.5;
	wcout << L"Частное от деления первой суммы на число 3,5: "; s.putSterling(); wcout << endl;

	return 0;
}