using System;
using System.Windows.Forms;
using MaZaiPC.CollectionsHome.WindowsForms.Tasks;

namespace MaZaiPC.CollectionsHome.WindowsForms
{
	public partial class LauncherForm : Form
	{
		public LauncherForm()
		{
			InitializeComponent();

			// Устанавливаем режим "поверх всех окон", для снижения вероятности
			// того, что мы забудем закрыть этот непримечательный лаунчер.
			TopMost = true;

			comboBox1.SelectedIndex = 0;  // выбираем 1-й элемент выпадающего списка
			btnStart.NotifyDefault(true); // устанавливаем btnStart кнопкой по умолчанию
			
			btnExit.Click += (sender, e) => Application.Exit();
		}

		private void btnStart_Click(object sender, System.EventArgs e)
		{
			this.Visible = false; // скрываем лаунчер, чтобы не мешал
			switch (comboBox1.SelectedIndex)
			{
				case 0: new Task1Form().ShowDialog(); break;
				case 1: new Task2Form().ShowDialog(); break;
				case 2: new Task3Form().ShowDialog(); break;
				case 3: new Task4Form().ShowDialog(); break;
			}
			this.Visible = true; // после закрытия выбранной задачи показываем лаунчер снова
		}
	}
}
