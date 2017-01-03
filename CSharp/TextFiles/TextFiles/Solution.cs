using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

using MaZaiPC.TextFiles.Service;

namespace MaZaiPC.TextFiles
{
	static class Solution
	{
		private static string temp;
		private static string[] tokens;

		public static void Task1()
		{
			StreamReader sr;
			InitTask(out sr);
			
			Utils.PrintEncolored("\nОригинал:\n");
			
			for (int i = 0; i < tokens.Length; ++i)
				Utils.PrintEncolored($"{tokens[i]} ", i % 2 == 0 ? ConsoleColor.Magenta : ConsoleColor.Cyan);
			Console.WriteLine();

			
			for (int i = 1; i < tokens.Length; i += 2)
			{
				temp = tokens[i];
				tokens[i] = tokens[i - 1];
				tokens[i - 1] = temp;
			}

			Utils.PrintEncolored("\nПосле обработки:\n");

			for (int i = 0; i < tokens.Length; ++i)
				Utils.PrintEncolored($"{tokens[i]} ", i % 2 == 0 ? ConsoleColor.Cyan : ConsoleColor.Magenta );
			
			sr.Close(); // закрыть поток/файл ввода
		}

		public static void Task2()
		{
			StreamReader sr;
			InitTask(out sr);

			Utils.PrintEncolored("\nОригинал:\n");
			for (int i = 0; i < tokens.Length; ++i)
				Console.Write($"{tokens[i]} ");

			Utils.PrintEncolored("\n\nСлова, начинающиеся и заканчивающиеся на согласную букву:\n");

			string consonants = "бвгджзклмнпрстфхцчшщ"; // bcdfghjklmnpqrstvwxz

			// Перечисляем все слова из текста, начинающиеся и заканчивающиеся на согласную букву.
			foreach (var token in tokens)
			{
				string t = token.ToLower();
				if (consonants.IndexOf(t[0]) >= 0 && consonants.IndexOf(t[t.Length - 1]) >= 0)
				{
					Utils.PrintEncolored(token, ConsoleColor.Cyan);
					Console.Write(", ");
				}
			}
			
			// Ставим точку в конце перечисления.
			Utils.WriteXY(Console.CursorLeft - 2, Console.CursorTop, ".");
		}

		private static void InitTask(out StreamReader sr)
		{
			string path = @"..\..\fish-text.txt";
			Console.Write($"Нажмите ENTER, чтобы открыть файл по-умолчанию или укажите путь\nк файлу для открытия.\n\n{path}>");
			temp = Console.ReadLine();

			if (temp != string.Empty)
				path = temp;

			sr = new StreamReader(File.OpenRead(path), Encoding.Default);

			StringBuilder sb = new StringBuilder();

			while (!sr.EndOfStream) sb.Append(sr.ReadLine());
			
			tokens = sb.ToString().Split(" \n\r\t".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
		}
	}
}
