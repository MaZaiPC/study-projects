using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DataGridView_DataBinding
{
    public partial class MainForm : Form
    {
        private List<Student> students;      // имя набора данных в памяти
        private readonly XmlSerializer xmls; // XML-сериализатор
        private string fileName;             // имя файла с набором данных

	    private const string EXTENTION = "students";       // расширение для файлв набора данных
	    private const string DEFAULT_NAME = "Безымянный";  // им файла по умолчанию

        // заголовок окна, общая часть заголовка. Полный заголовок это:
        // общая часть и имя обрабатываемого файла
	    private const string DEFAULT_TEXT = "Данные о студентах";

        public MainForm()
        {
            InitializeComponent();

            students = new List<Student>();     // набор данных
            bnsDataGrid.DataSource = students;  // привязка набора к таблице во время исполнения приложения
            // !!! Привязка к типу (объекту класса Students на время разработки дала возможность
            // настройки таблицы. Привязка к набору данных во время исполнения дает возможность
            // менять данные в наборе и автоматически менять их отображение в таблице и, наоборот,
            // меняя данные в таблице мы меняем их в наборе данных

            // Создать XML сериализатор - для сохранения данных из коллекции в XML-формате
            xmls = new XmlSerializer(typeof(List<Student>));

            // Имя файла с набором данных - по умолчанию "Безымянный";
            fileName = DEFAULT_NAME + "." + EXTENTION;
            Text = DEFAULT_TEXT + " - " + fileName;
        } // MainForm

        // Выход из приложения 
        private void mniExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        } // mniExit_Click

        // Проверка данных на уровне строки
        private void dgvMain_RowValidating(object sender, DataGridViewCellCancelEventArgs e)
        {
            // Если это последняя строка - не проверять ее, молча уходить
            if (dgvMain.Rows[e.RowIndex].IsNewRow) return;

            // Для остальных строк проверяем заполнение поля Фамилия И.О.
            string errMsg = "";
            if (dgvMain[1, e.RowIndex].Value == null) {
                errMsg = @"Поле ""Фамилия И.О."" должно быть заполнено";
            } // if

            // Вывести или стереть сообщение об ошибке
            dgvMain.Rows[e.RowIndex].ErrorText = errMsg;

            // Оставить пользователя в строке или уйти из строки 
            e.Cancel = errMsg != "";
        } // dgvMain_RowValidating


        // Обработка ошибок на уровне ячейки - для каждой ячейки отдельный вызов
        private void dgvMain_CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
        {
            // Если это последняя строка - не проверять ее, молча уходить
            if (dgvMain.Rows[e.RowIndex].IsNewRow) return;

            string s = e.FormattedValue.ToString();  // значение, прочитанное из ячейки
            string errMsg = "";                      // предполагаем, что ошибок нет
            string header = dgvMain.Columns[e.ColumnIndex].HeaderText + ": ";

            int temp;   // переменная для проверки преобразования строки в число

            // Проверяем ошибки по столбцам - для каждого столбца система выполняет отдельный
            // выхов этого метода проверки 
            switch (e.ColumnIndex) {
                case 0:   // Идентификатор
                case 4:   // Курс
                    if (int.TryParse(s, out temp)) {
                        if (temp < 0)
                            errMsg = header + "Отрицательные числе не допускаются";
                    } else
                        errMsg = header + "Ожидается ввод целого положительного числа";
                    break;

                case 1:   // Фамилия И.О.
                case 2:   // Пол
                case 5:   // Группа
                    if (s == "") errMsg = header + "Поле должно быть заполнено";
                    break;

                case 3:   // Дата рождения
                    if (s == "") {
                        errMsg = header + "Поле должно быть заполнено";
                        break;
                    } // if

                    DateTime dt;
                    if (DateTime.TryParse(s, out dt)) {
                        // Прошло преобразование в дату, проверим возраст
                        int age = DateTime.Today.Year - dt.Year;
                        if (age < 15 || age > 55)
                            errMsg = header + "Возраст студента должен быть в диапазоне от 15 до 55 лет";
                    } else {
                        errMsg = header + "Ожидается ввод даты в формате дд/мм/гггг";
                    } // if
                    break;
            } // switch

            // Вывести или стереть сообщение об ошибке
            dgvMain.Rows[e.RowIndex].ErrorText = errMsg;

            // Оставить пользователя в строке или уйти из строки 
            e.Cancel = errMsg != "";
        } // dgvMain_CellValidating


        // Сохранить текущие данные в  файле
        private void mniSave_Click(object sender, EventArgs e)
        {
            // Защита от записи пустого набора данных
            // Т.е. не записывать данные в файл, если в таблице только одна строка
            // (управляющая строка для ввода новой записи) 
            if (dgvMain.RowCount == 1) {
                tslMain.ForeColor = System.Drawing.Color.Red;
                tslMain.Text = "Нельзя записать пустой набор данных";
                return;
            } // if

            // Если имя файла не задано, то запросить имя файла для редактирования
            if (fileName == DEFAULT_NAME + "." + EXTENTION) {
                if (sfdStudents.ShowDialog() != DialogResult.OK)
                    return;
                else {
                    fileName = sfdStudents.FileName;
                    Text = DEFAULT_TEXT + " - " + Path.GetFileName(fileName);
                } // if 
            } // if

            SaveData();
        } // mniSave_Click


        // При выборе пункта меню "Файл" вывести в строку состояния текст "Готово"
        private void mniFile_Click(object sender, EventArgs e)
        {
            tslMain.ForeColor = System.Drawing.Color.Black;
            tslMain.Text = "Готово";
        } // mniFile_Click


        // Загрузка файла данных
        private void mniLoad_Click(object sender, EventArgs e)
        {
            // Сохранение данных (если есть, что сохранять)
            if (dgvMain.RowCount > 1) SaveData();

            // Если не выбрано имя файла для сохранения, то молча выходим
            if (ofdStudents.ShowDialog() != DialogResult.OK) return;
            fileName = ofdStudents.FileName;
            Text = DEFAULT_TEXT + " - " + Path.GetFileName(fileName);
            LoadData();
        } // mniLoad_Click


        // Сохранение данных в XML-файле
        private void SaveData() {
            // Перред записью выполняется обмен между DGV и нашими данными
            // Если текущая строка DGV последняя, то некорректные данные
            // (пустая строка) пишутся в файл
            // Для исправления - делаем текущей строкой последнюю заполненную строку
            // RowCount-2 --> это и есть последняя заполненнся строка
            if (dgvMain.CurrentRow.IsNewRow) dgvMain.CurrentCell = dgvMain[0, dgvMain.RowCount - 2];

            using (StreamWriter sw = new StreamWriter(fileName, false, Encoding.Default)) {
                xmls.Serialize(sw, students);
            } // using
        } // SaveData

        // Загрузка данных из XML-файла
        private void LoadData()
        {
            // Для отображения загружаемых данных надо отключить привязку перед загрузкой
            // и включить привязку к данным после загрузки из файла данных
            bnsDataGrid.DataSource = null;   // отключение привязки
            using (StreamReader sr = new StreamReader(fileName, Encoding.Default)) {
                students = (List<Student>)xmls.Deserialize(sr);
            } // using
            bnsDataGrid.DataSource = students; // повторное подключение к изменившемуся источнику данных
        } // LoadData


        // Сохраняем данные при закрытии формы - вызов штатного обработчика
        // команды сохранения
        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            // TODO: Запрет завершения работы до окончания редактирования данных
            // Это важно при выходе по команде меню. Если выход по кнопке X в окне 
            // то режим редактирования завершается автоматически 
            // Некорректные данные пропукаются :( 
            if (dgvMain.IsCurrentCellDirty) { 
                e.Cancel = true;
                return;
            } // if
            mniSave_Click(sender, EventArgs.Empty);
        } // MainForm_FormClosing


        // Событие срабатывает, если есть ячейка в режиме редактирования
        // и ячейка изменена, но Enter для закрепления изменений еще не был нажат
        // В таком случае запрещаем и загрузку и сохранения до закрепления измененных
        // данных - до нажатия на Enter
        private void dgvMain_CurrentCellDirtyStateChanged(object sender, EventArgs e)
        {
            // Пока есть ячейка в режиме редактирования - не сохранять данные
            mniNew.Enabled = mniLoad.Enabled = mniSave.Enabled = !dgvMain.IsCurrentCellDirty;

            int row = dgvMain.CurrentRow.Index;
            if ((int)dgvMain["dgcId", row].Value == 0) {
                dgvMain["dgcId", row].Value = GetMaxId() + 1;
            } // if
        } // dgvMain_CurrentCellDirtyStateChanged


        // Возвращает максимальный идентификатор из списка студентов
        private int GetMaxId()
        {
            int maxId = students[0].Id;
            for (int i = 1; i < students.Count(); i++)
                if (students[i].Id > maxId) maxId = students[i].Id;
            return maxId;
        } // GetMaxId

		private void mniNew_Click(object sender, EventArgs e)
		{

		}
	} // class MainForm
}
