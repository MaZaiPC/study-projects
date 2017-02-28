using System;
using System.IO;

using Moreniell.NumManager.Common;
using Moreniell.NumManager.Entities;
using Moreniell.NumManager.Evеnts;

namespace Moreniell.NumManager
{
	internal class Solution
	{
		// Путь к файлу с целыми числами.
		private const string FILE_NAME = @"..\..\random-integers.bin";
		
		// Диапазон значений отслеживаемых фильтром.
		private static int min = -2;
		private static int max = 2;
		
		// Диапазон значений для генерации рандомных чисел.
		public const int WRITE_MIN = -10;
		public const int WRITE_MAX = 10;

		// Объекты-наблюдатели.
		private static AppendPositive appendPositive = new AppendPositive();
		private static FilteredShow   filteredShow   = new FilteredShow(min, max);
		private static readonly EvenCounter evenCounter = new EvenCounter();

		/// <summary> Записывает в файл новые случайные значения. </summary>
		public static void FillRandomizedNumbers()
		{
			int len = RandomGenerator.Int32(10, 20);
			using (var bw = new BinaryWriter(File.Open(FILE_NAME, FileMode.Create)))
			{
				// Записываем в файл энное количество случайных чисел.
				for (int i = 0; i < len; ++i)
					bw.Write(RandomGenerator.Int32(WRITE_MIN, WRITE_MAX));
			} // BinaryWriter::END
		} // FillRandomizedNumbers::END

		/// <summary> Настраивает фильтр так, чтобы он срабатывал в указаном диапазоне значений. </summary>
		public static void ChangeFilterRanges()
		{
			// Выводим подсказки.
			Print.Encolored("Диапазон значений:         "); Console.WriteLine($"от {WRITE_MIN} до {WRITE_MAX}");
			Print.Encolored("Текущий диапазон фильтра:  "); Console.WriteLine($"от {min} до {max}");

			Print.Encolored("\nВведите новый диапазон фильтра:\n");
			Console.WriteLine("Минимум  :> " +
			                  "Максимум :> ");

			// Вводим новый диапазон значений.
			Console.SetCursorPosition(12, 5);
			int.TryParse(Console.ReadLine(), out min);
			Console.SetCursorPosition(12, 6);
			int.TryParse(Console.ReadLine(), out max);

			// Формируем новый фильтр значений.
			filteredShow = new FilteredShow(min, max);
		} // ChangeFilterRanges::END
		
		/// <summary> Читает и выводит значения из файла попутно зажигая событие OnNumberRead. </summary>
		public static void ShowNumbers()
		{
			try
			{
				using (var br = new BinaryReader(File.Open(FILE_NAME, FileMode.Open)))
				{
					// Читаем до конца файла.
					while (br.BaseStream.Position != br.BaseStream.Length)
					{
						// Читаем значение из файла.
						int value = br.ReadInt32();
						Events.CallOnNumberRead(typeof(Solution), value);

						// Выводим значение на экран.
						Console.Write(value + " ");
					}
				} // BinaryReader::END

				// Выводим значение счетчика четных чисел.
				Print.Encolored($"\n\nКол-во четных чисел: {evenCounter.Value}\n");

				// Счетчик справился со своей задачей. Сбрасываем его значение.
				evenCounter.Reset();
			}
			catch (FileNotFoundException)
			{
				Print.Encolored("Файл не найден!");
			}
		} // ShowTable::END
	}
}
