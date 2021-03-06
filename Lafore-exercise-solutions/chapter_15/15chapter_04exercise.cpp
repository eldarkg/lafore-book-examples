﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 15chapter_04exercise.cpp
// Имеется класс person, определение которого можно взять из примеров к
// этой (15-й главе). Требуется создать мультимножество, элементы которого
// являются указателями на объекты класса person. Это мультимножество
// требуется определить с помощью функционального объекта comparePersons
// (определение этого функционального объекта тоже можно взять из примеров
// к 15-й главе) так, чтобы мультимножество сортировалось автоматически
// в алфавитном порядке по фамилиям и именам объектов класса person,
// содержащихся в мультимножестве. В функции main требуется определить
// полдюжины (6) персон, поместить их в мультимножество и показать на экране
// содержимое мультимножества. Несколько персон в мультимножестве должны
// иметь сопадающие имя и фамилию, чтобы показать, что мультимножество может
// хранить объекты с одним и тем же ключом.

#include <locale>
#include <iostream>
#include <set>       // для работы с контейнером multiset
#include <algorithm> // для алгоритма for_each
#include <string>    // для работы с классом wstring
#include <iomanip>   // для манипулятора потока setw
using namespace std;

class person // класс, представляющий запись о человеке в телефонной книге
{
private:
	wstring lastName;  // фамилия
	wstring firstName; // имя
	long phoneNumber;  // телефонный номер
public:
	// конструктор без аргументов
	person() : lastName(L"пусто"), firstName(L"пусто"), phoneNumber(0L)
		{ }
	// конструктор с тремя аргументами
	person(wstring lana, wstring fina, long pho) :
		lastName(lana), firstName(fina), phoneNumber(pho)
		{ }
	
	// дружественная для класса функция (перегрузка оператора «меньше»)
	friend bool operator< (const person&, const person&);

	void display() const   // вывод на экран данных о человеке
	{
		wcout << setiosflags(ios::left) << setw(13) << lastName
			<< setw(11) << firstName << L"телефон: " << phoneNumber << endl;
	}
};

// оператор < («меньше»), перегруженный для класса person
bool operator< (const person& p1, const person& p2)
{
	if (p1.lastName == p2.lastName)
		return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}

// функциональный объект для сравнения объектов класса person по указателям на них
class comparePersons
{
public:
	bool operator() (const person* ptrP1, const person* ptrP2) const
		{ return *ptrP1 < *ptrP2; }
};

// функция для вывода на экран объекта класса person по указателю на него
void displayPerson(const person* ptrP)
	{ ptrP->display(); }

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	// определим мультимножество и укажем наш функциональный объект,
	// предназначенный для автоматической сортировки мультимножества
	multiset<person*, comparePersons> mspers;

	// отмечу, что в угловых скобках следует задавать имя типа (или класса)
	// comparePersons, а не выражение comparePersons() с круглыми скобками —
	// это будет ошибкой

	// определим полдюжины персон, выделим память под эти объекты класса person
	// и поместим указатели на выделенную память в мультимножество
	mspers.insert(new person(L"Пушкин", L"Александр", 4157300)); // 1
	mspers.insert(new person(L"Толстой", L"Лев", 8435150));      // 2
	mspers.insert(new person(L"Лермонтов", L"Михаил", 9207404)); // 3
	mspers.insert(new person(L"Ахматова", L"Анна", 6946473));    // 4
	mspers.insert(new person(L"Чехов", L"Антон", 7049982));      // 5
	mspers.insert(new person(L"Пушкин", L"Александр", 7764987)); // 6

	// отмечу, что у объектов 1 и 6 совпадает ключ (совокупность фамилии
	// и имени), но они оба будут вставлены в мультимножество, так как
	// мультимножество (в отличие от множества) позволяет вставку объектов
	// с одинаковым ключом (это можно проверить, заменив в начале этой программы
	// в определении мультимножества служебное слово multiset на служебное
	// слово set — множество)

	// выведем на экран содержимое мультимножества
	for_each(mspers.begin(), mspers.end(), displayPerson);

	// в этом месте программы задание уже полностью выполнено и дальнейший
	// код не обязателен, но всё равно выполним освобождение выделенной ранее
	// памяти и удаление всех элементов из мультимножества

	// для прохода в цикле по мультимножеству определим итератор
	multiset<person*, comparePersons>::iterator iter;

	// пройдем в цикле по мультимножеству
	for (iter = mspers.begin(); iter != mspers.end(); iter++)
	{
		delete *iter;       // освободим память, выделенную ранее
		                    // под объект класса person,
		mspers.erase(iter); // удалим элемент мультимножества
	}

	return 0;
}