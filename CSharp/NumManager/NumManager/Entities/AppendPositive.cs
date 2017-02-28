using System;
using System.IO;
using Moreniell.NumManager.Common;
using Moreniell.NumManager.Evеnts;
using Moreniell.NumManager.Evеnts.Args;

namespace Moreniell.NumManager.Entities
{
	internal class AppendPositive
	{
		// Путь к файлу с положительными числами.
		private const string FILE_NAME = @"..\..\positive.bin";
		
		public AppendPositive()
		{
			if (!File.Exists(FILE_NAME)) File.Create(FILE_NAME).Close();

			Events.OnNumberRead += Events_OnNumberRead;
		}

		~AppendPositive()
		{
			Events.OnNumberRead -= Events_OnNumberRead;
		}

		private void Events_OnNumberRead(object sender, NumberReadEventArgs e)
		{
			if (e.ReadedValue > 0)
			{
				// Добавляем значение в конец файла положительных чисел.
				using (var bw = new BinaryWriter(File.Open(FILE_NAME, FileMode.Append)))
					bw.Write(e.ReadedValue);

				// Выводим сообщение о том, что запись прошла успешно.
				Print.Encolored("\nAddNumber: ", ConsoleColor.Cyan);
				Console.WriteLine($"Обнаружено положительное число {e.ReadedValue}, дозаписано в файл \"positive.bin\".");
			}
		}
	}
}