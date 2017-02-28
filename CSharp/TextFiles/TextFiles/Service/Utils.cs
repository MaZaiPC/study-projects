using System;
using System.IO;
using System.Reflection;
using System.Text;
using System.Threading;

namespace Moreniell.TextFiles.Service
{
	static class Utils
	{
		/// <summary>Настраивает консоль для последующей работы.</summary>
		public static void ConfigureConsole()
		{
			// Установить заголовок окна консоли
			Console.Title = "Иванченко А. Д.  |  " + Path.GetFileName(Assembly.GetExecutingAssembly().Location).Replace(".exe", "");

			// Загрузочный экран - Собачка :3
			StartScreen();

			// Установить кодировку консоли для корректного отображения символов
			Console.OutputEncoding = Encoding.UTF8;

			Console.BackgroundColor = ConsoleColor.Black;
			Console.ForegroundColor = ConsoleColor.White;

			// TODO: Установка размера шрифта
			
			// Установить размер окна консоли
			Console.SetWindowSize(80, 25);
		}

		/// <summary>Получает значение удовлетворяющее заданному диапазону.</summary>
		public static byte GetByte(string prompt, byte min, byte max)
		{
			byte x;
			while (true)
			{
				Console.Write(prompt);

				// Проверка корректности типа ввода
				if (!byte.TryParse(Console.ReadLine(), out x))
				{
					Console.WriteLine("\nОШИБКА: Вводите число, не символы.\n");
					Pause();
					Console.Clear();
					continue;
				}

				// Если число не принадлежит диапазону допустимых значений,
				// сообщить об ошибке и повторить ввод
				if (x < min || x > max)
				{
					Console.WriteLine("\nОШИБКА: Число должно быть в диапазоне от " +
									  min + " до " + max + ".\n\n");
					Pause();
					Console.Clear();
					continue;
				}

				// Если оказались тут - число в корректном диапазоне
				break;
			} // while::END

			return x;
		} // GetByte::END

		/// <summary>Выводит сообщение паузы в указанной позиции.</summary>
		public static int Pause(int left, int top, string text = "Для продолжения нажмите любую клавишу . . . ")
		{
			Console.SetCursorPosition(left, top);
			return Pause(text);
		} // Pause::END

		/// <summary>Выводит сообщение паузы.</summary>
		public static int Pause(string text = "Для продолжения нажмите любую клавишу . . . ")
		{
			int cpX = Console.CursorLeft, cpY = Console.CursorTop;
			Console.Write(text);
			int key = Console.ReadKey().KeyChar;
			if (key <= 0 || key == 224) key = Console.ReadKey().KeyChar;
			Console.SetCursorPosition(cpX, cpY);
			Fill(' ', (uint)text.Length);
			Console.SetCursorPosition(cpX, cpY);
			return key;
		} // Pause::END

		/// <summary>Заполняет указанным символом N ячеек консоли.</summary>
		public static void Fill(char symbol, uint n)
		{
			if (n > 0) n++;
			for (uint i = 1; i < n; ++i)
				Console.Write(symbol);
		} // Fill::END

		/// <summary>Выводит текст в указанной позиции.</summary>
		public static void WriteXY(int x, int y, string text, params object[] arguments)
		{
			Console.SetCursorPosition(x, y);
			Console.Write(text, arguments);
		} // WriteXY::END

		/// <summary>Выводит текст указанным цветом.</summary>
		public static void PrintEncolored(string text, ConsoleColor fgColor = ConsoleColor.Yellow)
		{
			PrintEncolored(text, Console.BackgroundColor, fgColor);
		}

		/// <summary>Выводит текст указанным цветом и с указанным фоном.</summary>
		public static void PrintEncolored(string text, ConsoleColor bgColor, ConsoleColor fgColor)
		{
			ConsoleColor fgOld = Console.ForegroundColor, bgOld = Console.BackgroundColor;
			Console.BackgroundColor = bgColor;
			Console.ForegroundColor = fgColor;
			Console.Write(text);
			Console.BackgroundColor = bgOld;
			Console.ForegroundColor = fgOld;
		} // WriteXY::END

		public static void StartScreen()
		{
			try
			{
				Console.BackgroundColor = ConsoleColor.White;
				Console.ForegroundColor = ConsoleColor.Black;

				StringBuilder[] dog = { new StringBuilder(), new StringBuilder() };

				StreamReader sr = new StreamReader(File.OpenRead(@"..\..\dog.ansii"), Encoding.Unicode);

				int i, step;
				for (i = 0; i < 2; ++i)
					for (int j = 0; j < 19; ++j)
						dog[i].Append("\t\t").Append(sr.ReadLine()).Append("\n");
				sr.Dispose(); // sr.Close();

				for (i = 0; i < 4; ++i)
				{
					step = 20 * (i + 1);

					PrintDog(dog[0], step - 5);
					PrintDog(dog[1], step);
				}
			}
			catch (Exception ex)
			{
				// ignored
			}
		}

		private static void PrintDog(StringBuilder dog, int step)
		{
			Console.Clear();
			Console.WriteLine($"\n{dog}\n");
			PrintEncolored(new string('░', 80), ConsoleColor.Black, ConsoleColor.White);
			Console.CursorTop -= 1;
			PrintEncolored(new string('▓', step - 5), ConsoleColor.DarkGreen);
			Thread.Sleep(200);
		}
	}
}
