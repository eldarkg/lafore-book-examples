// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// opers.cpp
// запись объекта класса person в файл

#include <locale>
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
using namespace std;

class person // класс, представляющий человека
{
protected:
	wchar_t name[80]; // имя человека
	short age;        // и его возраст
public:
	void getData()    // получение от пользователя данных объекта
	{
		wcout << L"Введите имя: "; wcin >> name;
		wcout << L"Введите возраст: "; wcin >> age;
	}
};

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	person pers;    // создать объект класса person
	pers.getData(); // получить данные объекта класса person
	                // создать объект класса ofstream (связанный с файлом)
	ofstream outfile(L"человек.dat", ios::binary);
	                // записать в файл объект класса person
	outfile.write(reinterpret_cast<char*>(&pers), sizeof(pers));

	return 0;
}