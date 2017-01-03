using System;
using System.Windows.Forms;

namespace MaZaiPC.CaseManager.WindowsForms
{
	public partial class HelperForm : Form
	{
		const string NEG_ANSWER = "Не понятно";

		public HelperForm()
		{
			InitializeComponent();
		}
		
		private void button2_MouseEnter(object sender, EventArgs e)
		{
			if (button2.Text == NEG_ANSWER)
				SwapButtons();
		}

		private void button1_MouseEnter(object sender, EventArgs e)
		{
			if (button1.Text == NEG_ANSWER)
				SwapButtons();
		}

		private void SwapButtons()
		{
			string temp = button1.Text;
			button1.Text = button2.Text;
			button2.Text = temp;
		}

		private void HelperForm_Load(object sender, EventArgs e)
		{
			if (button1.Text == NEG_ANSWER)
				SwapButtons();
		}
	}
}
