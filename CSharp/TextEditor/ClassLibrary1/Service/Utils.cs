using System;
using System.IO;
using System.Reflection;
using System.Text;

namespace ClassLibrary1.Service
{
	public static class Utils
	{
		/// <summary>Настраивает консоль для последующей работы.</summary>
		public static void ConfigureConsole()
		{
			// Установить заголовок окна консоли
			Console.Title = "Иванченко А. Д.  |  " + Path.GetFileName(Assembly.GetExecutingAssembly().Location).Replace(".exe", "");
			
			// Установить кодировку консоли для корректного отображения символов
			Console.OutputEncoding = Encoding.UTF8;

			Console.BackgroundColor = ConsoleColor.Black;
			Console.ForegroundColor = ConsoleColor.White;

			// TODO: Установка размера шрифта
			
			// Установить размер окна консоли
			Console.SetWindowSize(80, 25);
		}
		
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

		/// <summary> Проверяет, является ли строка целым числом. </summary>
		public static bool IsNumber(string str)
		{
			foreach (var c in str)
				if (!char.IsDigit(c)) return false;
			return true;
		}

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
