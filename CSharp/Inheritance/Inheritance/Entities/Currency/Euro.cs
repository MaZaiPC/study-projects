using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Moreniell.Inheritance.Entities.Currency
{
	public class Euro : Currency
	{
		public Euro() { }
		public Euro(decimal value) : base(value) { }

		/// <summary> Конвертирует евро в рубли. </summary>
		public override decimal ToRUR()
		{
			return Value * 72.34M;
		}

		/// <summary> Конвертирует евро в доллары. </summary>
		public decimal ToUSD()
		{
			return Value * 1.12M;
		}

		/// <summary> Выводит сумму на экран. </summary>
		public override void Show()
		{
			Console.WriteLine("Euros here: " + this);
		}

		/// <summary> Строковое представление класса. </summary>
		public override string ToString()
		{
			return $"€{Value:N}";
		}

		public bool Equals(Currency obj)
		{
			if (obj is Euro)
				return Value == obj.Value;
			if (obj is Dollar)
				return this.ToUSD() == obj.Value;
			// (obj is Rubles) в ТЗ отсутствует класс рублей
			return false;
		}
	}
}
