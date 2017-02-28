using Moreniell.Triangles.Interfaces;
using static System.Math;

namespace Moreniell.Triangles.Entities
{
    public class Isosceles : ATriangle, ITriangle
    {
        public double C
        {
            // Расчет по теореме косинусов
            get { return Sqrt(a*a + a*a - 2*a*a*Cos(angle)); }
        }

        public Isosceles() : this(1D, 24D) { }
        public Isosceles(double a, double angle) : base(a, a, angle) { }

        public double Area()
        {
            return 0.5*a*a*Sin(Utils.DegreeToRadians(angle));
        }

        public double Perimeter()
        {
            return a + a + C;
        }
    }
}