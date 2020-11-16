// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// constobj.cpp
// константные объекты класса Distance

#include <locale>
#include <iostream>
using namespace std;

class Distance // длина в английской системе
{
private:
	int feet;     // футы
	float inches; // дюймы
public:
	// конструктор с двумя аргументами
	Distance(int ft, float in) : feet(ft), inches(in)
		{ }
	void getdist() // неконстантный метод
	{
		wcout << L"Введите число футов: "; wcin >> feet;
		wcout << L"Введите число дюймов: "; wcin >> inches;
	}
	void showdist() const // константный метод
		{ wcout << feet << L"\'-" << inches << L'\"'; }
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	const Distance football(300, 0);

	// football.getdist();         // ошибка: метод getdist() неконстантный
	
	wcout << L"Длина футбольного поля равна ";
	football.showdist();           // корректно
	wcout << endl;

	return 0;
}