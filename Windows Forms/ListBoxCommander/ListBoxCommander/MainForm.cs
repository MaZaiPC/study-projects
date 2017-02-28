using System;
using System.Drawing;
using System.Windows.Forms;

namespace Moreniell.ListBoxCommander
{
	public partial class MainForm : Form
	{
		private readonly HelperForm _helperForm;
		private readonly Button[] _buttons;

		public MainForm()
		{
			InitializeComponent();
			_helperForm = new HelperForm();

			// Фокус заголовков делегируется на соответствующие лист-боксы.
			header1.Enter += (sender, e) => listBox1.Focus();
			header2.Enter += (sender, e) => listBox2.Focus();

			// Инициализируем массив кнопок
			// (нужен для компактности в слушателя MainForm_Resize).
			_buttons = new[]
			{
				btnCopy, btnMove,
				btnClear, btnClearBoth, btnExit
			};
		}

		// Возвращает выбранный список.
		public ListBox SelectedListBox
		{
			get { return header1.BackColor == Color.Bisque ? listBox1 : listBox2; }
		}

		// Возвращает список противоположный выбранному.
		public ListBox UnselectedListBox
		{
			get { return header1.BackColor != Color.Bisque ? listBox1 : listBox2; }
		}
		
		private void listBox1_Enter(object sender, EventArgs e)
		{
			// Помечаем левый лист активным.
			header1.BackColor = Color.Bisque;
			header2.BackColor = Color.AntiqueWhite;
		}

		private void listBox2_Enter(object sender, EventArgs e)
		{
			// Помечаем правый лист активным.
			header2.BackColor = Color.Bisque;
			header1.BackColor = Color.AntiqueWhite;
		}

		private void btnExit_Click(object sender, EventArgs e)
		{
			Application.Exit();
		}

		private void MainForm_Resize(object sender, EventArgs e)
		{
			// Фикс случая, когда минимизация ломает логику resize.
			if (this.WindowState == FormWindowState.Minimized) return;

			int cx = this.ClientSize.Width;
			int buttonWidth = cx / 6;

			/* Равномерно распределяем все кнопки по форме.
			----------------------------------------------------*/
			btnWriteLine.Width = buttonWidth;

			for (int i = 0; i < _buttons.Length; i++)
			{
				_buttons[i].Width = buttonWidth;
				_buttons[i].Location = new Point
				{
					X = buttonWidth * (i + 1),
					Y = _buttons[i].Location.Y
				};
			}
			btnExit.Width = cx - btnExit.Location.X;

			/* Выравниваем положение лист-боксов.
			----------------------------------------------------*/
			header1.Width = listBox1.Width = cx / 2 - 2;
			listBox2.Location = new Point
			{
				X = cx / 2 + 2,
				Y = listBox2.Location.Y
			};
			header2.Location = new Point
			{
				X = listBox2.Location.X,
				Y = header2.Location.Y
			};
		}

		private void btnWriteLine_Click(object sender, EventArgs e)
		{
			// Если строка пустая, то добавлять нечего. Тихо покидаем этот метод.
			if (textBox1.Text.Length == 0) return;

			// Добавляем строку в выбранный список.
			SelectedListBox.Items.Add(textBox1.Text);

			// Очищаем поле ввода.
			textBox1.Clear();

			// Для удобства устанавливаем фокус на поле ввода.
			textBox1.Focus();
		}

		private void btnCopy_Click(object sender, EventArgs e)
		{
			// Если пользователь не выбрал копируемый элемент, то тут нам делать нечего.
			if (SelectedListBox.SelectedItem == null) return;

			// Добавляем в соседний список выбранный элемент из текущего списка.
			UnselectedListBox.Items.Add(SelectedListBox.SelectedItem);
		}

		private void btnMove_Click(object sender, EventArgs e)
		{
			// Если пользователь не выбрал перемещаемый элемент, то тут нам делать нечего.
			if (SelectedListBox.SelectedItem == null) return;

			// Добавляем в соседний список выбранный элемент из текущего списка.
			UnselectedListBox.Items.Add(SelectedListBox.SelectedItem);
			// Удаляем его из текущего списка.
			SelectedListBox.Items.Remove(SelectedListBox.SelectedItem);
		}

		private void btnClear_Click(object sender, EventArgs e)
		{
			// Очищаем выбранный список.
			SelectedListBox.Items.Clear();
		}

		private void btnClearBoth_Click(object sender, EventArgs e)
		{
			// Очищаем оба списка.
			listBox1.Items.Clear();
			listBox2.Items.Clear();
		}

		private void textBox1_KeyDown(object sender, KeyEventArgs e)
		{
			// Быстрое добавление в список нажатием ENTER.
			if (e.KeyCode == Keys.Enter)
			{
				btnWriteLine_Click(this, new EventArgs());
			}
		}

		private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
		{
			// Выводим открываем диалог с "помощником".
			_helperForm.ShowDialog();
		}
	}
}
