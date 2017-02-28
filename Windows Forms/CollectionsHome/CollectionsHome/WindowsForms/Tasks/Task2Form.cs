using System;
using System.Collections.Generic;
using System.Windows.Forms;
using Moreniell.CollectionsHome.Common;

namespace Moreniell.CollectionsHome.WindowsForms.Tasks
{
	public partial class Task2Form : Form
	{
		private readonly Stack<int> _stack1 = new Stack<int>();
		private readonly Stack<int> _stack2 = new Stack<int>();
		private readonly Stack<int> _stack3 = new Stack<int>();

		private bool _isFulfilled; // выполнено ли моделирование

		public Task2Form()
		{
			InitializeComponent();
			GenerateInitialSet();  // генерируем начальные данные
			UpdateControlsState(); // обновляем графику
		}
		
		private void RunModelling()
		{
			int len = _stack1.Count;
			for (int i = 0; i < len; ++i)
			{
				(_stack1.Peek()%2 == 0 ? _stack2 : _stack3).Push(_stack1.Pop());
				UpdateControlsState(); // обновляем графику
			}
		}

		private void GenerateInitialSet()
		{
			_stack1.Clear(); _stack2.Clear(); _stack3.Clear();
			bool side = RandomGenerator.Bool();
			for (int i = 0; i < 10; i++)
			{
				if (cheatActive.Checked)
					_stack1.Push(side ? RandomGenerator.Odd(10) : RandomGenerator.Even(10));
				else
					_stack1.Push(RandomGenerator.Int32(10));
			}
			UpdateControlsState();
		}
		
		private void btnSwitch_Click(object sender, EventArgs e)
		{
			if (_isFulfilled)
			{
				GenerateInitialSet();
				btnSwitch.Text = "Запуск моделирования";
			}
			else
			{
				RunModelling();
				btnSwitch.Text = "Сгенерировать новые исходные данные";
			}

			_isFulfilled = !_isFulfilled;
		}
		
		private void UpdateControlsState()
		{
			stackProgress1.Value = _stack1.Count;
			txtStack1.Text = Utils.CollectionToString(_stack1);

			stackProgress2.Value = _stack2.Count;
			txtStack2.Text = Utils.CollectionToString(_stack2);

			stackProgress3.Value = _stack3.Count;
			txtStack3.Text = Utils.CollectionToString(_stack3);
		}
		
		private void cheatActive_CheckedChanged(object sender, EventArgs e)
		{
			if (cheatActive.Checked)
			{
				MessageBox.Show("Чит активирован.", "Инфо", MessageBoxButtons.OK, MessageBoxIcon.Information);
			}
		}
	}
}
