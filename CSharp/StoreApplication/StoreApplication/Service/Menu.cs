using System;
using System.Runtime.InteropServices;
using System.Threading;

namespace Moreniell.StoreApplication.Service
{
	class Menu
	{
		/// <summary> При полном совпадении имени элемента с этой строкой он будет трактоваться как разделитель. </summary>
		public const string SEPARATOR = "$_SEPARATOR_$";

		private readonly MenuItem[] items;
		private int startPos;

		public char SeparatorChar { get; set; }
		
		public Menu(MenuItem[] items)
		{
			this.items = items;
		}

		/// <summary> Выводит меню. После выбора пункта возвращает его порядковый номер. </summary>
		public byte GetChoice()
		{
			// Скрываем курсор.
			Console.CursorVisible = false;

			ConsoleKey code;
			byte choice = 1;

			bool redraw = true;

			while (true)
			{
				if (redraw)
					PrintMenu(choice);

				// Разрешаем перерисовку содержимого в следующей итерации.
				redraw = true; 

				code = Console.ReadKey().Key;
				
				switch (code)
				{
					// Клавиши вверх/вниз, для движения по меню
					case ConsoleKey.W:
					case ConsoleKey.UpArrow:
						do {
							if (choice > 1)
								choice--; // выбираем предыдущий пункт
							else
								redraw = false; // запрещаем перерисовку содержимого в следующей итерации

						// Пропускаем все разделители, т.к. выбирать их нет смысла.
						} while (items[choice - 1].Name == SEPARATOR && choice > 1);
						
						continue;
					case ConsoleKey.S:
					case ConsoleKey.DownArrow:
						do {
							if (choice < items.Length)
								choice++; // выбираем следующий пункт
							else
								redraw = false;
						} while (items[choice - 1].Name == SEPARATOR && choice < items.Length);
						continue;

					// Клавиша активации элемента меню
					case ConsoleKey.Enter:
						if (items[choice - 1].Active)
						{
							// Восстанавливаем курсор.
							Console.CursorVisible = true;

							// Переходим в начало пункта.
							Console.SetCursorPosition(3, startPos + 2 + choice);
							
							// Перерисовываем его другим цветом.
							Utils.PrintEncolored($"• {items[choice - 1].Name}", ConsoleColor.Magenta);

							// Небольшая пауза. Как результат получаем эффект активации элемента меню при подтверждении выбора.
							Thread.Sleep(80);
							
							// Очищаем экран.
							Console.Clear();
							return choice;
						}
						continue;

					// По этим клавишам отсылаем признак завершения программы
					case ConsoleKey.NumPad0:
					case ConsoleKey.Escape:
						return 0;
				}
			}
		}

		private void PrintMenu(byte choice)
		{
			string line = new string('═', 76);

			// Очищаем экран.
			Console.Clear();

			// Просто выводим надпись "Меню".
			Console.Write("\t\t\t __  __ \n" +
						  "\t\t\t|  \\/  |\n" +
						  "\t\t\t| \\  / | ___ _ __  _   _\n" +
						  "\t\t\t| |\\/| |/ _ \\ '_ \\| | | |\n" +
						  "\t\t\t| |  | |  __/ | | | |_| |\n" +
						  "\t\t\t|_|  |_|\\___|_| |_|\\__,_|\n");

			startPos = Console.CursorTop + 1;
			Console.SetCursorPosition(0, startPos);

			Console.WriteLine("   ESC или Numpad0 для выхода");

			// Рисуем границы меню.
			Utils.PrintEncolored($" ╔{line}╗\n", ConsoleColor.White);
			for (int i = 0; i < items.Length + 2; i++)
				Utils.PrintEncolored($" ║{new string(' ', 76)}║\n", ConsoleColor.White);
			Utils.PrintEncolored($" ╚{line}╝\n", ConsoleColor.White);

			// Заполняем область меню элементами.
			for (int i = 0; i < items.Length; i++)
			{
				if (i == choice - 1)
				{
					// Помечаем выбранный элемент
					Console.SetCursorPosition(3, startPos + 3 + i);
					Utils.PrintEncolored("● ", ConsoleColor.Red);
					Utils.PrintEncolored(items[i].Name, items[i].Active ? ConsoleColor.Yellow : ConsoleColor.Gray );
					
					// Выводим подсказку.
					Utils.WriteXY(3, startPos + items.Length + 5, items[i].Tooltip);
				}
				else
				{
					Utils.WriteXY(5, startPos + 3 + i, items[i].Name == SEPARATOR ? new string(SeparatorChar, 15)
						.Trim('\n', '\t') : items[i].Name);
				}
					
			}

			// Если описание выделенного пункта длиннее высоты окна, то
			// сбрасываем координаты курсора в ноль.
			if (Console.CursorTop >= Console.WindowHeight - 1)
				Console.SetCursorPosition(0, 0);
		}
	}
}