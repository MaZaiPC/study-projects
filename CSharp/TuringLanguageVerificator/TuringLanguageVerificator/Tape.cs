// Класс-контейнер представляет собой ленту МТ.
// TuringMachine.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MaZaiPC.CourseWork
{
	public class Tape
	{
		private int _head;                       // головка ленты
		private readonly List<char> _tape;       // список ячеек ленты

		public char CurrentCell => _tape[_head]; // значение текущей ячейки
		
		public char Blank { get; }               // знак пробела

		// Конструктор по-умолчанию.
		public Tape() : this("") { }

		// Параметризованный конструктор.
		public Tape(string word, char blank = 'B')
		{
			_tape = (word + blank).ToList();

			Blank = blank;
		}
		
		public void CellChange(char value, MoveHead moveHead)
		{
			// Изменяем содержимое ячейки.
			_tape[_head] = value;

			// Уведомляем подписчиков о срабатывании события CellChanged.
			CellChanged?.Invoke(this, new CellChangedEventArgs(_head));

			// Если при передвижении головка делает попытку выхода за пределы ленты,
			// то к соответствующему краю ленты добавляется знак пробела. Таким
			// образом мы имитируем бесконечность ленты, расширяя её границы по
			// мере необходимости.

			// Двигаем головку ленты в одну из сторон.
			switch (moveHead)
			{
				case MoveHead.Left:
					if (_head != 0) _head--; else _tape.Insert(0, Blank); break;
				case MoveHead.Right:
					_head++; if (_head == _tape.Count) _tape.Add(Blank); break;
			}
		}

		// Строковое представление ленты МТ.
		public override string ToString()
		{
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < _tape.Count; i++)
			{
				if (i == _head)
					sb.Append('[').Append(_tape[i]).Append("] ");
				else
					sb.Append(_tape[i]).Append(' ');
			}
			return sb.ToString();
		}

		// Обработчик события CellChanged.
		public delegate void CellChangedEventHandler(object sender, CellChangedEventArgs e);

		// Событие CellChanged. Зажигается после изменения ячейки.
		public event CellChangedEventHandler CellChanged;
	}

	public class CellChangedEventArgs : EventArgs
	{
		public int CellIndex { get; } // индекс текущей ячейки

		// Параметризованный конструктор.
		public CellChangedEventArgs(int cellIndex)
		{
			CellIndex = cellIndex;
		}
	}

	public enum MoveHead
	{
		None, // стоять на месте
		Left, // двигаться в лево
		Right // двигаться в право
	}
}