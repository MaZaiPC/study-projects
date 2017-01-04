#include "stdafx.h"
#include "BinFiles.h"
#include "Utils.h"

void SplitFilename(const std::string& str)
{
	
}

BinDB::BinDB() : fileName("data0.bin")
{
}


BinDB::~BinDB()
{
}

void BinDB::SetFileName(LPCSTR name)
{
	fileName = name;
}

LPCSTR BinDB::GetFileName() {
	return fileName;
}

// ГЛАВНЫЕ ФУНКЦИИ
void BinDB::Read(LPCSTR section, WORD paramNumber, LPSTR defaultValue, LPSTR &returnWhere)
{
	FILE * fin;
	fin = fopen(fileName, "rb");
	RESULT finder = Find(section, paramNumber);
	if (finder.state) // если вдруг секция и параметр созданы
	{
		fseek(fin, finder.seek, SEEK_SET);
		fscanf(fin, "%s", &returnWhere);
		return;
	} else {
		cout << "\nПараметр #" << paramNumber << " в секции \"" << section << "\" не найден!\n"; 
		returnWhere = defaultValue;
	}
	
	fclose(fin);
}

void BinDB::Write(LPCSTR section, WORD paramNumber, LPCSTR string)
{
	FILE * fout;
	fout = fopen(fileName, "wb");
	RESULT finder = Find(section, paramNumber);
	if (finder.state) // если вдруг секция и параметр созданы
	{
		fseek(fout, finder.seek, SEEK_SET);
		fprintf(fout, "%d\n", string);
		return;
	}
	if (finder.secState) // если вдруг секция уже создана а параметра еще нет
	{
		fseek(fout, finder.secSeek, SEEK_SET);
		int i = finder.secSeek;
		LPSTR str("");
		while (!feof(fout)) {
			i++;
			if (fgets(str, 250, fout) == "}")
			{
				fprintf(fout, "%d\n}", string);
				break;
			}
		}
		return;
	}
	fseek(fout, 0, SEEK_END);   // иначе запись в конец файла данных
	fclose(fout);
}

BinDB::RESULT BinDB::Find(LPCSTR section, WORD what) const
{

	RESULT result;
	FILE * f;
	f = fopen(fileName, "rb");
	fseek(f, 0, SEEK_SET);   // в начало файла данных
	int i(0),j;
	// Цикл - по записям в файле - линейный поиск 
	LPSTR str("");
	LPSTR sec = (LPSTR)Format("%c%s", '{', section).c_str();
	// находим секцию
	while (!feof(f)) {
		i++;
		if (fgets(str, 250, f) == sec)
		{
			result.secState = true;
			result.secSeek  = i;
			break;
		}
		
	} // while i
	fseek(f, i, SEEK_SET);   // начало секции данных
	// находим параметр в секции
	while (!feof(f)) {
		i++;
		fgets(str, 250, f);
		
		j = 0;
		// Посимвольная проверка строки на наличие '}' (конца секции)
		// пока не достигнут нуль-терминал (эта чатсть кода требует консультации)
		while (str[j] != '\0')
		{
			j++;
			if (str[j] == '}')
			{
				goto _break; // выход из всех вложенных циклов
			}
		} // while j

		// если параметр n найден успешно, то присваеваем полный результат
		if (i == result.secSeek+what)
		{
			result.str = str;
			result.seek = i;
			result.state = true;
			break;
		} // if

	} // while i
_break:; // метка предназначеная для выхода из всех вложенных циклов,
		 // можно было и с помощью булевых флагов, но так проделывается
		 // в разы больше операций.

	return result;
}