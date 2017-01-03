using System;
using MaZaiPC.Triangles.Interfaces;

namespace MaZaiPC.Triangles.Entities
{
    public class Rectangular : ATriangle, ITriangle
    {
        public double C
        {
            get
            {
                return Math.Sqrt(a*a + b*b);
            }
        }

        public Rectangular() : this(1D, 1D) { }
        public Rectangular(double a, double b) : base(a, b, 90D) { }

        public double Area()
        {
            return 0.5*a*b;
        }

        public double Perimeter()
        {
            return a + b + C;
        }
    }
}