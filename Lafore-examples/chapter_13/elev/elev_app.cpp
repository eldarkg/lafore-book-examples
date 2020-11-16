// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// elev_app.cpp
// клиентский файл

#include "elev.h" // описатели классов

#include <locale>

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	building theBuilding;

	while (true)
	{
		theBuilding.master_tick();       // запустить тики (такты) всех лифтов
		wait(1000);                      // пауза
		theBuilding.record_floor_reqs(); // получить запросы с этажей
		                                 // от пользователя
	}

	return 0;
}