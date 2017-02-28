using System;
using System.IO;
using System.Reflection;
using System.Text;
using static System.Math;

namespace Moreniell.SolveMethods
{
	public static class Utils
	{
		private static ArgumentException triangleEx = new ArgumentException("Указанного треугольника не существует!");

		/// <summary> Проверяет существует ли указанный треугольник. </summary>
		public static bool IsTriangle(double a, double b, double c)
		{
			return a + b > c && a + c > b && b + c > a && a > 0D && b > 0D && c > 0D;
		}

		/// <summary> Вычисляет периметр треугольника. </summary>
		public static double TrianglePerimeter(double a, double b, double c)
		{
			if (!IsTriangle(a, b, c)) throw triangleEx;
			return a + b + c;
		}

		/// <summary> Вычисляет площадь треугольника. </summary>
		public static double TriangleArea(double a, double b, double c)
		{
			if (!IsTriangle(a, b, c)) throw triangleEx;
			double p = (a + b + c)/2;
			return Sqrt(p*(p - a)*(p - b)*(p - c));
		}

		/// <summary> Вычисляет корень линейного уравнения. </summary>
		public static bool RootLinear(double a, double b, out double x)
		{
			if (a == 0D)
			{
				// Если решения нет
				if (b != 0D) {
					x = 0;
					return false;
				}

				// Уравнение имеет бесконечное множество решений
				x = double.PositiveInfinity;
				return true;
			}

			// Решаем уравнение.
			x = b / a;
			return true;
		} // RootLinear::END

		/// <summary> Вычисляет корни квадратного уравнения. </summary>
		public static bool RootSquare(double a, double b, double c, out double x1, out double x2)
		{
			double d = b*b - 4*a*c;

			if (a != 0D && d >= 0D)
			{
				// Когда D == 0, x1 будет равно x2
				x1 = (-b + Sqrt(d)) / (2D * a);
				x2 = (-b - Sqrt(d)) / (2D * a);
				return true;
			}
			x1 = x2 = 0;
			return false;
		} // RootSquare::END

		/// <summary> Вычисляет сумму первых n членов геометрической прогрессии. </summary>
		public static double GeometricProgressionSumma(double b1, double q, uint n)
		{
			// if (q == 1D) return n*b1;
			return b1*(1 - Pow(q, n))/(1 - q);
		}

		/// <summary> Конвертирует время из указанной единицы измерения в секунды. </summary>
		public static uint ConvertToSeconds(uint time, TimeEntity entity)
		{
			switch (entity)
			{
				case TimeEntity.Hour:
					return time*3600;
				case TimeEntity.Minute:
					return time*60;
				case TimeEntity.Second:
					return time;
				case TimeEntity.Millisecond:
					return time/1000;
				default:
					throw new ArgumentOutOfRangeException(nameof(entity), entity, null);
			}
		} // ConvertToSeconds::END

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

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
