using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using MaZaiPC.TextFiles.Entities;
using MaZaiPC.TextFiles.Service;

namespace MaZaiPC.TextFiles
{
	static class Solution
	{
		private static string fileName = @"..\..\marsh.bin";

		/// <summary> Вводит данные о маршруте с клавиатуры и сохраняет в бинарный файл. </summary>
		public static void EnterNewMarsh()
		{
			#region Выводим подсказку
			
			Utils.PrintEncolored("Введите новый маршрут\n\n");
			Console.WriteLine("Пункт отправления :>\n" +
							  "Пункт назначения  :>\n" +
			                  "Номер маршрута    :>");
			#endregion

			#region Вводим данные о маршруте
			Marsh recruit = new Marsh();
			const int cx = 22;
			Console.SetCursorPosition(cx, 2);
			recruit.From = Console.ReadLine();
			Console.SetCursorPosition(cx, 3);
			recruit.To = Console.ReadLine();

			int number;
			Console.SetCursorPosition(cx, 4);
			int.TryParse(Console.ReadLine(), out number);
			recruit.Number = number;
			#endregion

			#region Добавляем в файл
			using (BinaryWriter bw = new BinaryWriter(new FileStream(fileName, FileMode.Append), Encoding.Default))
				recruit.Write(bw);
			#endregion
		} // EnterNewMarsh::END

		/// <summary>
		///		Выводит на экран информации о маршруте, номер которого введен с клавиатуры.
		///		Если таких маршрутов нет, выводит соответствующее сообщение.
		/// </summary>
		public static void GetMarshInfo()
		{
			#region Вводим номер для поиска по маршрутам
			int requested;
			bool finded = false;

			Console.Write("Вывести номер маршрута :> ");
			int.TryParse(Console.ReadLine(), out requested);
			#endregion
			
			#region Читаем каждый маршрут при совпадении с номером выводим его на экран
			using (BinaryReader br = new BinaryReader(File.OpenRead(fileName)))
			{
				Console.WriteLine("{0,-30} {1,-30} {2,-5}", "Откуда", "Куда", "Номер");

				// Сколько записей в файле
				int len = (int)br.BaseStream.Length / Marsh.LenRecord;

				if (len == 0)
				{
					Console.WriteLine("\nПусто.");
					return;
				}

				for (int i = 0; i < len + 1; ++i)
				{
					Marsh loaded = new Marsh().Load(br);

					if (loaded.Number == requested)
					{
						Console.WriteLine(loaded);
						finded = true;
						// break; -- но программа допускает ввод одинаковых маршрутов
					}
				}
				if (!finded)
					Console.WriteLine("Маршрут не найден!");
			
			}
			#endregion
		} // GetMarshInfo::END

		/// <summary> Выводит все маршруты на экран. </summary>
		public static void ShowAll()
		{
			#region Читаем каждый маршрут и выводим его в цикле
			using (BinaryReader br = new BinaryReader(File.OpenRead(fileName)))
			{
				Console.WriteLine("{0,-30} {1,-30} {2,-5}", "Откуда", "Куда", "Номер");

				// Сколько записей в файле
				int len = (int)br.BaseStream.Length / Marsh.LenRecord;

				if (len == 0) {
					Console.WriteLine("\nПусто.");
					return;
				}

				for (int i = 0; i < len + 1; ++i)
					Console.WriteLine(new Marsh().Load(br));

			}
			#endregion
		} // ShowAll::END

		/// <summary> Упорядочивает файл по номерам маршрутов. </summary>
		public static void SortFileByNumbers()
		{
			#region Читаем все маршруты из файла в массив
			Marsh[] marshes;
			using (BinaryReader br = new BinaryReader(File.OpenRead(fileName)))
			{
				// Сколько записей в файле
				int len = (int)br.BaseStream.Length / Marsh.LenRecord;

				if (len == 0) {
					Utils.PrintEncolored("\nНет элементов для упорядочивания.\n", ConsoleColor.Cyan);
					return;
				}

				marshes = new Marsh[len + 1];
				
				for (int i = 0; i < len + 1; ++i)
					marshes[i] = new Marsh().Load(br);
			}
			#endregion Читаем в массив

			#region Сортируем массив пузырьком
			Marsh temp;
			for (int i = 0; i < marshes.Length; ++i)
			{
				for (int j = i + 1; j < marshes.Length; ++j)
				{
					if (marshes[i].Number > marshes[j].Number)
					{
						temp = marshes[i];
						marshes[i] = marshes[j];
						marshes[j] = temp;
					} // endif
				} // for j
			} // for i
			#endregion
			
			#region Записываем обратно в файл
			using (BinaryWriter bw = new BinaryWriter(File.Create(fileName), Encoding.Default))
			{
				foreach (var marsh in marshes)
					marsh.Write(bw);
			} // BinaryWriter::END

			Utils.PrintEncolored("\nУпорядочено.\n", ConsoleColor.Cyan);
			#endregion
			// TODO: Сортировка без использования массива.
		} // SortFileByNumbers::END
	}
}
