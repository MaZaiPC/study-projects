using System;
using System.IO;
using System.Windows.Forms;

namespace Moreniell.TextAnalyzer
{
    public partial class MainForm : Form
    {
	    private string _buffer;
	    private bool _isOpened;
	    private int _opCount = 1;

        public MainForm()
        {
            InitializeComponent();
        }

		private void mniOpenText_Click(object sender, EventArgs e)
		{
			if (openFileDialog.ShowDialog() != DialogResult.OK) return;

			using (var tr = new StreamReader(openFileDialog.OpenFile()))
			{
				_buffer = tr.ReadToEnd();
				_isOpened = true;
			}
		}

		private void mniFileExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

		private void mniWordsCount_Click(object sender, EventArgs e)
		{
			if (!_isOpened) { OpenFileHint(); return; }

			// Получаем кол-во слов в тексте
			int wordsCount = _buffer
				.Split(" .,;\"'!?@#$%^&+-=/*()[]".ToCharArray(),
				StringSplitOptions.RemoveEmptyEntries).Length;

			// Выводим результат.
			WriteJournal($"Количество слов в тексте: {wordsCount}");
		}

		private void mniLetterOccurrence_Click(object sender, EventArgs e)
		{
			if (!_isOpened) { OpenFileHint(); return; }

			// Включаем интерфейс ввода буквы.
			labelCounter.Visible = true;
			charBox1.Visible = true;
			charBox1.Text = string.Empty;
			btnStart.Visible = true;
			charBox1.Focus();
		}

		private void mniAbout_Click(object sender, EventArgs e)
		{
			new AboutForm().ShowDialog();
		}

		private void WriteJournal(string what)
		{
			// Выводим текст в окно сообщений.
			richTextBox1.Text += $"\n\nОперация #{_opCount}\n\n" + what;

			// Инкрементируем счетчик выполненных операций.
			_opCount++;

			// Двигаем курсор в конец.
			richTextBox1.Select(richTextBox1.TextLength, 0);

			// Двигаем scroll-bar к курсору.
			richTextBox1.ScrollToCaret();
		}

		// Вывод подсказки на экран (используется в нескольких местах)
		private static void OpenFileHint()
	    {
		    MessageBox.Show("Сначала откройте файл с текстом!", "Подсказка",
							MessageBoxButtons.OK, MessageBoxIcon.Information);
	    }

		private void btnStart_Click(object sender, EventArgs e)
		{
			if (charBox1.TextLength == 0)
			{
				// Вывод другой подсказки на экран (используется только тут)
				MessageBox.Show("Сначала введите букву для поиска с подсчетом!", "Подсказка",
							MessageBoxButtons.OK, MessageBoxIcon.Information);
				return;
			}

			// Выключаем интерфейс ввода буквы.
			labelCounter.Visible = false;
			charBox1.Visible = false;
			btnStart.Visible = false;

			char expected = char.ToLower(charBox1.Text[0]);

			// Считаем кол-во вхождений указанной буквы.
			int counter = 0;
			foreach (char ch in _buffer) if (char.ToLower(ch)  == expected) counter++;

			// Выводим результат.
			WriteJournal($"Буква '{expected}' " +
				(counter == 0 ? "не встречается в тексте." : $"встречается в тексте {counter} раз."));
		}

		private void charBox1_TextChanged(object sender, EventArgs e)
		{
			if (charBox1.TextLength > 0 && !char.IsLetter(charBox1.Text[0]))
			{
				// Запрещаем ввод значений не являющихся буквой.
				charBox1.Clear();
			}
		}
	}
}
