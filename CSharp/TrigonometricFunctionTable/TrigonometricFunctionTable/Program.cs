using System;
using MaZaiPC.TrigonometricFunctionTable.Common;
using MaZaiPC.TrigonometricFunctionTable.Common.Menu;

namespace MaZaiPC.TrigonometricFunctionTable
{
	static class Program
	{
		static void Main()
		{
			Utils.ConfigureConsole();
			byte cmd;
			bool flagExit = false;
			
			Menu menu = new Menu(new []  {
							new MenuItem("Настроить диапазон значений"),
							new MenuItem("Показать таблицу"),
							new MenuItem(Menu.SEPARATOR),
							new MenuItem("О программе", "Автор:  Иванченко А.Д. (ник MaZaiPC)\n\n" +
                                                        "Таблица синусов и косинусов.", active: false), 
						});

			while (true)
			{
				try
				{
					Console.Clear();

					cmd = menu.GetChoice();

					switch (cmd)
					{
						case 1:
							Solution.GetRanges();
							break;
						case 2:
							Solution.ShowTable();
							break;
						case 0:
							flagExit = true;
							break;
					} // switch::END
				}
				catch (Exception ex)
				{
					Print.Encolored(ex.Message, ConsoleColor.Red);
					Print.Encolored(ex.StackTrace);
				}
				finally
				{
					if (!flagExit)
					{
						if (Console.CursorTop >= Console.WindowHeight - 1)
							Utils.Pause(Console.WindowWidth-46, 0);
						else
							Utils.Pause(0, Console.WindowHeight - 1);
					}
				}
				if (flagExit) break;
			} // while::END

			Console.BackgroundColor = ConsoleColor.Black;
			Console.ForegroundColor = ConsoleColor.Gray;
			Console.Clear();
			Print.Position(Console.WindowWidth / 2 - 6, Console.WindowHeight / 2, "Конец работы");
			Console.SetCursorPosition(0, Console.WindowHeight - 1);
		} // Main::END
	}
}
