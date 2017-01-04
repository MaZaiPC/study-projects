#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Goods.h"
#include "Receipt.h"


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
	return ftell(f) / Goods::recSize();
}

Application::Application() :dbFileName("Goods.bin")
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
}// Application::Application


Application::~Application()
{
	fclose(f);   // закрыть файл данных
}// Application::~Application


// Главный метод приложения - обработка команд пользователя  
void Application::run()
{
	UINT cmd;                // Команда меню
	bool flagExit = false;   // Флаг выхода из бесконечного цикла

	char *szMenu = "\t\t           Задание номер 13 на 28.09.15"
		"\n\n\t\t\t\t  *** М Е Н Ю ***\n"
		"\t\t         1) Ввод данных для товарного чека\n"
		"\t\t         2) Вывод товарных чеков\n"
		"\t\t         3) Сумма\n"
		"\t\t         0) Выход\n"
		"\t\t         Ваш выбор (0, ..., 3)> ";

	while (true) {
		Clear();
		
		cmd = getUINT(szMenu, 0, 3);

		switch (cmd) {
		case 1:
			read();
			break;
		case 2:
			Clear();
			show();
			break;
		case 3:
			Sum();
			break;
		case 0:
			flagExit = true;
			break;
		} // switch
		cout << "\n\n\n";
		if (flagExit) break;
		system("pause");
	} // while

	// Возвращаем стандартный вид окну
	// размер 80 х 25, серые символы на черном фоне
	SetWindow(80, 25, 0x07);
	cout << "\nКонец работы\n";

}// Application::run


// Метод для ввода данных для чека
void Application::read()
{
	receipt = new Receipt(); // создать новый чек
	cin >> *receipt;         // ввести чек
	receipt->save();        // сохранить чек в файле данных
	delete receipt;        // освободить память, удалить чек
}// Application::read

// Метод для вывода данных для чеков
void Application::show()
{
	
}// Application::show

// Сумма товаров к оплате, не корректная(
void Application::Sum()
{
}// Application::Sum()



