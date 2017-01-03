using System;
using System.Globalization;
using System.IO;
using System.Windows.Forms;
using ListViewShip.Model;

namespace ListViewShip.Forms
{
    public partial class MainForm : Form
    {
	    private readonly Ships ships;      // коллекция кораблей
	    private string fileName;           // файл для сохранения/загрузки
	    private EditForm editForm;         // форма для ввода/редактирования данных о корабле 

		// имя файла с картинкой - заместителем
		public static readonly string FileNoImage = @"..\..\Images\NoImage.png";

		public MainForm()
        {
            InitializeComponent();

            // Создать коллекцию кораблей, связь коллекции с элементом
            // интерфейса ListView
	        ships = new Ships
	        {
				// для надежности, т.к. в конструкторах может отсутствовать передача
				// ссылки на ListView в списке параметров, и еще - как через конструктор
				// по умолчанию связаться с ListView? да никак - вот и нужно свойство 
				ShipListView = lvShips
	        };
        } // MainForm


        // Добавление записи в ListView по команде меню (инструментальной кнопке)
        private void mniAdd_Click(object sender, EventArgs e)
        {
            if (editForm == null) editForm = new EditForm();
            editForm.Text = "Добавление корабля в коллекцию";
            if (editForm.ShowDialog() != DialogResult.OK) return;

            // Прочитать данные из формы, добавить их в коллекцию, ListView 
            Ship ship = editForm.Data;
            editForm.Clear(); // Очистка полей, отсоединение от файла фотографии

            // перед добавлением - копировать файл в папку Images проекта,
            // скорректировать имя файла - привести к формату Images\ИмяФайла
            string temp = @"..\..\Images\" + Path.GetFileName(ship.FilePhoto); // новое имя - файл приемник
            File.Copy(ship.FilePhoto, temp);  // копирование из старого места в папку Images проекта
            ship.FilePhoto = temp;            // запомнить новое имя файла

            ships.Add(ship);                  // и, наконец-таки, добавляем корабль

            // Добавить элемент в ListView"
            // a) создать элемент - первый столбец ListView
            ListViewItem item = new ListViewItem($"{ship.Id}");

            // б) создать подэлементы - остальные столбцы
            item.SubItems.Add(ship.Name);
            item.SubItems.Add($"{ship.Displacement}");
            item.SubItems.Add($"{ship.Speed}");
            item.SubItems.Add($"{ship.CruisingRange}");

            // в) собственно добавление в ListView
            lvShips.Items.Add(item);
        } // mniAdd_Click


        // Удаление записи из ListView по команде меню (инструментальной кнопке)
        private void mniRemove_Click(object sender, EventArgs e)
        {
            // проверка - есть ли выбранные элементы
            if (lvShips.SelectedIndices.Count == 0) {
                MessageBox.Show("Корабль для удаления не выбран", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            } // if

            // удаление при помощи "делегированного" метода класса List
            int index = lvShips.SelectedIndices[0];  // индекс выбранного элемента

            // Получить имя файла картинки удаляемого корабля
            string fileName = ships[index].FilePhoto;

            ships.RemoveAt(index);         // удаление из контейнерного класса          
            lvShips.Items.RemoveAt(index); // удаление из элемента интерфейса

            // Удалить файл из папки Images
            if (File.Exists(fileName)) File.Delete(fileName);
        } // mniRemove_Click


        // Выход из приложения по команде меню (инструментальной кнопке)
        private void mniExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        } // mniExit_Click


        // Сохранить коллекцию кораблей в файле - бинарная сериализация
        // (обработка меню и кнопки панели инструментов)
        private void mniSave_Click(object sender, EventArgs e)
        {
            // Если имя файла уже задано, не выводим диалог выбора файла
            if (string.IsNullOrEmpty(fileName)) {
                // Выбираем/задаем файл для сохранения, если не задан - уходим 
                if (sfdMain.ShowDialog() != DialogResult.OK) return;

                // Запомнить имя файла и сохранить коллекцию в этом файле
                fileName = sfdMain.FileName;
            } // if
         
            ships.Save(fileName);
            Text = "Коллекция кораблей, файл - " + fileName;
        } // mniSave_Click


        // Очистка данных
        // (обработка меню и кнопки панели инструментов)
        private void mniNew_Click(object sender, EventArgs e)
        {
            lvShips.Items.Clear();
            ships.Clear();
            fileName = "";
            Text = "Коллекция кораблей";
        } // mniNew_Click


        // Загрузка файла данных, десериализация
        // (обработка меню и кнопки панели инструментов)
        private void mniOpen_Click(object sender, EventArgs e)
        {
            // Выбрать файл для загрузки
            if (ofdMain.ShowDialog() != DialogResult.OK) return;
            fileName = ofdMain.FileName;

            // Загрузить данные в коллекцию, в элемент отображения
            ships.Load(fileName);  // загрузка в коллекцию
            LoadFromShips();       // копирование коллекции в ListView 
            Text = "Коллекция кораблей, файл - " + fileName; // коррекция заголовка окна
        } // mniOpen_Click


        // Очистка ListView, копирование из коллекции в ListVew
        private void LoadFromShips()
        {
            lvShips.Items.Clear();

            // Перебираем коллекцию кораблей
            foreach (Ship ship in ships) {
                // Добавить элемент в ListView"
                // a) создать элемент - первый столбец ListView
                ListViewItem item = new ListViewItem($"{ship.Id}");

                // б) создать подэлементы - остальные столбцы
                item.SubItems.Add(ship.Name);
                item.SubItems.Add($"{ship.Displacement}");
                item.SubItems.Add($"{ship.Speed}");
                item.SubItems.Add($"{ship.CruisingRange}");

                // в) собственно добавление в ListView
                lvShips.Items.Add(item);
            } // foreach
        } // LoadFromShips


        // Обработка команды - редактирование корабля в коллекции
        // (обработка меню и кнопки панели инструментов)
        private void mniEdit_Click(object sender, EventArgs e)
        {
            // Проверка, есть ли нет выбранного элемента в списке ListView - 
            // сообщить об ошибке и выйти
            if (lvShips.SelectedIndices.Count == 0) {
                MessageBox.Show("Корабль для редактирования не выбран", "Ошибка", 
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            } // if

            // Получить индекс выбранного корабля
            int index = lvShips.SelectedIndices[0];

            // Создание формы, при необходимости, настройка формы
            // а) название, соответствующее операции формы - редактированию
            // б) передать данные в форму
            if (editForm == null) editForm = new EditForm();
            editForm.Text = "Изменение (редактирование) данных корабля в коллекции";
            editForm.Data = ships[index];

            if (editForm.ShowDialog() != DialogResult.OK) return;

            // Прочитать данные из формы, записать их новые значения
            // в коллекцию кораблей, в ListView 
            Ship ship = editForm.Data;
            editForm.Clear(); // Очистка полей, отсоединение от файла фотографии

            // !!! Идея работы с файлами фотографий
            // а) получаем имя файла-источника в форме редактирования
            // б) передаем в главную форму полное имя файла
            // в) в главной форме из имени файла, полученного из формы ввода (возможно,
            //    это полное имя, возмозжно - имя в папке Images) делаем
            //    имя из Images + толькоИмяФайле
            // г) проверяем, есть ли такой файл в папке Images
            //    и если его нет - копируем и заменяем имя файла источника
            //    именем файла-копии в папке Images
            // перед записью в коллекцию - копировать файл фото в папку Images проекта, если этого
            // файла еще нет в папке фотографий кораблей
            // скорректировать имя файла - привести к формату Images\ИмяФайла
            string temp = @"..\..\Images\" + Path.GetFileName(ship.FilePhoto); // новое имя - файл приемник
            if (!File.Exists(temp)) {
                File.Copy(ship.FilePhoto, temp);  // копирование из старого места в папку Images проекта
                ship.FilePhoto = temp;            // запомнить новое имя файла
            } // if
            ships[index] = ship;

            // Заменить поля элемента в ListView
            // a) получить элемент index из ListView
            ListViewItem item = lvShips.Items[index];

            // б) записать новые значения столбцов
            item.SubItems[0].Text = ship.Id.ToString();
            item.SubItems[1].Text = ship.Name;
            item.SubItems[2].Text = ship.Displacement.ToString();
            item.SubItems[3].Text = ship.Speed.ToString(CultureInfo.CurrentCulture);
            item.SubItems[4].Text = ship.CruisingRange.ToString();

            // в) собственно замена в ListView по индексу index
            lvShips.Items[index] = item;
        } // mniEdit_Click


        // Выполнить редактирование корабля по двойному щелчку мышью
        private void lvShips_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            mniEdit_Click(mniEdit, EventArgs.Empty);
        } // lvShips_MouseDoubleClick


        // Отображение фотографии корабля при изменении выбранного элемента в списке
        private void lvShips_SelectedIndexChanged(object sender, EventArgs e)
        {
            // Защита от ситуации, когда выбор еще не выполнен, т.е.
            // нет выбранной строки в ListView 
            if (lvShips.SelectedIndices.Count == 0) return;

            int index = lvShips.SelectedIndices[0];
            string fileName = ships[index].FilePhoto;
            pbxShip.Load(File.Exists(fileName) ? fileName : FileNoImage);
        }
    } // class MainForm
}
