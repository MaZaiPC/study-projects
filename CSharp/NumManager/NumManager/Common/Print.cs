using System;

namespace MaZaiPC.NumManager.Common
{
	public class Print
	{
		/// <summary> Выводит текст указанным цветом. </summary>
		public static void Encolored(string text, ConsoleColor fgColor = ConsoleColor.Yellow)
		{
			Encolored(text, Console.BackgroundColor, fgColor);
		}

		/// <summary> Выводит текст указанным цветом и с указанным фоном. </summary>
		public static void Encolored(string text, ConsoleColor bgColor, ConsoleColor fgColor)
		{
			ConsoleColor fgOld = Console.ForegroundColor, bgOld = Console.BackgroundColor;
			Console.BackgroundColor = bgColor;
			Console.ForegroundColor = fgColor;
			Console.Write(text);
			Console.BackgroundColor = bgOld;
			Console.ForegroundColor = fgOld;
		}

		/// <summary> Выводит текст в указанной позиции. </summary>
		public static void Position(int x, int y, string text, params object[] arguments)
		{
			Console.SetCursorPosition(x, y);
			Console.Write(text, arguments);
		}
		
		/// <summary>Заполняет указанным символом N ячеек консоли.</summary>
		public static void Fill(char symbol, uint n)
		{
			if (n > 0) n++;
			for (uint i = 1; i < n; ++i)
				Console.Write(symbol);
		}
	}
}