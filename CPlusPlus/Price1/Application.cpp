#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Price.h"


// возвращает количество записей в файле данных
int Application::numRecords()
{
	// Перейти в конец файла - переместить указатель файловой
	// операции в конец файла - функция fseek()
	// SEEK_END - относительно конца файла
	// SEEK_SET - относительно начала файла
	// SEEK_CUR - относительно текущей позиции файла
	fseek(f, 0, SEEK_END);

	// ftell()   - возвращает байтовую позицию указателя файловой операции
	// sizeof(x) - операция получения размера программного объекта x в байтах 
	
	// количество записей в файле
	return ftell(f) / Price::recSize();
}

Application::Application() :dbFileName("Price.bin")
{
	// режим открытия:
	// r - чтение
	// r+ чтение и запись
	// b - двоичный режим
	f = fopen(dbFileName, "rb+");
	
	// Если файл не найден - попытаемся создать файл
	if (f == nullptr) {
		// w - запись, если файла нет, то он создается
		//     если файл есть, то его длина сбрасывается в 0 
		//     содержимое файла уничтожается безвозвратно
		f = fopen(dbFileName, "wb+");
		if (f == nullptr) {
			SetWindow(80, 25, 0x07);
			Clear();
			WriteXY(34, 12, "Аварийное завершение");
			GotoXY(0, 24);
		} // if
	} // if
} // Application::Application


Application::~Application() 
{
	fclose(f);   // закрыть файл данных
} // Application::~Application


// Главный метод приложения - обработка команд пользователя  
void Application::run()
{
	UINT cmd;                // Команда меню
	bool flagExit = false;   // Флаг выхода из бесконечного цикла
	char *szMenu = "\t  Вариант 18, Семинар 6 из сборника Павловская Т.А., Щупак Ю.А."
		"\n\n\n\n\n\n\t\t  *** М Е Н Ю ***\n"
		"\t     1) Добавить новый товар\n"
		"\t     2) Вывод товаров, упорядоченных по цене\n"
		"\t     3) Вывод товаров, упорядоченных по названию\n"
		"\t     0) Выход\n"
		"\t     Ваш выбор (0, ..., 2)> ";

	while (true) {
		Clear();

		cmd = getUINT(szMenu, 0, 3);
		
		switch (cmd) {
		case 1:
			read();
			break;
		// Вывод с упорядочиванием по номеру маршрута
		case 2:
			sort(cmpPrice);
			show();
			break;
		// Вывод с упорядочиванием по пункту отправления
		case 3:
			sort(cmpName);
			show();
			break;
		case 0:
			flagExit = true;
			break;
		} // switch
		if (flagExit) break;
		GotoXY(0, 24);
		system("pause");
	} // while

	// Возвращаем стандартный вид окну
	// размер 80 х 25, серые символы на черном фоне
	SetWindow(80, 25, 0x07);
	Clear();
	WriteXY(34, 12, "Конец работы");
	GotoXY(0, 24);

	// Освободить память, занятую строковым представлением объекта
	//if (s) delete[] s;
} // Application::run


// Метод для ввода данных в массив пунктов назначений
void Application::read()
{
	Price Price;

	WriteXY(22, 12, "Введите данные пунктов маршрута");
	Price.Read(12, 14);   // ввод с клавиатуры
	Price.Save(f);        // сохранение в файл
	
	// Закрываем и открываем файл - для сброса в файл буферов ввода
	// Если возникла ошибка - аварийное завершение программы
	fclose(f);
	f = fopen(dbFileName, "rb+");
	if (f == nullptr) {
		SetWindow(80, 25, 0xce);
		WriteXY(20, 12, "Ошибка доступа к файлу данных");
		GotoXY(0, 24);
		exit(1);
	} // if
} // Application::read


// Метод для вывода данных из массива пунктов назначений
void Application::show()
{
	Price Price;

	Clear();

	int n = numRecords();

	fseek(f, 0, SEEK_SET);
	GotoXY(0, 3);
	int Pos[3];
	for (int i = 0; i < n; i++) {
		// чтение из файла очередной записи, указатель продвигается по файлу
		Price.Load(f); 
		Price.Display(Pos[0], Pos[1], true);
	} // for i
	Pos[2] = WhereXY().Y;
	WriteXY(Pos[0], 1, "Товар");
	WriteXY(Pos[1], 1, "Цена");
	GotoXY(0, Pos[2]);
} // Application::show


// Метод для сортировки данных в файле по возрастанию номеров маршрутов
void Application::sort(bool compare(const Price &, const Price &))
{
	int n = numRecords(), rec_size = Price::recSize();
	int i, j;      
	Price t1, t2;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			fseek(f, j*rec_size, SEEK_SET); // перейти к j-й записи файла
			t1.Load(f);   // j-я запись прочитана, автом. сместились на j+1
			t2.Load(f);   // j+1-я запись прочитана

			// Если пара не упорядочена, то поменять записи в файле местами
			if (compare(t1, t2)) {
				fseek(f, j*rec_size, SEEK_SET); // перейти к j-й записи файла
				t2.Save(f, false); // j-я позиция -- пишем t2 
				t1.Save(f, false); // j+1-я позиция -- пишем t1
			} // if
		} // for j
	} // for i
} // Application::sort


// Не обязательно метод класса
// Возвращает true, если номер маршрута1 > номера маршрута2
// т.е. пара не упорядочена, тркбуется обмен местами
inline bool cmpPrice(const Price &t1, const Price &t2)
{
	return t1.getPrice() > t2.getPrice();
} //  cmpNumber


// Возвращает true, если пункт отправления1 > пункта отправления2
// т.е. пара не упорядочена, тркбуется обмен местами
inline bool cmpName(const Price &t1, const Price &t2)
{
	return strcmp(t1.getName(), t2.getName()) == 1;
} //  cmpNumber






