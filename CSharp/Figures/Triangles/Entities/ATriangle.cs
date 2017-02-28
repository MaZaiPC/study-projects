namespace Moreniell.Triangles.Entities
{
    public abstract class ATriangle
    {
        /// <summary> Стороны треугольника. </summary>
        protected double a, b;

        /// <summary> Угол в градусах. </summary>
        protected double angle;

        #region Properties

        public double A
        {
            get
            {
                return a;
            }
            set
            {
                a = value <= 0D ? 1D : value;
                
            }
        }

        public double B
        {
            get
            {
                return b;
            }
            set
            {
                b = value <= 0D ? 1D : value;
            }
        }

        public double Angle
        {
            get
            {
                return angle;
            }
            set
            {
                angle = value <= 0D ? 60D : value;
            }
        }

        #endregion

        protected ATriangle(double a, double b, double angle)
        {
            A = a;
            B = b;
            Angle = angle;
        }

        public override string ToString()
        {
            return $"A[{a}], B[{b}], Alpha[{angle}]";
        }
    }
}