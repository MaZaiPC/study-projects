using System;

namespace Moreniell.Inheritance.Entities.Body
{
	public class Parallelepiped : Body
	{
		private Size3 size;

		#region Properties

		/// <summary> Длины сторон параллелепипеда. </summary>
		public Size3 Size
		{
			get { return size; }
			private set
			{
				if (value == null)
				{
					Utils.PrintEncolored("Ошибка, для \"Size\" нельзя присвоить значение null!\n", ConsoleColor.Red);
					return;
				}
				size = value;
			}
		}

		#endregion

		#region Constructors
		
		public Parallelepiped() : this(new Size3(1D, 1D, 2D)) { }
		public Parallelepiped(double cx, double cy, double cz) : this(new Size3(cx, cy, cz)) { }
		public Parallelepiped(Size3 size)
		{
			Size = size;
		}

		#endregion

		#region Methods

		/// <summary> Вычисляет площадь поверхности параллелепипеда. </summary>
		public override double CalcArea()
		{
			return 2*(size.Cx + size.Cy + size.Cz);
		}

		/// <summary> Вычисляет объем параллелепипеда. </summary>
		public override double CalcVolume()
		{
			return size.Cx*size.Cy*size.Cz;
		}

		/// <summary> Строковое представление класса. </summary>
		public override string ToString()
		{
			return $"size: {size}; area: {CalcArea():f2}; volume: {CalcVolume():f2}";
		}
		
		public bool Equals(Parallelepiped obj)
		{
			return size.Equals(obj.size);
		}

		#endregion
	}
}