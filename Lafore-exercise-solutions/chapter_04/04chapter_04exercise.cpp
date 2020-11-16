// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 04chapter_04exercise.cpp
// Создать структуру, представляющую работника, и выполнить с структурной
// переменной такого типа указанные в описании упражнения операции.

#include <locale>
#include <iostream>
#include <iomanip> // для манипулятора setw
using namespace std;

struct employee // работник
{
	int number;   // номер работника
	float salary; // зарплата работника в рублях
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	employee emp1, emp2, emp3; // создание трех структурных переменных типа employee

	// получаем с клавиатуры информацию о трех работниках
	wcout << L"Введите данные трех работников\n";
	wcout << L"Номер и зарплата работника: "; wcin >> emp1.number >> emp1.salary;
	wcout << L"Номер и зарплата работника: "; wcin >> emp2.number >> emp2.salary;
	wcout << L"Номер и зарплата работника: "; wcin >> emp3.number >> emp3.salary;

	// вывод информации о каждом из сотрудников на экран
	wcout << L"\nИнформация о работниках компании:\n"
	      << setw(5) << L"Номер"    << setw(9) << L"Зарплата" << endl
		  << setw(5) << emp1.number << setw(9) << emp1.salary << endl
		  << setw(5) << emp2.number << setw(9) << emp2.salary << endl
		  << setw(5) << emp3.number << setw(9) << emp3.salary << endl;

	return 0;
}