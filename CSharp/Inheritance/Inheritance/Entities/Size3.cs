using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MaZaiPC.Inheritance.Entities
{
	public class Size3
	{
		public double Cx { get; }
		public double Cy { get; }
		public double Cz { get; }

		public Size3(double cx, double cy, double cz)
		{
			Cx = cx;
			Cy = cy;
			Cz = cz;
		}

		public override string ToString()
		{
			// NOTE: .## означает, что дробная часть не будет занимать больше двух позиций при выводе (по кол-ву решеток).
			//       Отличие от модификатора f:
			//       $"{25:.##}"        == "25"
			//       $"{25.468455:.##}" == "25.46"

			//       $"{25:f2}          == "25.00"
			//       $"{25.468455:f2}"  == "25.46"

			return $"{Cx:.##} x {Cy:.##} x {Cz:.##}";
		}

		public bool Equals(Size3 obj)
		{
			return Cx.Equals(obj.Cx) && Cy.Equals(obj.Cy) && Cz.Equals(obj.Cz);
		}
	}
}
