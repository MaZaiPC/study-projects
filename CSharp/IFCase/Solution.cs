using System;

namespace Moreniell.Beginning
{
	static class Solution
	{
		public static void If16()
		{
			// Вывод задания
			Utils.PrintEncolored("ТЗ:");
			Console.WriteLine("\nДаны три переменные вещественного типа: A, B, C. Если их значения " +
								"упорядочены по возрастанию, то удвоить их; в противном случае заме" +
								"нить значение каждой переменной на противоположное. Вывести новые " +
								"значения переменных A, B, C.\n");

			// Объявление переменных
			double a, b, c;
			int posY;

			Utils.PrintEncolored("Введите:\n");
			posY = Console.CursorTop;
			Console.WriteLine("Значение A :>\nЗначение B :>\nЗначение C :>");

			const int offsetX = 14;

			// Ввод данных
			Console.SetCursorPosition(offsetX, posY);
			double.TryParse(Console.ReadLine(), out a);
			Console.SetCursorPosition(offsetX, posY + 1);
			double.TryParse(Console.ReadLine(), out b);
			Console.SetCursorPosition(offsetX, posY + 2);
			double.TryParse(Console.ReadLine(), out c);

			if (a < b && b < c) {
				a *= 2D; b *= 2D; c *= 2D;
			} else {
				a = -a; b = -b; c = -c;
			}

			// Вывод результатов
			Utils.PrintEncolored("\nРезультат:\n");
			Console.WriteLine($"A = {a:f2}\nB = {b:f2}\nC = {c:f2}");
		} // If16::END

		public static void If28()
		{
			// Вывод задания
			Utils.PrintEncolored("ТЗ:");
			Console.WriteLine("\nДан номер года (положительное целое число). Определить количество" +
								"дней в этом году, учитывая, что обычный год насчитывает 365 дней, а" +
								"високосный — 366 дней.Високосным считается год, делящийся на 4, за" +
								"исключением тех годов, которые делятся на 100 и не делятся на 400" +
								"(например, годы 300, 1300 и 1900 не являются високосными, а 1200 и 2000" +
								"— являются)\n");

			// Объявление переменных
			uint year;
			bool isLeapYear;

			Console.Write("Введите номер года :> ");
			uint.TryParse(Console.ReadLine(), out year);

			isLeapYear = year % 4 == 0 || (year % 100 != 0 && year % 400 == 0);

			// Вывод результатов
			Utils.PrintEncolored("\nРезультат:\n");
			Console.WriteLine("Год " + (isLeapYear ? "" : "не ") + "является високосным. Кол-во дней: "+ (isLeapYear ? "366" : "365"));
		} // If28::END

		public static void Case14()
		{
			// Вывод задания
			Utils.PrintEncolored("ТЗ:");
			Console.WriteLine("\nЭлементы равностороннего треугольника пронумерованы следую" +
								"щим образом:\n1 — сторона a,\n2 — радиус R1 вписанной окружности " +
								"(R1 = a·√3 / 6),\n3 — радиус R2 описанной окружности(R2 = 2·R1),\n4 — " +
								"площадь S = a^2·√3 / 4\nДан номер одного из этих элементов и его значение. " +
								"Вывести значения остальных элементов данного треугольника(в том же " +
								"порядке).\n");

			// Объявление переменных
			byte cnt;
			double val, a, r1;
			
			cnt = Utils.GetByte("Ваш выбор (1, ..., 4) :> ", 1, 4);

			Console.Write("Введите значение элементa :> ");
			double.TryParse(Console.ReadLine(), out val);
			
			switch (cnt)
			{
				case 1:
					a = val;
					r1 = a * (Math.Sqrt(3) / 6);
					break;
				case 2:
					a = val / (Math.Sqrt(3) / 6);
					r1 = val;
					break;
				case 3:
					a= val / (Math.Sqrt(3) / 3);
					r1= val / 2;
					break;
				case 4:
					a = Math.Sqrt(4 * val) / 3;
					r1 = a * (Math.Sqrt(3) / 6);
					break;
				default:
					return;
			}

			Utils.PrintEncolored("\nРезультаты:\n");
			Console.WriteLine($"Cторона: {a:f2}");
			Console.WriteLine($"Pадиус вписанной окружности: {r1:f2}");
			Console.WriteLine($"Pадиус описанной окружности: {2 * r1:f2}");
			Console.WriteLine($"Площадь: {a * a * (Math.Sqrt(3) / 4):f2}");
		} // Case14::END
		
		public static void Case17()
		{
			// Вывод задания
			Utils.PrintEncolored("ТЗ:");
			Console.WriteLine("\nДано целое число в диапазоне 10–40, определяющее количество учеб" +
								"ных заданий по некоторой теме.Вывести строку - описание указанного " +
								"количества заданий, обеспечив правильное согласование числа со слова" +
								"ми «учебное задание», например: 18 — «восемнадцать учебных заданий»," +
								"23 — «двадцать три учебных задания», 31 — «тридцать одно учебное за" +
								"дание».\n");

			// Объявление переменных
			string str = "";
			byte amount;

			// Ввод данных
			amount = Utils.GetByte("Кол-во заданий (10, ..., 40) :> ", 10, 40);

			if (amount/10 == 1)
			{
				switch (amount)
				{
					case 10:
						str += "десять";
						break;
					case 11:
						str += "одинадцать";
						break;
					case 12:
						str += "двенадцать";
						break;
					case 13:
						str += "тринадцать";
						break;
					case 14:
						str += "четырнадцать";
						break;
					case 15:
						str += "пятнадцать";
						break;
					case 16:
						str += "шестнадцать";
						break;
					case 17:
						str += "семнадцать";
						break;
					case 18:
						str += "восемнадцать";
						break;
					case 19:
						str += "девятнадцать";
						break;
				}
				str += " учебных заданий";
			}
			else
			{
				switch (amount / 10)
				{
					case 2:
						str += "двадцать ";
						break;
					case 3:
						str += "тридцать ";
						break;
					case 4:
						str += "сорок ";
						break;
				}

				switch (amount % 10)
				{
					case 1:
						str += "одно ";
						break;
					case 2:
						str += "два ";
						break;
					case 3:
						str += "три ";
						break;
					case 4:
						str += "четыре ";
						break;
					case 5:
						str += "пять ";
						break;
					case 6:
						str += "шесть ";
						break;
					case 7:
						str += "семь ";
						break;
					case 8:
						str += "восемь ";
						break;
					case 9:
						str += "девять ";
						break;
				}

				switch (amount % 10)
				{
					case 0: case 5: case 6:
					case 7: case 8: case 9:
						str += "учебных заданий";
						break;
					case 1:
						str += "учебное задание";
						break;
					case 2: case 3: case 4:
						str += "учебных задания";
						break;
				}
			}
			
			// Опционально:
			str += '.';									   // точка в конце предложения
			str = char.ToUpper(str[0]) + str.Substring(1); // с большой буквы

			// Вывод результатов
			Utils.PrintEncolored("\nВывод текста:\n");
			Console.WriteLine(str);
		} // Case14::END
	}
}
