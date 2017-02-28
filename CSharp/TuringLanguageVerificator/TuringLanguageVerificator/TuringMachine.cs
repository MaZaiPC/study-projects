// Класс, который отвечает за работу машины Тьюринга и реализует её прикладную часть.
// TuringMachine.cs

using System;
using System.Collections.Generic;

namespace Moreniell.CourseWork
{
	public class TuringMachine
	{
		// Язык который распознается этой машиной Тьюринга.
		public static string LanguageSyntax => "a^(5n)b^(7n) | n > 0";

		// Состояние МТ, которое означает что слово принадлежит языку.
		public static int SuccessCode     => 20;
		
		// Состояние МТ, которое означает что слово не принадлежит языку.
		public static int SyntaxErrorCode => 21;
		
		private Tape[] tapes; // массив лент
		private int q;		  // текущее состояние
		private int i;        // номер такта
		
		// Хранит кол-во пройденных тактов для каждой ячейки лент МТ.
		public Dictionary<KeyValuePair<int, int>, int> Max { get; private set; }

		// Событие CellChanged зажигается при изменении содержимого ячейки ленты.
		private void tape_CellChanged(object sender, CellChangedEventArgs e)
		{
			var key = new KeyValuePair<int, int>(sender == tapes[0] ? 0 : 1, e.CellIndex);
			if (!Max.ContainsKey(key))
			{
				Max.Add(key, 0);
			}
			Max[key]++;
		}
		
		// Метод выполняет определенное действие с лентами машины Тьюринга.
		private void Action(string stimulus, string reaction, int state, MoveHead move1, MoveHead move2)
		{
			if (tapes[0].CurrentCell == stimulus[0] && tapes[1].CurrentCell == stimulus[1])
			{
				if (tapes[0].CurrentCell != reaction[0] || move1 != MoveHead.None)
				{
					// Изменяем значение текущей ячейки первой ленты и
					// двигаемся в указанном направлении.
					tapes[0].CellChange(reaction[0], move1);
				}
				// Изменяем значение текущей ячейки второй ленты и
				// двигаемся в указанном направлении.
				tapes[1].CellChange(reaction[1], move2);

				// Меняем состояние МТ.
				q = state;

				// Уведомляем подписчиков о срабатывании события ActionPeformed.
				ActionPeformed?.Invoke(this, new ActionPeformedEventArgs(
					i, q, move1, move2, reaction[0], reaction[1]));
				
				// Бросаем исключение которое заменяет нам использование continue в цикле.
				// Сделано для удобства, чтобы не писать громозкие структуры из if-ов.
				throw new Exception("ignore next call");
			}
		}
		
		// Метод моделирует работу машины Тьюринга.
		public int Manage(string word)
		{
			// Инициализация словаря (типизированная хеш-таблица не имеющая метода разрешения коллизий).
			Max = new Dictionary<KeyValuePair<int, int>, int>();

			// Уведомляем подписчиков о срабатывании события Managing.
			Managing?.Invoke(this, EventArgs.Empty);

			// Инициализация лент.
			tapes = new[] { new Tape(word), new Tape() };

			// Подписка на события лент МТ.
			SubscribeEvents();

			q = 0; // по умолчанию q0
			i = 1; // это будет 1-й такт

			do
			{
				// Уведомляем подписчиков о срабатывании события IterationOfManaging.
				IterationOfManaging?
					.Invoke(this, new IterationOfManagingEventArgs(i, q, tapes[0].CurrentCell, tapes[1].CurrentCell));
				
				try
				{
					switch (q)
					{
						case 0:
							Action("aB", "a$", 1, MoveHead.None, MoveHead.Right);
							break;

						case 1:
							Action("aB", "aa", 2, MoveHead.None, MoveHead.Right);
							break;

						case 2:
							Action("aB", "aa", 3, MoveHead.None, MoveHead.Right);
							break;

						case 3:
							Action("aB", "aa", 4, MoveHead.None, MoveHead.Right);
							break;

						case 4:
							Action("aB", "aa", 5, MoveHead.None, MoveHead.Right);
							break;

						case 5:
							Action("aB", "aa", 6, MoveHead.None, MoveHead.Right);
							break;

						case 6:
							Action("aB", "a$", 7, MoveHead.None, MoveHead.Left);
							break;

						case 7:
							Action("aa", "aa", 7, MoveHead.Right, MoveHead.Left);
							Action("a$", "a$", 8, MoveHead.None, MoveHead.Right);
							Action("b$", "b$", 9, MoveHead.None, MoveHead.Right);
							break;

						case 8:
							Action("aa", "aa", 8, MoveHead.Right, MoveHead.Right);
							Action("a$", "a$", 7, MoveHead.None, MoveHead.Left);
							Action("b$", "b$", 10, MoveHead.None, MoveHead.Right);
							break;

						case 9:
							Action("ba", "ba", 9, MoveHead.None, MoveHead.Right);
							Action("b$", "b$", 10, MoveHead.None, MoveHead.Right);
							break;

						case 10:
							Action("bB", "bb", 11, MoveHead.None, MoveHead.Right);
							break;

						case 11:
							Action("bB", "bb", 12, MoveHead.None, MoveHead.Right);
							break;

						case 12:
							Action("bB", "bb", 13, MoveHead.None, MoveHead.Right);
							break;

						case 13:
							Action("bB", "bb", 14, MoveHead.None, MoveHead.Right);
							break;

						case 14:
							Action("bB", "bb", 15, MoveHead.None, MoveHead.Right);
							break;

						case 15:
							Action("bB", "bb", 16, MoveHead.None, MoveHead.Right);
							break;

						case 16:
							Action("bB", "bb", 17, MoveHead.None, MoveHead.Right);
							break;

						case 17:
							Action("bB", "b$", 18, MoveHead.None, MoveHead.Left);
							break;

						case 18:
							Action("bb", "bb", 18, MoveHead.Right, MoveHead.Left);
							Action("b$", "b$", 19, MoveHead.None, MoveHead.Right);
							Action("B$", "B$", SuccessCode, MoveHead.None, MoveHead.Right);
							break;
						case 19:
							Action("bb", "bb", 19, MoveHead.Right, MoveHead.Right);
							Action("b$", "b$", 18, MoveHead.None, MoveHead.Left);
							Action("B$", "B$", SuccessCode, MoveHead.None, MoveHead.Right);
							break;
					}
					
					// Если программа доходит до этого участка кода, это означает что
					// символы в текущей позиции на лентах не совпадают ни с одним
					// ожидаемым результатом.

					// Переходим в состояние МТ, которое означает, что-то пошло не так.
					q = SyntaxErrorCode;

					// Уведомляем подписчиков о срабатывании события ActionPeformed.
					ActionPeformed?.Invoke(this, new ActionPeformedEventArgs(
						i, q, MoveHead.None, MoveHead.None, tapes[0].CurrentCell, tapes[1].CurrentCell));
				}
				catch (Exception)
				{
					// ignored
				}

				i++; // инкрементируем счетчик тактов
			}
			// Выходим из цикла только если состояние q равно одному из конечных.
			while (q != SuccessCode && q != SyntaxErrorCode);

			// Уведомляем подписчиков о срабатывании события Managed.
			Managed?.Invoke(this, new ManagedEventArgs(i, q));

			// Отписка от событий лент МТ.
			UnsubscribeEvents();
			return i;
		}

		// Метод выполняет подписку слушателей к событиям проистекающим в лентах машины Тьюринга.
		private void SubscribeEvents()
		{
			tapes[0].CellChanged += tape_CellChanged;
			tapes[1].CellChanged += tape_CellChanged;
		}

		// Метод выполняет отписку слушателей от событий в лентах машины Тьюринга.
		//--------------------------------------------------------------------------
		// Делать это необходимо для корректной работы сборщика мусора.
		private void UnsubscribeEvents()
		{
			tapes[1].CellChanged -= tape_CellChanged;
			tapes[0].CellChanged -= tape_CellChanged;
		}

		// Обработчики событий.
		public delegate void ManagedEventHandler(object sender, ManagedEventArgs e);
		public delegate void IterationOfManagingEventHandler(object sender, IterationOfManagingEventArgs e);
		public delegate void ActionPeformedEventHandler(object sender, ActionPeformedEventArgs e);

		// Собственно события.
		public event EventHandler Managing;
		public event ManagedEventHandler Managed;
		public event IterationOfManagingEventHandler IterationOfManaging;
		public event ActionPeformedEventHandler ActionPeformed;
	}
	
	public class ManagedEventArgs : EventArgs
	{
		public int OperationsLeft { get; }  // количество пройденых тактов
		public int MachineState { get; }    // состояние машины (q)

		// Параметризованный конструктор.
		public ManagedEventArgs(int operationsLeft, int machineState)
		{
			OperationsLeft = operationsLeft;
			MachineState = machineState;
		}
	}

	public class IterationOfManagingEventArgs : ManagedEventArgs
	{
		public char[] CurrentCells { get; }  // ячейки на которые указывают головки лент МТ

		// Параметризованный конструктор.
		public IterationOfManagingEventArgs(int operationsLeft, int machineState, params char[] currentCells)
			: base(operationsLeft, machineState)
		{
			CurrentCells = currentCells;
		}
	}

	public class ActionPeformedEventArgs : IterationOfManagingEventArgs
	{
		public MoveHead Move1 { get; } // сторона в которую сдвинулась головка 1-й ленты МТ
		public MoveHead Move2 { get; } // сторона в которую сдвинулась головка 2-й ленты МТ

		// Параметризованный конструктор.
		public ActionPeformedEventArgs(int operationsLeft, int machineState,
			MoveHead move1, MoveHead move2, params char[] currentCells) 
			: base(operationsLeft, machineState, currentCells)
		{
			Move1 = move1;
			Move2 = move2;
		}
	}
}