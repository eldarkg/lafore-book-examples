// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// englptr.cpp
// доступ к членам класса через указатель

#include <locale>
#include <iostream>
using namespace std;

class Distance // класс, представляющий интервал в английских мерах длины
{
private:
	int feet;     // футы (1 фут = 12 дюймов)
	float inches; // дюймы
public:
	void getdist()        // получение длины интервала от пользователя
	{
		wcout << L"Введите футы: "; wcin >> feet;
		wcout << L"Введите дюймы: "; wcin >> inches;
	}
	void showdist() const // вывод на экран длины интервала
	{
		wcout << feet << L"\'-" << inches << L'\"';
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	Distance dist;          // определяем именованный объект класса Distance
	dist.getdist();         // получаем доступ к членам объекта
	dist.showdist();        //     через операцию точки
	wcout << endl << endl;

	Distance* distptr;      // указатель на безымянный объект класса Distance
	distptr = new Distance; // указывает на выделенный под этот объект блок памяти
	distptr->getdist();     // получаем доступ к членам объекта
	distptr->showdist();    //     через операцию -> (стрелки)
	wcout << endl;

	// Операцию стрелки (->) еще называют «операцией доступа к членам класса».

	return 0;
}