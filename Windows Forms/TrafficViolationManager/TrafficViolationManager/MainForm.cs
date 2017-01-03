using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Xml.Serialization;
using MaZaiPC.TrafficViolationManager.Model;
using MaZaiPC.TrafficViolationManager.Properties;

namespace MaZaiPC.TrafficViolationManager
{
	public partial class MainForm : Form
	{
		// XML-сериализатор.
		private readonly XmlSerializer _xmls;

		// Указывает, будет ли при попытке записи создаваться новый файл.
		private bool _isNewFile;

		// Полное имя открытого файла.
		private string _fileName;

		// Конструктор формы.
		public MainForm()
		{
			InitializeComponent();

			// Т.к. в начале работы программы будет создана новая
			// таблица, указываем, что при попытке записи будет
			// создаваться новый файл.
			_isNewFile = true;

			// Привязка набора к таблице во время исполнения приложения.
			violatorBindingSource.DataSource = new List<Violator>();

			// Привязка истории к подчиненной таблице.
			violationBindingSource.DataSource = violatorBindingSource;
			violationBindingSource.DataMember = "HistoryOfViolations";

			// Создать XML сериализатор - для сохранения данных из коллекции в XML-формате.
			_xmls = new XmlSerializer(typeof(List<Violator>));

			// Цвет правой части статус-бара будет красный, т.к. это область
			// для вывода сообщений об ошибках.
			sbRight.ForeColor = System.Drawing.Color.Red;
		}

		#region Обработка кликов

		// Событие Click зажигается при нажатии на контрол левой кнопкой мыши.
		private void newFile_Click(object sender, EventArgs e)
		{
			// Если предыдущий файл не сохранен, то показываем предупреждение.
			if (SaveBeforeClosingDialog() == DialogResult.Cancel) return;
			
			violatorBindingSource.Clear(); // очищаем источник данных
			_isNewFile = true;			   // устанавливаем признак нового файла
			SaveEnabled(false);			   // выключаем опции сохранения
		}

		// Событие Click зажигается при нажатии на контрол левой кнопкой мыши.
		private void openFile_Click(object sender, EventArgs e)
		{
			// Если предыдущий файл не сохранен, то показываем предупреждение.
			if (SaveBeforeClosingDialog() == DialogResult.Cancel) return;

			// Запускаем диалог открытия файла.
			if (openFileDialog.ShowDialog() == DialogResult.OK)
			{
				// По нажатию "ОК" выполняем следующие действия:
				
				// Сохраняем имя файла для дальнейшего использования.
				_fileName = openFileDialog.FileName;

				// Выполняем десериализацию таблицы из указанного файла.
				Deserialize(_fileName);

				// Сбрасываем признак нового файла.
				_isNewFile = false;
			}
		}

		// Событие Click зажигается при нажатии на контрол левой кнопкой мыши.
		private void saveFile_Click(object sender, EventArgs e)
		{
			// Если файл должен быть новым, то запускаем операцию "Сохранить как..."
			if (_isNewFile) {
				saveFileAs_Click(sender, EventArgs.Empty);
			}
			
			// Иначе выполняем сериализацию таблицы в указанный файл.
			else {
				Serialize(_fileName);
			}
		}

		// Событие Click зажигается при нажатии на контрол левой кнопкой мыши.
		private void saveFileAs_Click(object sender, EventArgs e)
		{
			// Запускаем диалог сохранения файла.
			if (saveFileDialog.ShowDialog() == DialogResult.OK)
			{
				// Сохраняем имя файла для дальнейшего использования.
				_fileName = saveFileDialog.FileName;

				// Выполняем сериализацию таблицы в указанный файл.
				Serialize(_fileName);

				// Сбрасываем признак нового файла.
				_isNewFile = false;
			}
		}

		// Событие Click зажигается при нажатии на контрол левой кнопкой мыши.
		private void mniAbout_Click(object sender, EventArgs e)
		{
			// Открываем форму "О программе..."
			new AboutForm().ShowDialog();
		}

		// Событие Click зажигается при нажатии на контрол левой кнопкой мыши.
		private void mniExit_Click(object sender, EventArgs e)
		{
			// Закрываем приложение.
			Application.Exit();
		}

		// Событие Click зажигается при нажатии на контрол левой кнопкой мыши.
		private void bindingNavigatorDeleteItem_Click(object sender, EventArgs e)
		{
			// Строка удалена, что означает таблица была изменена. Посему, включаем опции сохранения.
			SaveEnabled(true);
		}

		// Событие Click зажигается при нажатии на контрол левой кнопкой мыши.
		private void mniHelp_Click(object sender, EventArgs e)
		{
			// TODO: Сделать форму Helper-а.
		}

		// Событие FormClosing зажигается при попытке закрытия формы.
		private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
		{
			// Если данные таблицы не сохранены, то показываем предупреждение.
			if (SaveBeforeClosingDialog() == DialogResult.Cancel)
			{
				e.Cancel = true;
			}
		}

		#endregion

		#region Сериализация

		// Метод выполняет сериализацию данных о нарушителях указанный в файл.
		private void Serialize(string fileName)
		{
			// Если текущая строка является новой, то переключаемся на существующую.
			if (gridViolations.CurrentRow != null && gridViolations.CurrentRow.IsNewRow)
			{
				gridViolations.CurrentCell = gridViolations[0, gridViolations.RowCount - 2];
			}
			
			// Если таблица в режиме редактирования ячейки, то заканчиваем редактирование принудительно.
			if (gridViolations.CurrentCell.IsInEditMode)
			{
				gridViolations.EndEdit();
			}

			// Выполняем сериализацию в XML файл.
			using (var sw = new StreamWriter(fileName, false, Encoding.Default))
			{
				_xmls.Serialize(sw, violatorBindingSource.DataSource);
			}

			// Выключаем опции сохранения.
			SaveEnabled(false);
		}

		// Метод выполняет десериализацию данных о нарушителях из указанного файла.
		private void Deserialize(string fileName)
		{
			// Приостанавливаем привязку данных.
			violatorBindingSource.SuspendBinding();

			// Выполняем десериализацию из XML файла.
			using (var sr = new StreamReader(fileName, Encoding.Default))
			{
				violatorBindingSource.DataSource = _xmls.Deserialize(sr);
			}

			// Возобновляем привязку к измененному источнику данных.
			violatorBindingSource.ResumeBinding();
			
			// Выключаем опции сохранения.
			SaveEnabled(false);
		}

		#endregion

		#region Прочие манипуляции

		// Метод предлагает сохранить файл перед закрытием. При нажатии на "Да" сохраняет файл.
		private DialogResult SaveBeforeClosingDialog()
		{
			DialogResult result = DialogResult.None;

			if (btnSaveFile.Enabled) // если опции сохранения включены
			{
				// Выводим предупреждение о рисках закрытия текущей таблицы без сохранения.
				result = MessageBox.Show(
					Strings.CloseFileMsg, Strings.CloseFileTitle, MessageBoxButtons.YesNoCancel);

				switch (result)
				{
					case DialogResult.Yes: // вероятно, пользователь решил сохраниться
						saveFile_Click(null, EventArgs.Empty); // послушно выполняем приказ
						break;
				}
			}
			return result; // возвращаем результат нажатия одной из кнопок
		}

		// Событие SelectionChanged зажигается при изменении выделения.
		private void gridViolations_SelectionChanged(object sender, EventArgs e)
		{
			if (gridViolations.CurrentRow != null && !gridViolations.CurrentRow.IsNewRow)
			{
				// Узнаем фамилию и инициалы выбранного нарушителя.
				string famIO = (string)gridViolations.CurrentRow.Cells[1].Value;
				
				if (!string.IsNullOrEmpty(famIO)) // если оно вообще существует
				{
					// Выводим подсказку во вкладке истории.
					historySubjectTooltip.Text = string.Format(Strings.HistorySubjTooltip, famIO);
				}
			}
			else // если нарушитель не выбран
			{
				// Выводим стандартную подсказку во вкладке истории.
				historySubjectTooltip.Text = Strings.HistoryTooltipDefault;
			}
		}

		// Включает или выключает все кнопки отвечающие за сохранения данных в файл.
		private void SaveEnabled(bool value)
		{
			btnSaveFile.Enabled = mniSaveFile.Enabled = btnSaveFileAs.Enabled = mniSaveFileAs.Enabled = value;
		}

		// Событие RowEnter зажигается когда строка получает фокус ввода, но перед этим становится текущей строкой.
		private void gridHistory_RowEnter(object sender, DataGridViewCellEventArgs e)
		{
			// Если текущая строка не является новой, то выходим из метода.
			if (!gridHistory.Rows[e.RowIndex].IsNewRow) return;

			// Устанавливаем ID для очередной записи в истории.
			gridHistory[0, e.RowIndex].Value = e.RowIndex + 1;
		}

		private void dataGridView_RowsAdded(object sender, DataGridViewRowsAddedEventArgs e)
		{
			// Деактивируем кнопку удаления, для избавления от бага, из за которого при попытке
			// удаления единственной (пустой) строки кнопки сохранения активируются без надобности,
			// т.к. сохранять пустой документ - бессмысленно.
			bindingNavigatorDeleteItem.Enabled = ((DataGridView)sender).RowCount > 1;
		}

		#endregion

		#region Валидация ячеек

		// Метод проверяет каждую ячейку строки и бросает соответствующее исключение если она не прошла валидацию.
		private void ValidateRow(DataGridView source, int rowIndex)
		{
			if (rowIndex < 0) throw new InvalidDataException(); // индекс не может быть меньше нуля
			if (source.Rows[rowIndex].IsNewRow) return; // проверять новые строки на валидность бессмысленно

			// Получаем строку по индексу.
			DataGridViewRow row = source.Rows[rowIndex];

			// Проверяем на валидность каждую ячейку строки.
			for (int i = 0; i < row.Cells.Count; ++i)
			{
				ValidateCell(row.Cells[i]);
			} // for i
		}

		// Метод проверяет ячейку и бросает соответствующее исключение если она не прошла валидацию.
		private void ValidateCell(DataGridViewCell cell)
		{
			// Если ячейки не существует, то бросаем исключение.
			if (cell == null) throw new ArgumentNullException(nameof(cell));

			// Получаем имя текущей колонки
			string columnHeader = cell.OwningColumn.HeaderText;

			// Если текущая ячейка принадлежит диапазону от 1-го до 5-ти, то проверяем её.
			if (cell.ColumnIndex >= 1 && cell.ColumnIndex <= 5)
			{
				switch (cell.ValueType.Name) // определяем тип ячейки
				{
					case "String":   // здесь проверяем строки
						if (cell.Value == null || (string) cell.Value == string.Empty)
							throw new InvalidDataException(string.Format(Strings.ValueRequriedError, columnHeader));
						return;
					case "DateTime": // а здесь даты
						var dt = (DateTime) cell.Value;
						if (dt == new DateTime())
							throw new InvalidDataException(string.Format(Strings.ValueRequriedError, columnHeader));
						if (dt > DateTime.Today)
							throw new InvalidDataException(string.Format(Strings.WrongViolationDate, columnHeader));
						return;
					case "Double":  // а тут числа двойной точности
						if ((double) cell.Value == 0D)
							throw new InvalidDataException(string.Format(Strings.ValueRequriedError, columnHeader));
						return;
				}
			}
		}

		// Событие RowValidating зажигается при проверке валидности строки.
		private void dataGridView_RowValidating(object sender, DataGridViewCellCancelEventArgs e)
		{
			// Фикс ситуации, когда gridHistory появлялся в sender-е во время работы с gridViolations.
			if (e.ColumnIndex == 0) return;

			try
			{
				// Проверяем указанный столбец указанной таблицы.
				ValidateRow(((DataGridView) sender).Name == "gridViolations" ? gridViolations : gridHistory, e.RowIndex);
			}
			catch (InvalidDataException ex) // если проверка не пройдена
			{
				// Приписываем текущей строке сообщение об ошибке.
				((DataGridView) sender).Rows[e.RowIndex].ErrorText = ex.Message;

				// Выводим сообщение про ошибку валидации в статус баре.
				sbRight.Image = string.IsNullOrEmpty(ex.Message) ? null : Resources.BadExclamationIcon;
				sbRight.Text = ex.Message;

				// Отменяем событие.
				e.Cancel = true;

				// Выключаем опции сохранения.
				SaveEnabled(false);
			}
		}

		// Событие CellValueChanged зажигается при изменении значения ячейки.
		// Прошу не путать с изменением содержимого в режиме редактирования ячейки!
		private void dataGridView_CellValueChanged(object sender, DataGridViewCellEventArgs e)
		{
			if (gridViolations.CurrentRow != null)
			{
				sbRight.Image = null;
				sbRight.Text = gridViolations.CurrentRow.ErrorText = string.Empty;
			}

			try
			{
				ValidateRow(((DataGridView)sender).Name == "gridViolations" ? gridViolations : gridHistory, e.RowIndex);
			}
			catch (InvalidDataException) { return; }
			SaveEnabled(true);
		}


		#endregion

		#region Управление статус баром

		// Событие MouseEnter зажигается когда указатель мыши оказывается на элементе управления.
		private void toolStripItem_MouseEnter(object sender, EventArgs e)
		{
			// Приводим отправителя к базовому типу элемента ToolStrip.
			var item = sender as ToolStripItem;

			// Выводим текст подсказки в левой части статус-бара.
			if (item != null) sbLeft.Text = item.ToolTipText;
		}

		// Событие MouseLeave зажигается когда указатель мыши покидает элемент управления.
		private void toolStripItem_MouseLeave(object sender, EventArgs e)
		{
			// Выводим текст, сообщающий состояние готовности, в левой части статус-бара.
			sbLeft.Text = Strings.StatusReady;
		}

		#endregion
	}
}
