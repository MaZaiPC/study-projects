using System;

namespace Moreniell.NumManager.Evеnts.Args
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