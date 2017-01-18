using System.Windows;

namespace MaZaiPC.Variant14
{
	/// <summary>
	/// Логика взаимодействия для MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
		}

		private void ExitButton_Click(object sender, RoutedEventArgs e)
		{
			Application.Current.Shutdown();
		}

		private void RunProgrammButton_Click(object sender, RoutedEventArgs e)
		{
			WorkWindow win = new WorkWindow();
			win.ShowDialog();
		}
	}
}
