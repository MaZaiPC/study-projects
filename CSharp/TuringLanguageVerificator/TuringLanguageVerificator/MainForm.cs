// Форма, предоставляющая графические средства для взаимодействия пользователя с машиной Тьюринга.
// MainForm.cs

using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace Moreniell.CourseWork
{
	public partial class MainForm : Form
	{
		// Экземпляр класса представляющего машину Тьюринга распознающую наш язык.
		private readonly TuringMachine turingMachine = new TuringMachine();

		// Конструктор формы по-умолчанию.
		public MainForm()
		{
			// Инициализация компонентов формы.
			InitializeComponent();

			// Событие TextChanged зажигается при изменении текстового содержимого контрола.
			inputWord.TextChanged += (sender, args) => feedback.Text = "";

			// Событие Click зажигается при нажатии на контрол левой кнопкой мыши.
			mniExit.Click += (sender, args) => Application.Exit();
		}

		// Событие KeyPress зажигается при нажатии любой клавиши, если фокус принадлежит этому контролу.
		//--------------------------------------------------------------------------
		// Выполняет проверку ввода на допустимые символы.
		private void maskedTextBox1_KeyPress(object sender, KeyPressEventArgs e)
		{
			// Массив кодов всех разрешенных символов.
			byte[] allowedChars = { 0x61, 0x62, 0x3, 0x16, 0x18, 0xd, 0x8 };

			// Если нажатый символ не содержится среди допустимых символов - отменяем его ввод.
			if (!allowedChars.Contains((byte)e.KeyChar)) e.KeyChar = '\0';

			// Если код символа соответствует клавише ENTER - запускаем обработку введенных данных.
			if (e.KeyChar == 0xd)
			{
				buttonCheckWord_Click(sender, EventArgs.Empty);
				e.Handled = true; // признак того, что нажатая клавиша прошла валидацию
			}
		}

		// Событие Click зажигается при нажатии на контрол левой кнопкой мыши.
		//--------------------------------------------------------------------------
		// Запускает машину Тьюринга.
		private void buttonCheckWord_Click(object sender, EventArgs e)
		{
			// Подписка на события проистекающие в машине Тьюринга. Благодаря этому
			// графический интерфейс узнает о работе МТ и может выводить
			// все необходимые данные на экран. Таким образом достигается разделение
			// разделение логики и интерфейса программы.
			SubscribeEvents();

			// Запуск машины Тьюринга.
			turingMachine.Manage(inputWord.Text);

			// Отписка от событий машины Тьюринга.
			UnsubscribeEvents();

			// Протокол формируется во время работы МТ.
			// Работа МТ завершена, значит протоколы сформированы, а это
			// означает что теперь мы можем включить опцию их сохранения.
			mniSaveAs.Enabled = true;
		}

		// Событие Managing зажигается при запуске машины Тьюринга.
		//--------------------------------------------------------------------------
		// Очищает список, который потенциально может хранить предыдущий протокол работы МТ.
		private void turingMachine_Managing(object sender, EventArgs e) => listBoxResult.Items.Clear();

		// Событие IterationOfManaging зажигается перед выполнением каждого такта машины Тьюринга.
		//--------------------------------------------------------------------------
		// Добавляет в список информацию о состоянии МТ перед выполнением очередного такта.
		private void turingMachine_IterationOfManaging(object sender, IterationOfManagingEventArgs e)
		{
			// Формируем строку и добавляем в список.
			listBoxResult.Items.Add(
				e.OperationsLeft	// кол-во пройденных тактов
				+ ". " + "(q" +
				e.MachineState		// состояние МТ
				+ ", (" +
				e.CurrentCells[0]	// значение первой ленты
				+ ", " +
				e.CurrentCells[1]	// значение второй ленты
				+ "))");
		}

		// Событие ActionPeformed зажигается после выполнения каждого такта машины Тьюринга.
		//--------------------------------------------------------------------------
		// Добавляет к последнему элементу списка информацию об изменениях полученных
		// в следствии выполнения очередного такта. Таким образом формируется протокол работы МТ.
		private void turingMachine_ActionPeformed(object sender, ActionPeformedEventArgs e)
		{
			// Формируем строку.
			var sb = new StringBuilder(" ➜ ");
			
			// Если состояние МТ совпадает с условно принятым за "УСПЕХ", то выводим сообщение о том,
			// что машина Тьюринга завершила свою работу корректно.
			if (e.MachineState == TuringMachine.SuccessCode) sb.Append("STOP");
			
			// Если же состояние МТ совпадает с условно принятым за "НЕУДАЧА", то выводим сообщение о том,
			// что машина Тьюринга завершила свою работу некорректно.
			else if (e.MachineState == TuringMachine.SyntaxErrorCode) sb.Append("ERROR");

			// Иначе записываем полную информацию об изменениях полученных
			// в следствии выполнения этого такта.
			else
			{
				sb.Append("(q")
					.Append(e.MachineState)		// перешли в новое состояние ...
					.Append(", (")
					.Append(e.CurrentCells[0])	// заменили значение первой ленты на ...
					.Append(", ")
					.Append(e.CurrentCells[1])  // заменили значение второй ленты на ...
					.Append("), (")
					.Append(Enum.GetName(typeof(MoveHead), e.Move1)[0]) // головка на первой ленте сдвинулась в ... направлении
					.Append(", ")
					.Append(Enum.GetName(typeof(MoveHead), e.Move2)[0]) // головка на второй ленте сдвинулась в ... направлении
					.Append("))");
			}

			// Выполняем конкатенацию строк.
			listBoxResult.Items[listBoxResult.Items.Count - 1] += sb.ToString();
		}

		// Событие Managed зажигается по окончанию работы машины Тьюринга.
		//--------------------------------------------------------------------------
		// Выводит на экран информацию о том, успешно ли завершена работа МТ.
		private void turingMachine_Managed(object sender, ManagedEventArgs e)
		{
			// Делаем окно шире т.к. теперь у нас появляется график для которого нужно больше места.
			this.Width = 889;

			// Выводим информацию о том распознан ли язык МТ.
			if (e.MachineState == TuringMachine.SuccessCode)
				feedback.Text = $"Указанное слово принадлежит языку\n{{{TuringMachine.LanguageSyntax}}}";
			else if (e.MachineState == TuringMachine.SyntaxErrorCode)
				feedback.Text = $"Указанное слово не принадлежит языку\n{{{TuringMachine.LanguageSyntax}}}";

			// Выполняем построения графика временной сложности МТ.
			RenderChart(turingMachine.Max);
		}

		// Метод генерирует график временной сложности машины Тьюринга.
		//--------------------------------------------------------------------------
		// Сложность O(n+1)
		private void RenderChart(IReadOnlyDictionary<KeyValuePair<int, int>, int> max)
		{
			chart1.Series.Clear();
			var series1 = new Series();
			var series2 = new Series();
			series1.ChartType = SeriesChartType.Line;
			series2.ChartType = SeriesChartType.Line;
			series1.Name = "Лента 1"; series1.Color = Color.Red;
			series2.Name = "Лента 2"; series2.Color = Color.DarkOrange;
			chart1.Series.Add(series1);
			chart1.Series.Add(series2);
			chart1.Refresh();

			foreach (var pair in max)
			{
				int tapeNumber = pair.Key.Key;
				int x = pair.Key.Value;
				chart1.Series[tapeNumber].Points.AddXY(x, pair.Value);
				chart1.Series[tapeNumber].Points[x].Label = pair.Value.ToString();
				chart1.Series[tapeNumber].Points[x].MarkerColor = tapeNumber == 0 ? Color.Red : Color.DarkOrange;
				chart1.Series[tapeNumber].Points[x].MarkerSize = 5;
				chart1.Series[tapeNumber].Points[x].MarkerStyle = MarkerStyle.Square;
			}
		}

		// Метод выполняет подписку слушателей к событиям проистекающим в машине Тьюринга.
		//--------------------------------------------------------------------------
		// Благодаря этому графический интерфейс узнает о работе МТ и может выводить
		// все необходимые данные на экран. Таким образом достигается разделение
		// разделение логики и интерфейса программы.
		private void SubscribeEvents()
		{
			turingMachine.Managing += turingMachine_Managing;
			turingMachine.Managed += turingMachine_Managed;
			turingMachine.IterationOfManaging += turingMachine_IterationOfManaging;
			turingMachine.ActionPeformed += turingMachine_ActionPeformed;
		}

		// Метод выполняет отписку слушателей от событий машины Тьюринга.
		//--------------------------------------------------------------------------
		// Делать это необходимо для корректной работы сборщика мусора.
		private void UnsubscribeEvents()
		{
			turingMachine.ActionPeformed -= turingMachine_ActionPeformed;
			turingMachine.IterationOfManaging -= turingMachine_IterationOfManaging;
			turingMachine.Managed -= turingMachine_Managed;
			turingMachine.Managing -= turingMachine_Managing;
		}

		// Событие Click зажигается при нажатии на контрол левой кнопкой мыши.
		//--------------------------------------------------------------------------
		// Выполняет сохранение протокола работы машины Тьюринга в текстовый документ.
		private void mniSaveAs_Click(object sender, EventArgs e)
		{
			// Запускаем диалог выбора файла для сохранения.
			if (saveFileDialog.ShowDialog() == DialogResult.OK)
			{
				// Открываем поток для записи в указанный файл.
				using (StreamWriter sw = new StreamWriter(saveFileDialog.FileName))
				{
					foreach (string line in listBoxResult.Items)
					{
						// Записываем все протоколы в указанный файл (без нумерации)
						sw.WriteLine(line.Substring(line.IndexOf('(')));
					}
				} // тут неявно выполняется Dispose()
			}
		}
	}
}
