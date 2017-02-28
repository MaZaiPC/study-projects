using System;

namespace Moreniell.SolveMethods
{
	static class Program
	{
		static void Main()
		{
			Utils.ConfigureConsole();
			byte cmd;
			bool flagExit = false;
			const string szMenu = "\t*** М Е Н Ю ***\n" +
								  "1. Периметр треугольника\n" +
								  "2. Площадь треугольника\n" +
								  "3. Корень лин. уравнения\n" +
								  "4. Корень кв. уравнения\n" +
								  "5. Сумма геомет. прогрессии\n" +
								  "6. Конвертер в секунды\n" +
								  "0. Выход\n" +
								  "   Ваш выбор (0, ..., 6)? ";

			try
			{
				while (true)
				{
					Console.Clear();

					cmd = Utils.GetByte(szMenu, 0, 6);

					Console.WriteLine("\n");

					switch (cmd)
					{
						case 1:
							Solution.Task1();
							break;
						case 2:
							Solution.Task2();
							break;
						case 3:
							Solution.Task3();
							break;
						case 4:
							Solution.Task4();
							break;
						case 5:
							Solution.Task5();
							break;
						case 6:
							Solution.Task6();
							break;
						case 0:
							flagExit = true;
							break;
					} // switch::END
					if (flagExit) break;

					if (Console.CursorTop >= Console.WindowHeight - 1)
						Utils.Pause(0, Console.CursorTop + 2);
					else
						Utils.Pause(0, Console.WindowHeight - 1);

				} // while::END
			}
			catch (Exception ex)
			{
				Utils.PrintEncolored(ex.Message, ConsoleColor.Red);
				Utils.Pause();
			}

			Console.BackgroundColor = ConsoleColor.Black;
			Console.ForegroundColor = ConsoleColor.Gray;
			Console.Clear();
			Utils.WriteXY(Console.WindowWidth / 2 - 6, Console.WindowHeight / 2, "Конец работы");
			Console.SetCursorPosition(0, Console.WindowHeight - 1);
		} // Main::END
	}
}
