using System;
using System.IO;
using System.Net.Mime;
using System.Runtime.InteropServices;
using System.Security.AccessControl;
using System.Text;
using ClassLibrary1.Service;

namespace Moreniell.TextFiles.Entities
{
	class TextEditor
	{
		private string path, tmpPath;
		private bool changeAttempt;
		
		public bool ChangeAttempt
		{
			get { return changeAttempt; }
			private set
			{
				if (value)
					if (!File.Exists(tmpPath) || !changeAttempt) File.Copy(path, tmpPath, true);
				
				changeAttempt = value;
			}
		}
		
		// Конструктор
		public TextEditor(string defPath)
		{
			path = defPath;
		}

		public void Handler()
		{
			Utils.PrintEncolored("Text Editor 1.01\n\n");
			OpenFile(path);

			bool flagExit = false;
			
			while (true)
			{
				Utils.PrintEncolored("te-command:~$ ", ConsoleColor.Magenta);

				// Сюда записываем полное выражение.
				string expression = Console.ReadLine();

				// Режем выражение на аргументы.
				string[] args = expression.Split(" ,".ToCharArray(), /*MAX*/4, StringSplitOptions.RemoveEmptyEntries);
				
				// Если аргументов нет, то пропускаем итерацию.
				if (args.Length == 0) continue;

				// Сохраняем текущую команду в переменную.
				string currentCmd = args[0].ToLower();

				try
				{
					// Выполняем обработку команд.
					switch (currentCmd)
					{
						case "f":
							if (args.Length > 1) // f путь_к_файлу
								OpenFile(expression.Substring(2));
							else
								throw new FormatException();
							break;
						case "l":
							switch (args.Length)
							{
								case 3: // l с1, с2
									ShowLines(int.Parse(args[1]), int.Parse(args[2]));
									break;
								case 2: // l с1
									ShowLine(int.Parse(args[1]));
									break;
								case 1: // l
									ShowDoc();
									break;
								default:
									throw new FormatException();
							}
							break;
						case "i":
							if (args.Length > 2) // i c1 string
								InsertLine(int.Parse(args[1]), expression
									.Substring(3+args[1].Length)); // извлекаем текст из выражения
							else if (args.Length == 1) // i
								AppendLines();
							else
								throw new FormatException();
							break;
						case "d":
							switch (args.Length)
							{
								case 3: // d с1, с2
									DeleteLines(int.Parse(args[1]), int.Parse(args[2]));
									break;
								case 2: // d c1
									DeleteLine(int.Parse(args[1]));
									break;
								default:
									throw new FormatException();
							}
							break;
						case "r":
							if (args.Length > 2 && !Utils.IsNumber(args[2])) // r с1 string
								ReplaceLine(int.Parse(args[1]), expression.Substring(3 + args[1].Length));
							else if (args.Length > 3) // r с1 с2 string
								ReplaceLines(int.Parse(args[1]), int.Parse(args[2]), expression
									.Substring(4 + args[1].Length + args[2].Length)); // извлекаем текст из выражения
							else
								throw new FormatException();
							break;
						case "s":
							if (args.Length == 1) Save(); // s
							// TODO: s string - сохранить как
							else
								throw new FormatException();
							break;

						case "help":
						case "h":
							ShowHelp();
							break;
						case "q":
							SaveFile();
							flagExit = true;
							break;
						default:
							Console.WriteLine("\nНеизвестная команда!\n\n" +
											  "Введите h или help для просмотра справки.\n");
							break;
					}
				}
				catch (FormatException)
				{
					// Немножко ругаемся.
					Console.WriteLine("\nНеизвестная сигнатура комманды!\n");

					// Рассказываем пользователю как правильно записывать эту команду:
					// Получаем и выводим список правильных сигнатур для команды которая
					// вызвала ошибку формата.
					Utils.PrintEncolored("Возможные варианты:\n", ConsoleColor.Cyan);
					Console.WriteLine(GetSignature(currentCmd[0]) + "\n");
				}
				catch (Exception ex)
				{
					// Тут обрабатываем остальные исключения.
					Console.WriteLine(ex.Message);
				}
				if (flagExit) break;
			} // while::END
		} // Handler::END
		
		////////////////////////////////////////////////////////////////////////////////

		/// <summary> Открывает или создает новый файл. </summary>
		private void OpenFile(string fileName)
		{
			SaveFile();

			bool created = false;
			
			FileInfo f = new FileInfo(fileName);
			if (!f.Exists)
			{
				// Создаем файл и сразу закрываем его поток, чтобы не было конфликтов
				// с остальными действиями.
				f.Create().Close();
				created = true;
			}

			tmpPath = f.Directory.FullName + 
				$"\\~{f.Name.Split(".".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)[0]}.tmp";
			
			Utils.PrintEncolored((created ? "Создан": "Открыт") + " файл\n\n", ConsoleColor.Cyan);
			Console.WriteLine(f.FullName + "\n");
		}

		/// <summary> Подготавливается к завершению работы с файлом сохраняя все его изменения. </summary>
		private void SaveFile()
		{
			if (!File.Exists(tmpPath)) return;
			
			Console.Write((!ChangeAttempt
				? "Найдены несохраненные данные предыдущей сессии!\nВосстановить их?"
				: "Сохранить изменения?") + " [Д/н] :> ");
			char key = Console.ReadKey().KeyChar;
			switch (char.ToLower(key)) {
				case 'д': case 'y': case 'l':
					// Измененения нужны пользователю - сохраняем их.
					Save(allowWarning: false);
					break;
				default:
					// Измененения не нужны пользователю - удаляем их.
					File.Delete(tmpPath);
					break;
			}
			
			Console.WriteLine();
		}

		/// <summary> Сохраняет все изменения файла. </summary>
		private void Save(bool allowWarning = true)
		{
			if (!File.Exists(tmpPath)) return;

			// Это предупреждение сделано специально для команды 's'
			if (allowWarning && !ChangeAttempt)
			{
				// Ситуация когда файл ~fileName.tmp существует, но
				// попыток изменений файла в этой сессии не было означает то,
				// что файл был создан во время предыдущей сессии с онным. 
				// Та сессия была завершена некорректно, несохраненные данные
				// всё еще лежат в ~fileName.tmp, посему всё же предлагаем сохранить их.
				Console.Write("Вы пытаетесь сохранить несохраненные данные предыдущей сессии!\n" +
							  "Желаете сделать это? [Д/н] :> ");
				char key = Console.ReadKey().KeyChar;
				switch (char.ToLower(key)) {
					case 'д': case 'y': case 'l': break;
					default:
						Utils.PrintEncolored("\nОтменено.\n");
						return;
				}
			}

			// Сохраняем временный файл.
			File.Delete(path);
			File.Move(tmpPath, path);
			changeAttempt = false;

			Utils.PrintEncolored("\nСохранено.\n");
		}

		/// <summary> Заменяет строки с номерами от first до last на строку newLine. </summary>
		private void ReplaceLines(int first, int last, string newLine)
		{
			if (last < first) throw new ArgumentOutOfRangeException(nameof(last), last, null);

			ReplaceLine(first, newLine);
			DeleteLines(first + 1, last);
		}

		/// <summary> Заменяет строку с номером n на строку newLine. </summary>
		private void ReplaceLine(int n, string newLine)
		{
			ChangeAttempt = true;

			string[] document;

			// Читаем весь документ в массив строк. 
			using (StreamReader sr = new StreamReader(tmpPath, Encoding.Default))
				document = sr.ReadToEnd().Split(Environment.NewLine.ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

			File.WriteAllText(path, ""); // очищаем файл перед записью
			using (StreamWriter sw = new StreamWriter(tmpPath, false, Encoding.Default))
			{
				for (int i = 0; i < document.Length; ++i)
				{
					if (i+1 == n) {
						sw.WriteLine(newLine); // вставляем указанную строку вместо n-ной
						continue;
					}

					sw.WriteLine(document[i]); // записываем очередную строку документа
				}
			}
		}

		/// <summary> Удаляет строки с номерами от first до last. </summary>
		private void DeleteLines(int first, int last)
		{
			if (last < first) throw new ArgumentOutOfRangeException(nameof(last), last, null);

			for (int i = first; i < last; i++)
				DeleteLine(i);
		}

		/// <summary> Удаляет строку с номером n. </summary>
		private void DeleteLine(int n)
		{
			ChangeAttempt = true;

			string[] document;

			// Читаем весь документ в массив строк. 
			using (StreamReader sr = new StreamReader(tmpPath, Encoding.Default))
				document = sr.ReadToEnd().Split(Environment.NewLine.ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

			if (n < 1 || n > document.Length)
				throw new ArgumentOutOfRangeException(nameof(n), n, "Строки с указанным номером не существует!");

			File.WriteAllText(path, ""); // очищаем файл перед записью
			using (StreamWriter sw = new StreamWriter(tmpPath, false, Encoding.Default))
			{
				for (int i = 0; i < document.Length; ++i)
				{
					if (i+1 == n) continue; // не записываем n-ный элемент

					sw.WriteLine(document[i]); // записываем очередную строку документа
				}
			}
		} // DeleteLine::END

		/// <summary> Добавляет строки в конец файла. </summary>
		private void AppendLines()
		{
			ChangeAttempt = true;

			while (true)
			{
				Console.Write("* ");
				string str = Console.ReadLine(); // читаем очередную строку

				if (str == "%%%") break; // признак конца ввода

				// Записываем в файл.
				using (StreamWriter sw = new StreamWriter(tmpPath, true, Encoding.Default))
					sw.WriteLine(str);
			}
		}

		/// <summary> Вставляет строку insString перед номером n. </summary>
		private void InsertLine(int n, string insString)
		{
			ChangeAttempt = true;

			string[] document;

			// Читаем весь документ в массив строк.
			using (StreamReader sr = new StreamReader(tmpPath, Encoding.Default))
				document = sr.ReadToEnd().Split(Environment.NewLine.ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

			if (n < 1 || n > document.Length)
				throw new ArgumentOutOfRangeException(nameof(n), n, "Строки с указанным номером не существует!");
			
			File.WriteAllText(path, ""); // очищаем файл перед записью
			using (StreamWriter sw = new StreamWriter(tmpPath, false, Encoding.Default))
			{
				for (int i = 0; i < document.Length; ++i)
				{
					if (i+1 == n) sw.WriteLine(insString); // вставляем указанную строку перед n-ной строкой

					sw.WriteLine(document[i]); // записываем очередную строку документа
				}
			}
		}

		/// <summary> Показывает строки с номерами от first до last. </summary>
		private void ShowLines(int first, int last)
		{
			if (last < first) throw new ArgumentOutOfRangeException(nameof(last), last, null);
			
			using (StreamReader sr = new StreamReader(ChangeAttempt ? tmpPath : path, Encoding.Default))
			{
				for (int i = 1; !sr.EndOfStream; i++)
				{
					string str = sr.ReadLine(); // читаем из файла каждую строку
					if (i >= first && i <= last) Console.WriteLine(str);
				} // for i
			} // using
		}

		/// <summary> Показывает строку с номером n. </summary>
		private void ShowLine(int n)
		{
			using (StreamReader sr = new StreamReader(ChangeAttempt ? tmpPath : path, Encoding.Default))
			{
				for (int i = 1; !sr.EndOfStream; i++)
				{
					string str = sr.ReadLine(); // читаем из файла каждую строку
					if (i == n)
					{
						Console.WriteLine(str);
						break;
					}
				} // for i
			} // using
		}

		/// <summary> Показывает весь документ. </summary>
		private void ShowDoc()
		{
			using (StreamReader sr = new StreamReader(ChangeAttempt ? tmpPath : path, Encoding.Default))
				Console.WriteLine(sr.ReadToEnd());
		}

		/// <summary> Выводит справку. </summary>
		private static void ShowHelp()
		{
			Utils.PrintEncolored("\nСписок команд\n\n", ConsoleColor.Cyan);

			const string commands = "hflidrsq";
			foreach (char cmd in commands) Console.WriteLine(GetSignature(cmd));
			Console.WriteLine();
		}

		private static string GetSignature(char cmd)
		{
			switch (cmd)
			{
				case 'h':
					return "h или help     - вывести список всех команд";
				case 'f':
					return "f путь_к_файлу - открыть файл для обработки";
				case 'l':
					return "l              - показать весь документ\n" +
						   "l с1           - показать строку с номером с1\n" +
						   "l с1, с2       - показать строки с номерами от c1 до с2";
				case 'i':
					return "i              - добавить строки в файл (%%% для выхода)\n" +
						   "i c1 string    - вставить строку string перед строкой с номером с1";
				case 'd':
					return "d c1           - удалить строку с номером с1\n" +
						   "с1, с2         - удалить строки с номерами от с1 до с2";
				case 'r':
					return "r с1 string    - заменить строку с номером с1 на строку string\n" +
						   "r с1 с2 string - заменить строки с номерами от с1 до с2 на строку string";
				case 's':
					return "s              - сохранить файл";
				case 'q':
					return "q              - выход";
				default:
					return string.Empty;
			}
		}
	}
}