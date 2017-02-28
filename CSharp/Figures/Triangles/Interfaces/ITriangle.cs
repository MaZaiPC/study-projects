namespace Moreniell.Triangles.Interfaces
{
    public interface ITriangle
    {
        double C { get; }
        double Area();
        double Perimeter();
    }
}