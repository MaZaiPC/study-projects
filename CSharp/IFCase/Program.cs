using System;

namespace MaZaiPC.Beginning
{
	class Program
	{
		static void Main()
		{
			Utils.ConfigureConsole();
			byte cmd;
			bool flagExit = false;
			const string szMenu = "\t*** М Е Н Ю ***\n" +
			                      "1. If16\n" +
								  "2. If28\n" +
								  "3. Case14\n" +
								  "4. Case17\n" +
								  "0. Выход\n" +
			                      "   Ваш выбор (0, ..., 4)? ";

			while (true)
			{
				Console.Clear();
				
				cmd = Utils.GetByte(szMenu, 0, 4);

				Console.SetCursorPosition(0, 9);

				switch (cmd)
				{
					case 1:
						Solution.If16();
						break;
					case 2:
						Solution.If28();
						break;
					case 3:
						Solution.Case14();
						break;
					case 4:
						Solution.Case17();
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
			
			Console.BackgroundColor = ConsoleColor.Black;
			Console.ForegroundColor = ConsoleColor.Gray;
			Console.Clear();
			Utils.WriteXY(Console.WindowWidth / 2 - 6, Console.WindowHeight / 2, "Конец работы");
			Console.SetCursorPosition(0, Console.WindowHeight - 1);
		} // Main::END
	}
}
