using System;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace MaZaiPC.Inheritance
{
	static class Utils
	{
		/// <summary>Настраивает консоль для последующей работы.</summary>
		public static void ConfigureConsole()
		{
			// Установить кодировку консоли для корректного отображения символов
			Console.OutputEncoding = Encoding.UTF8;

			Console.BackgroundColor = ConsoleColor.DarkBlue;
			Console.ForegroundColor = ConsoleColor.White;

			// TODO: Установка размера шрифта

			// Установить заголовок окна консоли
			Console.Title = "Иванченко А. Д.  |  " + Path.GetFileName(Assembly.GetExecutingAssembly().Location).Replace(".exe", "");
			
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
	}
}
