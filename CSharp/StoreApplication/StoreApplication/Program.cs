using System;
using MaZaiPC.StoreApplication.Entities;
using MaZaiPC.StoreApplication.Entities;
using MaZaiPC.StoreApplication.Service;

namespace MaZaiPC.StoreApplication
{
	static class Program
	{
		static void Main()
		{
			Utils.ConfigureConsole();
			byte cmd;
			bool flagExit = false;
			
			Menu menu = new Menu(new []  {
							new MenuItem("Добавить новый товар"),
							new MenuItem("Найти товар"),
							new MenuItem("Прайс-лист"),
							new MenuItem("Упорядочить записи по алфавиту"),
							new MenuItem(Menu.SEPARATOR),
							new MenuItem("О программе", "Автор:  Иванченко А.Д. (ник MaZaiPC)\n\n" +
														"Добро пожаловать в наш магазин!", active: false), 
						});

			Store store = new Store("Пятерочка");

			while (true)
			{
				try
				{
					Console.Clear();

					cmd = menu.GetChoice();

					switch (cmd)
					{
						case 1:
							store.NewPrice();
							break;
						case 2:
							store.FindPrice();
							break;
						case 3:
							store.ShowPriceList();
							break;
						case 4:
							store.Sort();
							break;
						case 0:
							flagExit = true;
							break;
					} // switch::END
				}
				catch (Exception ex)
				{
					Utils.PrintEncolored("\n"+ex.Message, ConsoleColor.Red);
					//Utils.PrintEncolored(ex.StackTrace);
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

			// Закрываем все управляемые ресурсы.
			store.Close();
			
			Console.BackgroundColor = ConsoleColor.Black;
			Console.ForegroundColor = ConsoleColor.Gray;
			Console.Clear();
			Utils.WriteXY(Console.WindowWidth / 2 - 6, Console.WindowHeight / 2, "Конец работы");
			Console.SetCursorPosition(0, Console.WindowHeight - 1);
		} // Main::END
	}
}
