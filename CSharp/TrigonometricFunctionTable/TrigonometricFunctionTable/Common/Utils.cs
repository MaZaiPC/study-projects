using System;
using System.IO;
using System.Reflection;
using System.Text;

namespace MaZaiPC.TrigonometricFunctionTable.Common
{
	static class Utils
	{
		/// <summary>Настраивает консоль для последующей работы.</summary>
		public static void ConfigureConsole()
		{
			// Установить заголовок окна консоли
			Console.Title = "Иванченко А. Д.  |  " + Path.GetFileName(Assembly.GetExecutingAssembly().Location)
														 .Replace(".exe", "");
			
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
			Print.Fill(' ', (uint)text.Length);
			Console.SetCursorPosition(cpX, cpY);
			return key;
		} // Pause::END
		
		/// <summary> Проверяет, является ли строка целым числом. </summary>
		public static bool IsNumber(string str)
		{
			foreach (var c in str)
				if (!char.IsDigit(c)) return false;
			return true;
		}
		
		public static double RadiansToDegree(double angle)
		{
			return 180D/Math.PI*angle;
		}

		public static double DegreeToRadians(double angle)
		{
			return Math.PI*angle/180D;
		}
	}
}
