using System;

namespace Moreniell.Inheritance.Entities.Currency
{
	public abstract class Currency
	{
		/// <summary> Сумма. </summary>
		public decimal Value { get; set; }
		
		#region Constructors

		// Вызов конструктора абстрактных классов вне наследников не возможен => модификатор доступа protected.
		protected Currency() : this(0M) { }
		protected Currency(decimal value)
		{
			Value = value;
		}

		#endregion

		/// <summary>
		///		Конвертирует валюту в рубли.
		/// </summary>
		/// <returns> Сумма в рублях. </returns>
		public abstract decimal ToRUR();

		/// <summary>
		///		Выводит сумму на экран.
		/// </summary>
		public abstract void Show();
	}
}
