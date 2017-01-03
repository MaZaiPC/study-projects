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
							new MenuItem("Ввести новый маршрут"),
							new MenuItem("Показать информацию о маршруте"),
							new MenuItem("Показать все маршруты"),
							new MenuItem("Упорядочить файл по номерам маршрутов"),
							new MenuItem(Menu.SEPARATOR),
							new MenuItem("О программе", "Автор:  Иванченко А.Д. (ник MaZaiPC)\n\n" +
														"Небольшой менеджер маршрутов.", active: false), 
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
							Solution.EnterNewMarsh();
							break;
						case 2:
							Solution.GetMarshInfo();
							break;
						case 3:
							Solution.ShowAll();
							break;
						case 4:
							Solution.SortFileByNumbers();
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
