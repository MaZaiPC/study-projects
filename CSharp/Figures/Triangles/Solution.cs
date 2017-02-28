using System;
using Moreniell.Triangles.Entities;
using Moreniell.Triangles.Interfaces;

namespace Moreniell.Triangles
{
    static class Solution
    {
        public static void RunTest()
        {
            Test(new Equilateral(42D), "Тестирование равностороннего треугольника");
            Test(new Isosceles(38D, 33.7), "Тестирование равнобедренного треугольника");
            Test(new Rectangular(36D, 22D), "Тестирование прямоугольного треугольника");
            Test(new Versatile(50D, 42D, 35D), "Тестирование разностороннего треугольника");
        }

        private static void Test(ITriangle triangle, string prompt)
        {
            if (triangle == null) return;

            Utils.PrintEncolored("[" + prompt + "]\n", ConsoleColor.Cyan);
            Console.WriteLine("Метод ToString: " + triangle);
            
            Console.WriteLine($"\nПериметр: {triangle.Perimeter():f2}");
            Console.WriteLine($"Площадь: {triangle.Area():f2}\n");
        }
    }
}
