using System;
using System.Globalization;
using System.Windows.Forms;
using System.IO;
using ListViewShip.Model;

namespace ListViewShip.Forms
{
    public partial class EditForm : Form
    {
        private string fileName;  // имя файла с фотографией

        // Свойство Data - для связи формы с внешним миром
        // При присваивании эьому свойству поля данных записываются
        // (с преобразованием) в соответствующие поля ввода

        // При чтении этого свойства из полей данных (с преобразованием)
        // извлекаются данные и направляются в объект класса Ship 
		
        public Ship Data {
            // Геттер работаем при приеме данных из внешних форм
            get {
                Ship ship = new Ship() {
                    Name = txbName.Text, Displacement = int.Parse(txbDisplacement.Text),
                    Speed = double.Parse(txbMaxSpeed.Text),
                    CruisingRange = int.Parse(txbCruisingRange.Text),
                    FilePhoto = fileName
                };
                return ship; 
            } // get

            // Сеттер работает при передаче данных во внешние формы
            set {
                txbName.Text = value.Name;
                txbDisplacement.Text  = value.Displacement.ToString();
                txbMaxSpeed.Text      = value.Speed.ToString(CultureInfo.CurrentCulture);
                txbCruisingRange.Text = value.CruisingRange.ToString();

                // Если фото корабля есть в папке, то загрузить его
                // Иначе - загрузить картинку-заполнитель (это статическое свойство главной формы)
                fileName = value.FilePhoto;  // Важно! Надо запомнить имя файла!
                pbxPhoto.Load(File.Exists(value.FilePhoto)?value.FilePhoto: MainForm.FileNoImage);
            } // set
        } // Ship


        // Очистка полей ввода
        public void Clear()
        {
            txbName.Text = txbDisplacement.Text = txbMaxSpeed.Text = txbCruisingRange.Text = "";
            pbxPhoto.Load(MainForm.FileNoImage);  // это статическое свойство главной формы
        } // Clear


        // Конструктор формы
        public EditForm() {  InitializeComponent(); } // EditForm


        // Выбор фотографии корабля, установка в pbxPhoto, запоминание имени файла
        // с картинкой для дальнейшего копирования в папку фоток коллекции
        private void btnPhotoChoice_Click(object sender, EventArgs e)
        {
            if (ofdPhoto.ShowDialog() != DialogResult.OK) return;
			
            fileName = ofdPhoto.FileName;   // Запомнить имя файла
			pbxPhoto.Load(File.Exists(fileName) ? fileName : MainForm.FileNoImage);
		} // btnPhotoChoice_Click
    } // class EditForm
}
