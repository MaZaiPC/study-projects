using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Moreniell.Inheritance.Entities.Body
{
	public class Ball : Body
	{
		private double r;

		#region Properties

		/// <summary> Длины сторон параллелепипеда. </summary>
		public double Radius
		{
			get { return r; }
			private set
			{
				if (value == 0)
				{
					Utils.PrintEncolored("Ошибка, радиус не может быть нулевым!\n", ConsoleColor.Red);
					return;
				}
				r = value;
			}
		}

		#endregion

		#region Constructors

		public Ball() : this(1D) { }
		public Ball(double r)
		{
			Radius = r;
		}

		#endregion

		#region Methods

		/// <summary> Вычисляет площадь поверхности шара. </summary>
		public override double CalcArea()
		{
			return 4*Math.PI*r*r;
		}

		/// <summary> Вычисляет объем шара. </summary>
		public override double CalcVolume()
		{
			return 4 / 3 * Math.PI * Math.Pow(r, 3);
		}

		/// <summary> Строковое представление класса. </summary>
		public override string ToString()
		{
			return $"radius: {r:f2}; area: {CalcArea():f2}; volume: {CalcVolume():f2}";
		}

		public bool Equals(Ball obj)
		{
			return r.Equals(obj.r);
		}

		#endregion
	}
}
