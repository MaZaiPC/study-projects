using System;
using System.Reflection;

namespace Moreniell.TextFiles
{
	public class Events
	{
		public static event EventHandler OnPairLetters;
		
		public static void CallOnPairLetters()
		{
			if (OnPairLetters != null) OnPairLetters(typeof(Events), EventArgs.Empty);
		}
	}
}