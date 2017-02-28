using System;
using Moreniell.NumManager.Common;
using Moreniell.NumManager.Common.Menu;

namespace Moreniell.NumManager
{
	internal class Program
	{
		static void Main()
		{
			Utils.ConfigureConsole();
			byte cmd;
			bool flagExit = false;
			
			Menu menu = new Menu(new []  {
							new MenuItem("Сгенерировать новый набор", "Записывает в файл новые случайные значения."),
							new MenuItem("Настроить диапазон значений фильтра", "Вы можете настроить фильтр так,\n" +
							                                                    "чтобы он срабатывал в нужном вам\n" +
							                                                    "диапазоне значений."),
							new MenuItem("Вывести значения из файла на экран", "Читает и выводит значения из файла\n" +
							                                                   "попутно зажигая событие OnNumberRead."),
							new MenuItem(Menu.SEPARATOR),
							new MenuItem("О программе", "Автор:  Иванченко А.Д. (ник Moreniell)\n\n" +
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
							Solution.FillRandomizedNumbers();
							break;
						case 2:
							Solution.ChangeFilterRanges();
							break;
						case 3:
							Solution.ShowNumbers();
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
							Utils.Pause(0, Console.CursorTop + 1);
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
