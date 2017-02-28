using System;

namespace Moreniell.SolveMethods
{
	static class Solution
	{
		public static void Task1()
		{
			double p = Utils.TrianglePerimeter(5D, 5D, 5D);
			Console.WriteLine("Периметр треугольника {5;5;5} == " + p);
		}

		public static void Task2()
		{
			double s = Utils.TriangleArea(7D, 9D, 7D);
			Console.WriteLine("Площадь треугольника {7;9;7} == " + s);
		}

		public static void Task3()
		{
			double a, b, x;
			a = 2D;
			b = 4D;

			string str = $"Линейное уравнение {a}x + {b} = 0 ";
			bool state = Utils.RootLinear(a, b, out x);

			if (state)
			{
				if (double.IsInfinity(x))
					str += "имеет бесконечное множество решений";
				else
					str += $"| x = {x}";
			}
			else
				str += "не имеет решения";

			Console.WriteLine(str);
		}

		public static void Task4()
		{
			double a, b, c, x1, x2;
			//a = 2D;
			//b = -0.5;
			//c = 2.2;
			a = 2D;
			b = 4D;
			c = -7D;

			string str = $"Квадратное уравнение {a}x^2 - {b} + {c} = 0 ";
			bool state = Utils.RootSquare(a, b, c, out x1, out x2);

			if (state)
			{
				if (x1 == x2)
					str += $"| x = {x1}";
				else
					str += $"| x1 = {x1:f2}, x2 = {x2:f2}";
			}
			else
				str += "не имеет решения";

			Console.WriteLine(str);
		}

		public static void Task5()
		{
			double s = Utils.GeometricProgressionSumma(27D, 1D/3D, 4);
			Console.WriteLine("Геометрическая прогрессия b1 = 27; q = 1/3 | n = 4 | Ответ: " + s);
		}

		public static void Task6()
		{
			TimeEntity cmd;
			uint time;
			const string szChoice = "Что будем конвертировать?\n\n" +
									"1. Часы\n" +
									"2. Минуты\n" +
									"3. Секунды\n" +
									"4. Миллисекунды\n" +
									"   Ваш выбор (1, ..., 4)? ";

			
			cmd = (TimeEntity)(Utils.GetByte(szChoice, 1, 4) - 1);

			Console.Write("\nВведите кол-во " + GetTimeEntityStr(cmd, false) + " :> ");
			uint.TryParse(Console.ReadLine(), out time);
			Console.Write($"\n{time}");
			Utils.PrintEncolored($"{GetTimeEntityStr(cmd)}", ConsoleColor.Cyan);
			Console.Write($" = {Utils.ConvertToSeconds(time, cmd)}");
			Utils.PrintEncolored("с\n", ConsoleColor.Cyan);
		} // Task6::END

		private static string GetTimeEntityStr(TimeEntity entity, bool abbr = true)
		{
			switch (entity)
			{
				case TimeEntity.Hour:
					return abbr ? "ч" : "часов";
				case TimeEntity.Minute:
					return abbr ? "м" : "минут";
				case TimeEntity.Second:
					return abbr ? "с" : "секунд";
				case TimeEntity.Millisecond:
					return abbr ? "мс" : "миллисекунд";
				default:
					throw new ArgumentOutOfRangeException(nameof(entity), entity, null);
			}
		}
	}
}
