using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using Moreniell.StoreApplication.Service;

namespace Moreniell.StoreApplication.Entities
{
	class Store
	{
		private readonly FileStream   fs; // Базовый поток
		private readonly BinaryReader br; // Читатель двочиных данных из базового потока
		private readonly BinaryWriter bw; // Писатель двочиных данных в базовый поток


		private const string HEADER = "╔══════════════════════════════════════════╦════════════╗\n" +
									  "║ Наименование товара                      ║ Цена (руб) ║\n" +
									  "╠══════════════════════════════════════════╬════════════╣";
		private const string FOOTER = "╚══════════════════════════════════════════╩════════════╝";

		/// <summary> Название магазина. </summary>
		public string Name { get; set; }

		public Store(string storeName)
		{
			Name = storeName;
			fs = new FileStream($"..\\..\\{storeName}.dat", FileMode.OpenOrCreate, FileAccess.ReadWrite);
			br = new BinaryReader(fs, Encoding.GetEncoding(1251), leaveOpen: true);
			bw = new BinaryWriter(fs, Encoding.GetEncoding(1251), leaveOpen: true);
		}

		/// <summary> Закрывает все управляемые ресурсы. </summary>
		public void Close()
		{
			bw.Close();
			br.Close();
			fs.Close();
		}

		public void NewPrice()
		{
			#region Выводим подсказку

				Utils.PrintEncolored("[Добавление товара]\n\n");
				Console.WriteLine("Наименование :>\n" +
								  "Стоимость    :>");
			#endregion

			#region Заполняем данные о товаре

				const int cx = 16;
				Console.SetCursorPosition(cx, 2);
				Price recruit = new Price
				{
					StoreName = Name,
					ProductName = Console.ReadLine()
				};
			
				uint cost;
				Console.SetCursorPosition(cx, 3);
				uint.TryParse(Console.ReadLine(), out cost);
				if (cost == 0) throw new Exception("Бесплатно не продаем!");
				recruit.Cost = cost;
			#endregion

			#region Добавляем в файл
				fs.Seek(0, SeekOrigin.End);
				recruit.Write(bw);
			#endregion
		} // END::

		public void Sort()
		{
			#region Подготавливаем инструменты
				// Длина одной записи
				int lenRecord = Price.LenRecord;
			
				// Сколько записей в файле
				int len = (int)fs.Length / lenRecord;

				if (len == 0)
				{
					Utils.PrintEncolored("\nНет элементов для упорядочивания.\n", ConsoleColor.Cyan);
					return;
				}

				Price curr = new Price();   // текущий прочитанный элемент
				Price next = new Price();   // следующий прочитанный элемент
			#endregion

			#region Сортируем файл
			for (int i = 0; i < len; ++i)
				{
					for (int j = 0; j < len - i - 1; ++j)
					{
						// Читать j и j+1 записи
						fs.Seek(j * lenRecord, SeekOrigin.Begin);
						curr.Load(br);
						next.Load(br);

						// Если необходимо  меняем местами j и j+1 записи
						if (string.CompareOrdinal(curr.ProductName, next.ProductName) > 0)
						{
							fs.Seek(j * lenRecord, SeekOrigin.Begin);  // перейти на позицию j
							next.Write(bw);  // сначала запишем содержимое позиции j+1 
							curr.Write(bw);  // затем запишем содержимое позиции j
						} // endif
					} // for j
				} // for i
			#endregion
		} // Sort::END

		public void FindPrice()
		{
			#region Вводим название товара для поиска
			bool finded = false;

			Console.Write("Найти товар :> ");
			string requested = Console.ReadLine();
			#endregion

			#region Читаем каждый товар, при совпадении с запросом выводим его на экран
			Utils.PrintEncolored($"Результаты поиска по магазину \"{Name}\"\n\n");
			Console.WriteLine(HEADER);

			// Перейти в начало файла
			fs.Seek(0, SeekOrigin.Begin);

			// Сколько записей в файле
			int len = (int)fs.Length / Price.LenRecord;

			if (len != 0)
			{
				for (int i = 0; i < len; ++i)
				{
					Price curr = new Price().Load(br);

					if (!curr.ProductName.ToLower().Contains(requested.ToLower())) continue;

					Console.WriteLine(curr);
					finded = true;
				}
			}

			if (!finded) {
				Console.Clear();
				Utils.PrintEncolored("\n\nСовпадений не найдено.\n\n");
				return;
			}
			Console.WriteLine(FOOTER);
			#endregion
		} // FindPrice::END

		public void ShowPriceList()
		{
			#region Читаем каждый товар и выводим его в цикле
			Utils.PrintEncolored($"Прайс-лист магазина \"{Name}\"\n\n");
			Console.WriteLine(HEADER);

			// Перейти в начало файла
			fs.Seek(0, SeekOrigin.Begin);

			// Сколько записей в файле
			int len = (int)fs.Length / Price.LenRecord;

			if (len != 0)
			{
				for (int i = 0; i < len; ++i)
					Console.WriteLine(new Price().Load(br));
			}
			else
				Console.WriteLine($"║ {"Список товаров пуст.",-41}║    ————    ║");
			Console.WriteLine(FOOTER);
			#endregion
		} // ShowPriceList::END
	}
}