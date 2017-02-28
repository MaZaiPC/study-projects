using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Remoting.Channels;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

using Moreniell.TextFiles.Service;

namespace Moreniell.TextFiles
{
	static class Solution
	{
		static Solution()
		{
			Events.OnPairLetters += Events_OnPairLetters1;
			Events.OnPairLetters += Events_OnPairLetters2;
		}
		
		private static void Events_OnPairLetters1(object sender, EventArgs e)
		{
		}

		private static void Events_OnPairLetters2(object sender, EventArgs e)
		{
			Console.WriteLine("Я тоже!");
		}

		public static void RunTask()
		{
			string path = @"..\..\fish-text.txt";
			Console.Write($"Нажмите ENTER, чтобы открыть файл по-умолчанию или укажите путь\nк файлу для открытия.\n\n{path}>");
			string temp = Console.ReadLine();

			if (temp != string.Empty)
				path = temp;

			using (StreamReader sr = new StreamReader(File.OpenRead(path), Encoding.Default))
			{
				while (!sr.EndOfStream)
				{
					string[] tokens = sr.ReadLine()
						.Split(".!?,;-+=()`\" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

					foreach (var token in tokens)
					{
						if (token.Length == 2)
						{
							Events.CallOnPairLetters();
							break;
						}
					}
				}
			} // StreamReader::END
		} // RunTask::END
	}
}
