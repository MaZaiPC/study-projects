using System;
using System.Windows.Forms;

namespace MaZaiPC.CaseManager.WindowsForms
{
	public partial class WorkerForm : Form
	{
		private readonly HelperForm _helperForm;

		private const string TOOLTIP = "Введите текст...";

		public WorkerForm(HelperForm helperForm)
		{
			InitializeComponent();
			_helperForm = helperForm;

			linkHelp.Click += (sender, e) => _helperForm.ShowDialog();
		}
		
		public void domainUpDown1_GotFocus(object sender, EventArgs e)
		{
			if (domainUpDown1.Text == TOOLTIP)
			{
				domainUpDown1.Text = "";
				checkReverse.Enabled = true;
			}
		}

		public void domainUpDown1_LostFocus(object sender, EventArgs e)
		{
			if (string.IsNullOrWhiteSpace(domainUpDown1.Text))
			{
				domainUpDown1.Text = TOOLTIP;
				checkReverse.Enabled = false; // фикс для swap
			}
		}

		private void btnClear_Click(object sender, EventArgs e)
		{
			domainUpDown1.Text = TOOLTIP;
			
			radioUpperCase.Checked = true;
			checkReverse.Checked = false;
		}
		
		private void btnManage_Click(object sender, EventArgs e)
		{
			if (domainUpDown1.Text == TOOLTIP)
				return;
			
			// ПРОПИСНЫЕ
			if (radioUpperCase.Checked)
				domainUpDown1.Text = domainUpDown1.Text.ToUpper();
			// строчные
			else if (radioLowerCase.Checked)
				domainUpDown1.Text = domainUpDown1.Text.ToLower();
			// Начинается С Прописных
			else if (radioCapital.Checked)
				domainUpDown1.Text = Utils.Capitalize(domainUpDown1.Text);
		}

		private void checkReverse_CheckStateChanged(object sender, EventArgs e)
		{
			if (domainUpDown1.Text == TOOLTIP)
				return;

			// Изменяем порядок слов в предложении.
			domainUpDown1.Text = Utils.ReverseByWords(domainUpDown1.Text);
		}

		private void domainUpDown1_SelectedItemChanged(object sender, EventArgs e)
		{
			if (domainUpDown1.Text == TOOLTIP)
				return;
			
			// Проводим очистку от всех символов кроме пробела.
			domainUpDown1.Text = Utils.DelAllSymbols(domainUpDown1.Text);

			// Устанавливаем курсор в конец поля ввода.
			domainUpDown1.Select(domainUpDown1.Text.Length, 0);
		}
	}
}
