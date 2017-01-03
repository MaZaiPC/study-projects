using System;

using MaZaiPC.TextFiles.Service;

namespace MaZaiPC.TextFiles
{
	static class Program
	{
		static void Main()
		{
			Utils.ConfigureConsole();
			byte cmd;
			bool flagExit = false;
			
			Menu menu = new Menu(new []  {
							new MenuItem("Запуск", "Построчно считывает текст из файла, реагирует на слова из двух букв."),
							new MenuItem(Menu.SEPARATOR),
							new MenuItem("О программе", "Автор:  Иванченко А.Д. (ник MaZaiPC)\n\n" +
														"Инфо 1: Задания составлены по мотивам лабораторной работы №7\n" +
														"        из учебника Павловской Т.А.\n\n" +
														"Инфо 2: Собачку можно отключить, это не более чем забавный символьный" +
							                            " арт,\n        который находится в файле dog.ansii", active: false), 
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
							Solution.RunTask();
							break;
						case 0:
							flagExit = true;
							break;
					} // switch::END
				}
				catch (Exception ex)
				{
					Utils.PrintEncolored(ex.Message, ConsoleColor.Red);
					Utils.PrintEncolored(ex.StackTrace);
				}
				finally
				{
					if (!flagExit)
					{
						if (Console.CursorTop >= Console.WindowHeight - 1)
							Utils.Pause(0, Console.CursorTop + 2);
						else
							Utils.Pause(0, Console.WindowHeight - 1);
					}
				}
				if (flagExit) break;
			} // while::END

			Console.BackgroundColor = ConsoleColor.Black;
			Console.ForegroundColor = ConsoleColor.Gray;
			Console.Clear();
			Utils.WriteXY(Console.WindowWidth / 2 - 6, Console.WindowHeight / 2, "Конец работы");
			Console.SetCursorPosition(0, Console.WindowHeight - 1);
		} // Main::END
	}
}
