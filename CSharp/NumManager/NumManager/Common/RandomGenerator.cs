using System;

namespace MaZaiPC.NumManager.Common
{
	public class RandomGenerator
	{
		private static readonly Random rand = new Random();

		public static int Int32(int min, int max)
		{
			return rand.Next(min, max + 1);
		}
		
		public static double Double(double min, double max)
		{
			return rand.NextDouble() * (max - min) + min;
		}

		public static char Char(char a, char b)
		{
			return (char)Int32(a, b);
		}
		
		public static int Digit()
		{
			return rand.Next(10);
		}
	}
}