using System;
using Moreniell.TrigonometricFunctionTable.Common;
using Moreniell.TrigonometricFunctionTable.Entities;

namespace Moreniell.TrigonometricFunctionTable
{
	static class Solution
	{
		private static TableWriter tableWriter = new TableWriter();

		/// <summary> Получает диапазон значений углов для формирования таблицы. </summary>
		public static void GetRanges()
		{
			int from, to;

			Print.Encolored("Введите диапазон значений углов для формирования таблицы (градусы)\n\n");
			Console.Write("От :>\nДо :>");
			Console.SetCursorPosition(7, 2);
			int.TryParse(Console.ReadLine(), out from);
			Console.SetCursorPosition(7, 3);
			int.TryParse(Console.ReadLine(), out to);

			// Формируем таблицу с новым диапазоном.
			tableWriter = new TableWriter(from, to);
		}

		/// <summary> Просто выводит таблицу на экран. </summary>
		public static void ShowTable()
		{
			Print.Encolored("\nТаблица в градусах:\n");
			tableWriter.Write(Console.Out);
		}
	}
}
