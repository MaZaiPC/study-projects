using System.IO;
using System.Text;

namespace Moreniell.StoreApplication.Entities
{
	class Price
	{
		public string StoreName  { get; set; }
		public string ProductName   { get; set; }
		public uint Cost { get; set; }
		
		/// <summary> Возвращает длину одной записи маршрута. </summary>
		public static int LenRecord { get { return sizeof (byte)*80 + sizeof (uint); } }

		public Price() { }
		public Price(string storeName, string productName, uint cost)
		{
			StoreName = storeName;
			ProductName = productName;
			Cost = cost;
		}

		/// <summary> Записывает объект в файл пользуясь указанным BinaryWriter-ом. </summary>
		public void Write(BinaryWriter bw)
		{
			// Устанавливаем фиксированное кол-во байт (конвертированных символов char).
			byte[] bytes = new byte[40]; 

			// Пишем закодированный в байтах пункт отправления.
			Encoding.Default.GetBytes(StoreName).CopyTo(bytes, 0);
			bw.Write(bytes);

			// Пишем закодированный в байтах пункт назначения.
			bytes = new byte[40];
			Encoding.Default.GetBytes(ProductName).CopyTo(bytes, 0);
			bw.Write(bytes);

			// Пишем номер маршрута.
			bw.Write(Cost);
		}

		/// <summary> Читает объект из файла пользуясь указанным BinaryReader-ом. </summary>
		public Price Load(BinaryReader br)
		{
			// Читаем и декодируем массив байтов в строку пункта отправления.
			StoreName = Encoding.Default.GetString(br.ReadBytes(40));

			// Читаем и декодируем массив байтов в строку пункта назначения.
			ProductName = Encoding.Default.GetString(br.ReadBytes(40));

			// Читаем номер маршрута.
			Cost = br.ReadUInt32();

			// Возвращает этот объект.
			return this;
		}
		
		public override string ToString()
		{
			return $"║ {ProductName,-40} ║ {Cost, 10} ║";
		}
	}
}