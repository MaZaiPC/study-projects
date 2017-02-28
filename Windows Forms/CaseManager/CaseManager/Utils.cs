using System;
using System.Text;

namespace Moreniell.CaseManager
{
	public static class Utils
	{
		public static string DelAllSymbols(string target, bool allowSpace = true)
		{
			StringBuilder sb = new StringBuilder();

			foreach (var ch in target)
			{
				// Игнорируем всё кроме букв, цифр и символа пробела (опционально).
				if (char.IsLetterOrDigit(ch) || allowSpace && ch == ' ')
					sb.Append(ch);
			}

			return sb.ToString();
		}
		
		public static string ReverseByWords(string source)
		{
			string[] tokens = source.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

			StringBuilder sb = new StringBuilder();

			// Движемся по массиву лексем в обратном порядке.
			for (int i = tokens.Length - 1; i >= 0; --i)
				sb.Append(' ').Append(tokens[i]); // собираем предложение

			return sb.ToString().TrimStart();
		}

		public static string Capitalize(string source)
		{
			string[] tokens = source.ToLower().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

			StringBuilder sb = new StringBuilder();

			foreach (var token in tokens)
			{
				sb.Append(' ').Append(char.ToUpper(token[0])) // переводим первую букву слова в верхний регистр
					.Append(token.Substring(1));              // добавляем остальную часть слова
			}

			return sb.ToString().TrimStart();
		}
	}
}