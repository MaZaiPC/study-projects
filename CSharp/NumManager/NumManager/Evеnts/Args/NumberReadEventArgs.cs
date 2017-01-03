using System;

namespace MaZaiPC.NumManager.Evеnts.Args
{
	public class NumberReadEventArgs : EventArgs
	{
		public int ReadedValue { get; set; }

		public NumberReadEventArgs(int readedValue)
		{
			ReadedValue = readedValue;
		}
	}
}