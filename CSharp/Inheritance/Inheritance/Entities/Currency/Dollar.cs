using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Moreniell.Inheritance.Entities.Currency
{
	public class Dollar : Currency
	{
		public Dollar() { }
		public Dollar(decimal value) : base(value) { }

		/// <summary> Конвертирует доллары в рубли. </summary>
		public override decimal ToRUR()
		{
			return Value * 64.83M;
		}

		/// <summary> Конвертирует доллары в евро. </summary>
		public decimal ToEUR()
		{
			return Value * 0.8894M;
		}

		/// <summary> Выводит сумму на экран. </summary>
		public override void Show()
		{
			Console.WriteLine("Dollars here: " + this);
		}

		/// <summary> Строковое представление класса. </summary>
		public override string ToString()
		{
			return $"${Value:N}";
		}

		public bool Equals(Currency obj)
		{
			if (obj is Dollar)
				return Value == obj.Value;
			if (obj is Euro)
				return this.ToEUR() == obj.Value;
			// (obj is Rubles) в ТЗ отсутствует класс рублей
			return false;
		}
	}
}
