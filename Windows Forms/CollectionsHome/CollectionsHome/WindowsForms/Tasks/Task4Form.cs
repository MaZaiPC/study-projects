using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using Moreniell.CollectionsHome.Common;

namespace Moreniell.CollectionsHome.WindowsForms.Tasks
{
	public partial class Task4Form : Form
	{
		private readonly Queue<int> _queue1 = new Queue<int>();
		private readonly Queue<int> _queue2 = new Queue<int>();
		private readonly Queue<int> _queue3 = new Queue<int>();

		private bool _isFulfilled; // выполнено ли моделирование

		private const int QUEUE_LENGTH = 5;
		
		public Task4Form()
		{
			InitializeComponent();
			GenerateInitialSet();  // генерируем начальные данные
			UpdateControlsState(); // обновляем графику
		}

		private void RunModelling()
		{
			QeueUnion();     // выполняем объединение двух очередей
			UpdateControlsState(); // обновляем графику
		}

		private void GenerateInitialSet()
		{
			_queue1.Clear(); _queue2.Clear(); _queue3.Clear();
			
			int[][] arr = new int[2][];
			for (int i = 0; i < 2; ++i)
			{
				// Создаем новый массив.
				arr[i] = new int[QUEUE_LENGTH];

				// Заполняем его случайными числами.
				for (int j = 0; j < QUEUE_LENGTH; j++)
				{
					arr[i][j] = RandomGenerator.Int32(10);
				}

				// Сортируем.
				Array.Sort(arr[i]);
			}

			// Руководствуясь рекомендациями из ТЗ, заполняем
			// очереди элементами из сортированных массивов случайных чисел.
			foreach (int item in arr[0]) _queue1.Enqueue(item);
			foreach (int item in arr[1]) _queue2.Enqueue(item);

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

			queueProgress3.Value = _queue3.Count;
			txtStack3.Text = Utils.CollectionToString(_queue3);
		}
		
		// Метод объеденяет 2 очереди в одну сорированную.
		public void QeueUnion()
		{
			for (int i = 0; i < QUEUE_LENGTH*2; i++)
			{
				if (_queue1.Count == 0 && _queue2.Count == 0) break;

				int item = ExtractSmallest(_queue1, _queue2);
				_queue3.Enqueue(item);
			}
		}
		
		// Извлекает минимальный среди двух очередей элемент.
		private static int ExtractSmallest(Queue<int> left, Queue<int> right)
		{
			int minLeft;
			int minRight;

			// 1-й случай: левая очередь пуста.
			if (left.Count == 0)
			{
				minRight = Utils.Min(right);
				Utils.Extract(right, minRight);
				return minRight;
			}
			// 2-й случай: правая очередь пуста.
			if (right.Count == 0)
			{
				minLeft = Utils.Min(left);
				Utils.Extract(left, minLeft);
				return minLeft;
			}

			// 3-й случай: обе очереди имеют элементы.

			minLeft = Utils.Min(left);
			minRight = Utils.Min(right);

			if (minLeft > minRight)
			{
				Utils.Extract(right, minRight);
				return minRight;
			}

			Utils.Extract(left, minLeft);
			return minLeft;
		}
	}
}
