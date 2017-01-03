using System;
using MaZaiPC.NumManager.Common;
using MaZaiPC.NumManager.Evеnts;
using MaZaiPC.NumManager.Evеnts.Args;

namespace MaZaiPC.NumManager.Entities
{
	internal class FilteredShow
	{
		public int Min { get; set; }
		public int Max { get; set; }

		public FilteredShow(int min, int max)
		{
			Min = min;
			Max = max;
			Events.OnNumberRead += Events_OnNumberRead;
		}

		~FilteredShow()
		{
			Events.OnNumberRead -= Events_OnNumberRead;
		}

		private void Events_OnNumberRead(object sender, NumberReadEventArgs e)
		{
			if (e.ReadedValue >= Min && e.ReadedValue <= Max)
			{
				// Вывод на экран числа удовлетворяющего заданному диапазону.
				Print.Encolored("\nFilteredShow: ", ConsoleColor.Magenta);
				Console.WriteLine($"Число {e.ReadedValue} удовлетворяет диапазону от {Min} до {Max}!\n");
			} // endif
		}
	}
}