using System.IO;
using System.Text;

namespace Moreniell.TextFiles.Entities
{
	class Marsh
	{
		public string From  { get; set; }
		public string To   { get; set; }
		public int Number { get; set; }

		/// <summary> Возвращает длину одной записи маршрута. </summary>
		public static int LenRecord { get { return sizeof (byte)*80 + sizeof (int); } }

		public Marsh() { }
		public Marsh(string from, string to, int number)
		{
			From = from;
			To = to;
			Number = number;
		}

		/// <summary> Записывает объект в файл пользуясь указанным BinaryWriter-ом. </summary>
		public void Write(BinaryWriter bw)
		{
			// Устанавливаем фиксированное кол-во байт (конвертированных символов char).
			byte[] bytes = new byte[30]; 

			// Пишем закодированный в байтах пункт отправления.
			Encoding.Default.GetBytes(From).CopyTo(bytes, 0);
			bw.Write(bytes);

			// Пишем закодированный в байтах пункт назначения.
			Encoding.Default.GetBytes(To).CopyTo(bytes, 0);
			bw.Write(bytes);

			// Пишем номер маршрута.
			bw.Write(Number);
		}

		/// <summary> Читает объект из файла пользуясь указанным BinaryReader-ом. </summary>
		public Marsh Load(BinaryReader br)
		{
			// Читаем и декодируем массив байтов в строку пункта отправления.
			From = Encoding.Default.GetString(br.ReadBytes(30));

			// Читаем и декодируем массив байтов в строку пункта назначения.
			To = Encoding.Default.GetString(br.ReadBytes(30));

			// Читаем номер маршрута.
			Number = br.ReadInt32();

			// Возвращает этот объект.
			return this;
		}
		
		public override string ToString()
		{
			return $"{From,-30} {To,-30} {Number, 5}";
		}
	}
}