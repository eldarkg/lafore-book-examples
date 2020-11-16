// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// statdata.cpp
// статические данные класса

#include <locale>
#include <iostream>
using namespace std;

class foo
{
private:
	static int count; // общее поле для всех объектов (здесь лишь его объявление)
public:
	foo()             // инкрементирование при создании объекта
		{ count++; }
	int getcount()    // возвращает значение count
		{ return count; }
};

int foo::count = 0;   // определение count

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	foo f1, f2, f3; // создание трех объектов

	// каждый объект видит одно и то же значение
	wcout << L"Число объектов: " << f1.getcount() << endl;
	wcout << L"Число объектов: " << f2.getcount() << endl;
	wcout << L"Число объектов: " << f3.getcount() << endl;

	return 0;
}