using System;

using Moreniell.Inheritance.Entities.Body;
using Moreniell.Inheritance.Entities.Currency;

namespace Moreniell.Inheritance
{
	static class Solution
	{
		public static void Task64()
		{
			Utils.PrintEncolored("Тестирование класса Parallelepiped\n\n");

			Parallelepiped ppiped = new Parallelepiped();
			Console.WriteLine($"Тестирование конструктора по-умолчанию:\n{ppiped}\n");

			ppiped = new Parallelepiped(5.25, 4.1246548, 8.46);
			Console.WriteLine($"Все данные параллелепипеда:\n{ppiped}\n");
			Console.WriteLine($"Только длины сторон: {ppiped.Size}");
			Console.WriteLine($"Только площадь: {ppiped.CalcArea()}");
			Console.WriteLine($"Только объем: {ppiped.CalcVolume()}");

			Utils.PrintEncolored("\nТестирование класса Ball\n\n");

			Ball ball = new Ball();
			Console.WriteLine($"Тестирование конструктора по-умолчанию:\n{ball}\n");

			ball = new Ball(25.62);
			Console.WriteLine($"Все данные параллелепипеда:\n{ball}\n");
			Console.WriteLine($"Только радиус: {ball.Radius}");
			Console.WriteLine($"Только площадь: {ball.CalcArea()}");
			Console.WriteLine($"Только объем: {ball.CalcVolume()}");
		}

		public static void Task65()
		{
			Utils.PrintEncolored("Тестирование класса Dollar\n\n");

			Dollar dollar = new Dollar();
			Console.WriteLine($"Тестирование конструктора по-умолчанию:\n{dollar}\n");

			dollar = new Dollar(1200.150M);
			Console.WriteLine($"Значение суммы: {dollar.Value}");
			Console.WriteLine($"Метод ToString: {dollar}");
			Console.WriteLine($"Метод ToRUR: {dollar.ToRUR()}");
			Console.WriteLine($"Метод ToEUR: {dollar.ToEUR()}");

			Utils.PrintEncolored("\nТестирование класса Euro\n\n");
			Euro euro = new Euro();
			Console.WriteLine($"Тестирование конструктора по-умолчанию:\n{euro}\n");

			euro = new Euro(875.240M);
			Console.WriteLine($"Значение суммы: {euro.Value}");
			Console.WriteLine($"Метод ToString: {euro}");
			Console.WriteLine($"Метод ToRUR: {euro.ToRUR()}");
			Console.WriteLine($"Метод ToUSD: {euro.ToUSD()}");
		}
	}
}
