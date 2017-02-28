using System;
using System.IO;
using System.Text;

namespace Moreniell.TrigonometricFunctionTable.Entities
{
	public delegate double TrigonometricFuncDelegate(double x);

	public class TableWriter
	{
		private readonly int from, to;
		private readonly string header, middleline, footer;
		private readonly ColumnInfo[] columnsInfo;

		public TableWriter(): this(0, 100, ColumnInfoGenerator.SinDeg, ColumnInfoGenerator.CosDeg) { }
		public TableWriter(int from, int to): this(from, to, ColumnInfoGenerator.SinDeg, ColumnInfoGenerator.CosDeg) { }
		public TableWriter(int from, int to, params ColumnInfo[] columnsInfo)
		{
			if (from > to)
				throw new ArgumentOutOfRangeException(nameof(from), from,
					"Параметр \"от\" не может быть больше параметра \"до\"!");
			if (Math.Abs(to - from) > 100)
				throw new ArgumentOutOfRangeException(nameof(to), to,
					"Больше 100 элементов выводить не рекомендуется!");

			// Устанавливаем диапазон ответов выводимых в таблице.
			this.from = from;
			this.to = to;

			// Добавляем перед заданными колонками еще одну, для исходных данных.
			// Для этого делаем размер массива на 1 больше:
			Array.Resize(ref columnsInfo, columnsInfo.Length + 1);
			// Переставляем все элементы на одну ячейку вперед.
			for (int i = columnsInfo.Length - 1; i > 0; --i)
				columnsInfo[i] = columnsInfo[i - 1];
			// Добавляем в начало колонку для исходных данных.
			columnsInfo[0] = ColumnInfoGenerator.Description;
			// Записываем массив-результат в поле класса.
			this.columnsInfo = columnsInfo;

			// Создаем линии нужной формы.
			header     = BuildLine('╔', '╦', '╗');
			middleline = BuildLine('╠', '╬', '╣');
			footer     = BuildLine('╚', '╩', '╝');
		} // ctorp::END

		/// <summary> Выводит таблицу в указанный поток out. </summary>
		public void Write(TextWriter tw) => tw.Write(this.ToString());

		/// <summary> Генерирует графическое представление разделительной линии таблицы. </summary>
		private string BuildLine(char leftAng, char columnSep, char rightAng)
		{
			StringBuilder sb = new StringBuilder();
			sb.Append(leftAng);         // добавляем левый угол
			foreach (var info in columnsInfo) // добавляем горизонтальные и промежуточные линии
				sb.Append(new string('═', 12)).Append(columnSep); 
			sb[sb.Length-1] = rightAng; // добавляем правый угол 

			return sb.ToString();
		} // BuildLine::END

		private string BuildRow(double x, string appendFirst = "")
		{
			StringBuilder sb = new StringBuilder();
			
			// Добавляем колонку исходных данных.
			sb.Append($"║{$"{columnsInfo[0].TrigonFunction(x)}{appendFirst}",-12}").Append('║');
			
			// Добавляем остальные колонки.
			for (int i = 1; i < columnsInfo.Length; ++i)
				sb.Append($"{columnsInfo[i].TrigonFunction(x),-12:0.####}").Append('║');
			sb[sb.Length - 1] = '║';

			return sb.ToString();
		} // BuildRow::END

		private string BuildHeaders()
		{
			StringBuilder sb = new StringBuilder();
			sb.Append('║');
			foreach (var info in columnsInfo)
				sb.Append($"{info.Header,-12}").Append('║');
			sb[sb.Length - 1] = '║';

			return sb.ToString();
		} // BuildHeaders::END

		/// <summary> Возвращает строку, представляющую текущий объект. </summary>
		public override string ToString()
		{
			StringBuilder sb = new StringBuilder();
			
			// Формируем заголовок.
			sb.AppendLine(header);
			sb.AppendLine(BuildHeaders());
			sb.AppendLine(middleline);

			// Формируем строки.
			for (int i = from; i < to+1; ++i)
			{
				sb.AppendLine(BuildRow(i, "°"));
				if (i != to)
					sb.AppendLine(middleline);
			}

			// Отчеркиваем последнюю линию в таблице.
			sb.AppendLine(footer);
			
			return sb.ToString();
		} // ToString::END
	}
}