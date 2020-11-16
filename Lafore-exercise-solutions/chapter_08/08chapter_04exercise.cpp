﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 08chapter_04exercise.cpp
// Перегрузить четыре целочисленных арифметических операции (+, -, *, /), чтобы
// их можно было использовать для операций с объектами класса Int, созданного
// в 1-м упражнении 6-й главы (предусмотреть проверку на переполнение).

// Предполагается, что базовый тип int занимает 4 байта (на 32- или 64-разрядной
// операционной системе) и может представлять любое целое значение из диапазона
// с -2'147'483'648 по 2'147'483'647 (указанные границы входят в диапазон).
// Выход значения за этот диапазон считаем ошибкой переполнения.

// Для проверки на переполнение используем тип long double.
// Помним, что в Visual Studio Community 2017 тип long double хоть поддерживается
// и отличается компилятором от типа double, но на деле является таким же 64-битным
// представлением числа с плавающей запятой, что и double. Эти типы в указанной среде
// разработки идентичны и значения этих типов занимают по 8 байт (64 бита) каждое.

// При попытке использования значения -2'147'483'648 компилятор Visual Studio Community 2017
// выдает ошибку "C4146: применение унарного минуса к типу без знака". Это связано с тем,
// что указанный компилятор сначала рассматривает число без минуса и из-за того, что
// оно выходит за диапазон базового типа по умолчанию int, значение считается беззнаковым
// целым типа unsigned long, к которому знак минус неприменим. Поэтому пришлось
// использовать выражение (-2'147'483'647 - 1). Также можно использовать константу INT_MIN.

// При преобразовании переменной number типа int к типу long double применяем вместо
// выражения long double(number) рекомендуемое static_cast<long double>(number). Лафоре
// объясняет это тем, что последнее легче искать в тексте программы хоть визуально,
// хоть с помощью инструмента поиска.

#include <locale>
#include <iostream>
using namespace std;

class Int // класс, имитирующий стандартный тип int
{
private:
	int number; // поле класса
public:
	// конструктор без параметров, устанавливающий значение поля класса равным нулю
	Int() : number(0)
		{ }
	// конструктор с одним параметром для инициализации поля класса
	Int(int n) : number(n)
		{ }
	// метод выводит значение поля на экран
	void show()
		{ wcout << number; }
	// проверка на переполнение
	Int test_overflow(long double t) const
	{
		// при ошибке работа программы прерывается с сообщением
		if (t < -2'147'483'647 - 1 || t > 2'147'483'647)
			{ wcout << L"Ошибка переполнения!" << endl; exit(1); }
		// если переполнения нет, возвратить объект с результатом операции
		// (выполняется неявное преобразование long double в int, компилятор
		// выдает предупреждение, но компиляция завершается успешно)
		return Int(t);
	}
	// перегрузка операции сложения для нахождения суммы двух объектов класса Int
	Int operator+ (Int n) const
		{ return test_overflow(static_cast<long double>(number) + n.number); }
	// перегрузка операции вычитания для нахождения разности двух объектов класса Int
	Int operator- (Int n) const
		{ return test_overflow(static_cast<long double>(number) - n.number); }
	// перегрузка операции умножения для нахождения произведения двух объектов класса Int
	Int operator* (Int n) const
		{ return test_overflow(static_cast<long double>(number) * n.number); }
	// перегрузка операции деления для нахождения частного от деления одного объекта
	// класса Int на другой объект того же класса
	Int operator/ (Int n) const
		{ return test_overflow(static_cast<long double>(number) / n.number); }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	// создание трех переменных нашего класса и демонстрация работы конструкторов
	Int n1(13), n2 = 5, n3;

	// демонстрация работы перегруженных операций
	n3 = n1 + n2;
	wcout << L"Результат сложения: "; n3.show(); wcout << endl;
	n3 = n1 - n2;
	wcout << L"Результат вычитания: "; n3.show(); wcout << endl;
	n3 = n1 * n2;
	wcout << L"Результат умножения: "; n3.show(); wcout << endl;
	n3 = n1 / n2;
	wcout << L"Результат целочисленного деления: "; n3.show(); wcout << endl;

	// демонстрация работы программы при переполнении

	// n1 = -2'147'483'647; n2 = -2; // переполнение в меньшую сторону при сложении
	// n3 = n1 + n2;

	// n1 = 2'147'483'647; n2 = 1; // переполнение в бо́льшую сторону при сложении
	// n3 = n1 + n2;

	// n1 = -2'147'483'647; n2 = 2; // переполнение в меньшую сторону при вычитании
	// n3 = n1 - n2;

	// n1 = 2'147'483'647; n2 = -1; // переполнение в бо́льшую сторону при вычитании
	// n3 = n1 - n2;

	// n1 = -2'147'483'647; n2 = 2; // переполнение в меньшую сторону при умножении
	// n3 = n1 * n2;

	// и т.п.

	// при делении переполнение возможно только в бо́льшую сторону: -2'147'483'648 / -1

	return 0;
}