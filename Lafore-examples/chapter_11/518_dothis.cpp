// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// dothis.cpp
// обращение к данным объекта с помощью указателя this

#include <locale>
#include <iostream>  // для функций ввода/вывода
using namespace std;

class what
{
private:
	int alpha;
public:
	void tester()
	{
		this->alpha = 11;     // то же, что alpha = 11;
		wcout << this->alpha; // то же, что wcout << alpha;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	what w;
	w.tester();
	wcout << endl;

	return 0;
}