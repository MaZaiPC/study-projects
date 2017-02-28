using Moreniell.Triangles.Interfaces;
using static System.Math;

namespace Moreniell.Triangles.Entities
{
    public class Versatile : ATriangle, ITriangle
    {
        public double C
        {
            // Расчет по теореме косинусов
            get { return Sqrt(a*a + b*b - 2*a*b*Cos(angle)); }
        }

        public Versatile() : this(1D, 2D, 45D) { }
        public Versatile(double a, double b, double angle) : base(a, b, angle) { }

        public double Area()
        {
            return 0.5*a*b*Sin(Utils.DegreeToRadians(angle));
        }

        public double Perimeter()
        {
            return a + b + C;
        }
    }
}