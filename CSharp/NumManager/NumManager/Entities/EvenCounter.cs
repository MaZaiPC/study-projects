using MaZaiPC.NumManager.Evеnts;
using MaZaiPC.NumManager.Evеnts.Args;

namespace MaZaiPC.NumManager.Entities
{
	internal class EvenCounter
	{
		public int Value { get; private set; }
		
		public EvenCounter()
		{
			Events.OnNumberRead += Events_OnNumberRead;
		}

		~EvenCounter()
		{
			Events.OnNumberRead -= Events_OnNumberRead;
		}

		/// <summary> Сбрасывает значение счетчика. </summary>
		public void Reset()
		{
			Value = 0;
		}

		public void Events_OnNumberRead(object sender, NumberReadEventArgs e)
		{
			// Если значение кратно двум, то инкрементируем счетчик.
			if (e.ReadedValue % 2 == 0) Value++;
		}
	}
}