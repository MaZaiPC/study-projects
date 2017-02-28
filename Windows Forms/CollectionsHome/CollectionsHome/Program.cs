using System;
using System.Windows.Forms;
using Moreniell.CollectionsHome.WindowsForms;

namespace Moreniell.CollectionsHome
{
	static class Program
	{
		/// <summary>
		/// Главная точка входа для приложения.
		/// </summary>
		[STAThread]
		private static void Main()
		{
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			Application.Run(new LauncherForm());
		}
	}
}
