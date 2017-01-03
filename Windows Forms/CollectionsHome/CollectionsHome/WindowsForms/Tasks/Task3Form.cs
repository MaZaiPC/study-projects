using System;
using System.Collections.Generic;
using System.Windows.Forms;
using MaZaiPC.CollectionsHome.Common;

namespace MaZaiPC.CollectionsHome.WindowsForms.Tasks
{
	public partial class Task3Form : Form
	{
		private readonly Queue<int> _queue1 = new Queue<int>();
		private readonly Queue<int> _queue2 = new Queue<int>();

		private bool _isFulfilled; // выполнено ли моделирование

		public Task3Form()
		{
			InitializeComponent();
			GenerateInitialSet();  // генерируем начальные данные
			UpdateControlsState(); // обновляем графику
		}

		private void RunModelling()
		{
			bool evenfinded = false;
			int len = _queue1.Count;
			for (int i = 0; i < len; ++i)
			{
				if (_queue1.Peek() % 2 == 0)
				{
					evenfinded = true;
					break;
				}

				_queue2.Enqueue(_queue1.Dequeue());
				UpdateControlsState();
			}

			if (!evenfinded)
			{
				len = _queue1.Count;
				for (int i = 0; i < len; ++i)
				{
					_queue2.Enqueue(_queue1.Dequeue());
				}
				UpdateControlsState();
			}
		}

		private void GenerateInitialSet()
		{
			_queue1.Clear();
			_queue2.Clear();
			for (int i = 0; i < 10; i++)
			{
				if (RandomGenerator.Int32(10) < 8 || cheatActive.Checked)
				{
					_queue1.Enqueue(RandomGenerator.Even(10));
				}
				else
				{
					_queue1.Enqueue(RandomGenerator.Odd(10));
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
			queueProgress1.Value = _queue1.Count;
			txtStack1.Text = Utils.CollectionToString(_queue1);

			queueProgress2.Value = _queue2.Count;
			txtStack2.Text = Utils.CollectionToString(_queue2);
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
