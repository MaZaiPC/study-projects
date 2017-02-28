using Moreniell.Triangles.Interfaces;
using static System.Math;

namespace Moreniell.Triangles.Entities
{
    public class Equilateral : ATriangle, ITriangle
    {
        public double C { get { return a; } }

        public Equilateral() : this(1D) { }
        public Equilateral(double a) : base(a, a, 60D) { }

        public double Area()
        {
            return Sqrt(3)/4*a*a;
        }

        public double Perimeter()
        {
            return a*3;
        }
    }
}