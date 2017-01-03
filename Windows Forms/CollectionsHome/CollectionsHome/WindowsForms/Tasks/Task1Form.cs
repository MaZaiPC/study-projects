using System;
using System.Collections.Generic;
using System.Windows.Forms;
using MaZaiPC.CollectionsHome.Common;

namespace MaZaiPC.CollectionsHome.WindowsForms.Tasks
{
	public partial class Task1Form : Form
	{
		private readonly Stack<int> _stack1 = new Stack<int>();
		private readonly Stack<int> _stack2 = new Stack<int>();
		
		private bool _isFulfilled; // выполнено ли моделирование

		public Task1Form()
		{
			InitializeComponent();
			GenerateInitialSet();  // генерируем начальные данные
			UpdateControlsState(); // обновляем графику
		}
		
		private void RunModelling()
		{
			bool evenfinded = false;
			int len = _stack1.Count;
			for (int i = 0; i < len; ++i)
			{
				if (_stack1.Peek() % 2 == 0)
				{
					evenfinded = true;
					break;
				}

				_stack2.Push(_stack1.Pop());
				UpdateControlsState(); // обновляем графику
			}

			// Случай, когда четных чисел в стеке не найдено:
			if (!evenfinded)
			{
				len = _stack1.Count;
				for (int i = 0; i < len; ++i)
				{
					_stack2.Push(_stack1.Pop());
				}
				UpdateControlsState(); // обновляем графику
			}
		}

		// Метод помещает 10 случайных элементов в стек
		private void GenerateInitialSet()
		{
			_stack1.Clear();
			_stack2.Clear();
			for (int i = 0; i < 10; i++)
			{
				// Вероятность получения нечетных элементов намеренно увеличена.

				if (RandomGenerator.Int32(10) < 8 || cheatActive.Checked)
				{
					_stack1.Push(RandomGenerator.Even(10));
				}
				else
				{
					_stack1.Push(RandomGenerator.Odd(10));
				}
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
