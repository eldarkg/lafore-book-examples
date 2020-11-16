// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 06chapter_04exercise.cpp
// создать класс employee (работник), используя упражнение 4 главы 4

#include <locale>
#include <iostream>
#include <iomanip> // для манипулятора setw
using namespace std;

class employee // класс, представляющий работника
{
private:
	int number;   // номер работника
	float salary; // зарплата работника в рублях
public:
	// метод для получения данных класса от пользователя с клавиатуры
	void get()
		{ wcout << L"Номер и зарплата работника: "; wcin >> number >> salary; }
	// константный метод выводит значения полей на экран
	void display() const
		{ wcout << setw(5) << number << setw(9) << salary << endl; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	employee emp1, emp2, emp3; // создание трех объектов класса employee

	// получаем с клавиатуры информацию о трех работниках
	wcout << L"Введите данные трех работников\n";
	emp1.get();
	emp2.get();
	emp3.get();

	// вывод информации о каждом из сотрудников на экран
	wcout << L"\nИнформация о работниках компании:\n"
		  << setw(5) << L"Номер" << setw(9) << L"Зарплата" << endl;
	emp1.display();
	emp2.display();
	emp3.display();

	return 0;
}