using Moreniell.NumManager.Evеnts.Args;

namespace Moreniell.NumManager.Evеnts
{
	public delegate void NumberReadEventHandler(object sender, NumberReadEventArgs e);

	public class Events
	{
		public static event NumberReadEventHandler OnNumberRead;
		
		public static void CallOnNumberRead(object sender, int readedValue)
		{
			if (OnNumberRead != null) OnNumberRead(sender, new NumberReadEventArgs(readedValue));
		}
	}
}