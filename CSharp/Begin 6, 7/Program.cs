using System;

namespace MaZaiPC.Beginning
{
	class Program
	{
		static void Begin6()
		{
			// Вывод задания
			Utils.PrintEncolored("ТЗ:");
			Console.WriteLine("\nДаны длины ребер a, b, c прямоугольного параллелепипеда.\nНайти " +
								"его объем V = a·b·c и площадь поверхности S = 2·(a·b + b·c + a·c)\n");

			// Объявление переменных
			double a, b, c, v, s;
			int posY;

			
			Utils.PrintEncolored("Введите длины:\n");
			posY = Console.CursorTop;
			Console.WriteLine("Ребро a :>\nРебро b :>\nРебро c :>");

			// Ввод данных
			Console.SetCursorPosition(11, posY);
			double.TryParse(Console.ReadLine(), out a);
			Console.SetCursorPosition(11, posY+1);
			double.TryParse(Console.ReadLine(), out b);
			Console.SetCursorPosition(11, posY+2);
			double.TryParse(Console.ReadLine(), out c);

			// OR: throw new Exception(...)
			if (a <= 0D || b <= 0D || c <= 0D)
			{
				Console.WriteLine("\nОШИБКА: Длина ребра(ер) не может быть меньше либо равной нулю");
				return;
			}

			// Вычисление искомых значений
			v = a*b*c;
			s = 2*(a*b + b*c + a*c);

			// Вывод результатов
			Console.WriteLine("Объем параллелепипеда: {0:f2}", v);
			Console.WriteLine("Площадь поверхности: {0:f2}", s);
		} // Begin6::END

		static void Begin7()
		{
			// Вывод задания
			Utils.PrintEncolored("ТЗ:");
			Console.WriteLine("\nНайти длину окружности L и площадь круга S заданного радиуса R:" +
								"\nL = 2·π·R,\nS = π·R^2\n");

			// Объявление переменных
			double r, l, s;
			
			// Ввод данных
			Console.Write("Введите радиус :> ");
			double.TryParse(Console.ReadLine(), out r);
			
			// OR: throw new Exception(...)
			if (r <= 0D)
			{
				Console.WriteLine("\nОШИБКА: Радиус не может быть меньше либо равным нулю");
				return;
			}

			// Вычисление искомых значений
			l = 2*Math.PI*r;
			s = Math.PI*r*r;

			// Вывод результатов
			Console.WriteLine($"Длина окружности: {l:f2}", l);
			Console.WriteLine($"Площадь круга: {s:f2}", s);
		} // Begin7::END

		static void Main(string[] args)
		{
			Utils.ConfigureConsole();
			uint cmd;
			bool flagExit = false;
			const string szMenu = "\t*** М Е Н Ю ***\n" +
			                      "1. Begin6\n" +
								  "2. Begin7\n" +
			                      "0. Выход\n" +
			                      "   Ваш выбор (0, ..., 2)? ";

			while (true)
			{
				Console.Clear();

				cmd = Utils.GetUint(szMenu, 0, 2);

				Console.SetCursorPosition(0, 7);

				switch (cmd)
				{
					case 1:
						Begin6();
						break;
					case 2:
						Begin7();
						break;
					case 0:
						flagExit = true;
						break;
				} // switch::END
				if (flagExit) break;
				Utils.Pause(0, Console.WindowHeight - 1);
			} // while::END
			
			Console.BackgroundColor = ConsoleColor.Black;
			Console.ForegroundColor = ConsoleColor.Gray;
			Console.Clear();
			Utils.WriteXY(Console.WindowWidth / 2 - 6, Console.WindowHeight / 2, "Конец работы");
			Console.SetCursorPosition(0, Console.WindowHeight - 1);
		} // Main::END
	}
}
