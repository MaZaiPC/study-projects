// BinaryFilesLib.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "BinFiles.h"
#include "Utils.h"

/* Для быстрой копипасты соорудил:

// чтение всего файла
void load(char* fileName, char* &to)
{
	FILE * fin;
	fin = fopen(fileName, "rb");
	while (!feof(fin)) {
		fscanf(fin, "%s", &to);
	}
	fclose(fin);
}

// запись строки в файл
void write(char* fileName, char* &from)
{
	FILE * fout;
	fout = fopen(fileName, "wb");
	fprintf(fout, "%d\n", from);
	fclose(fout);
}
*/

HANDLE h;

int main() // тест работы класса BinDB
{
	init();
	BinDB f;					// создаем базу
	f.SetFileName("test.bin");  // инициализируем
	LPSTR output;				// переменная для хранения результата

	//		Назв. секции, p№,  Value
	f.Write("TestSection", 1, "Test String");
	//	    Назв. секции, p№,  Default, куда записать значение
	f.Read("TestSection", 1 ,  "NULL"  , output);

	cout << "Param1 = " << output << endl; // вывод результата
	return 0;
}

