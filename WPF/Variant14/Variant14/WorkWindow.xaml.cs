using System;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace Moreniell.Variant14
{
	/// <summary>
	/// Логика взаимодействия для WorkWindow.xaml
	/// </summary>
	public partial class WorkWindow : Window
	{
		public WorkWindow()
		{
			InitializeComponent();
		}

		private double CalcLength()
		{
			return Math.Sqrt(Math.Pow(double.Parse(X2.Text) - double.Parse(X1.Text), 2) +
							 Math.Pow(double.Parse(Y2.Text) - double.Parse(Y1.Text), 2));
		}

		private double CalcKoef()
		{
			return (double.Parse(Y2.Text) - double.Parse(Y1.Text)) /
				   (double.Parse(X2.Text) - double.Parse(X1.Text));
		}
		
		private void button_Click(object sender, RoutedEventArgs e)
		{
			string msg = "";

			if (IsLengthIncluded.IsChecked.Value)
				msg += $"Длина отрезка: {CalcLength()}\n";
			if (IsKoefIncluded.IsChecked.Value)
				msg += $"Угловой коэффициент: \n{CalcKoef()}";
			MessageBox.Show(msg, "Результат");
		}
		
		private void checkbox_Checked(object sender, RoutedEventArgs e)
		{
			if (IsValidFields)
			{
				ProceedButton.IsEnabled = true;
			}
		}

		private void checkbox_Unchecked(object sender, RoutedEventArgs e)
		{
			if (!IsValidCheckBoxs)
			{
				ProceedButton.IsEnabled = false;
			}
		}
		
		private void textBox_PreviewTextInput(object sender, TextCompositionEventArgs e)
		{
			double result;
			if (!double.TryParse(e.Text, out result) && (e.Text != "," || ((TextBox) sender).Text.Count(x => x == ',') >= 1))
			{
				e.Handled = true;
			}
		}

		private void textBox_TextChanged(object sender, TextChangedEventArgs e)
		{
			ProceedButton.IsEnabled = IsValidFields && IsValidCheckBoxs;
		}

		public bool IsValidCheckBoxs =>
			IsLengthIncluded.IsChecked.Value || IsKoefIncluded.IsChecked.Value;

		public bool IsValidFields =>
			X1.Text.Length > 0 && Y1.Text.Length > 0 && X2.Text.Length > 0 && Y2.Text.Length > 0;
	}
}
