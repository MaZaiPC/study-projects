using System;

namespace Moreniell.CollectionsHome.Common
{
	public static class RandomGenerator
	{
		private static readonly Random rand = new Random();

		// Возвращает целое случайное число в диапазоне от 0 до maxValue.
		public static int Int32(int maxValue)
		{
			return rand.Next(maxValue + 1);
		}

		// Возвращает случайное значение истинности.
		public static bool Bool()
		{
			return rand.Next(11) > 5;
		}

		// Возвращает четное случайное число в диапазоне от 0 до maxValue.
		public static int Even(int maxValue)
		{
			int result;
			do
			{
				result = rand.Next(maxValue + 1);
			} while (result % 2 == 0);
			return result;
		}

		// Возвращает нечетное случайное число в диапазоне от 0 до maxValue.
		public static int Odd(int maxValue)
		{
			int result;
			do
			{
				result = rand.Next(maxValue + 1);
			} while (result % 2 != 0);
			return result;
		}
	}
}