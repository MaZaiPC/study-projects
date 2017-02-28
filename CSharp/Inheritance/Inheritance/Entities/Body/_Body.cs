namespace Moreniell.Inheritance.Entities.Body
{
	public abstract class Body
	{
		// NOTE: Можно было бы добавить что-то не абстрактное в этот класс (поля например),
		//       но здесь в этом нет практической надобности (да здравствуют интерфейсы!)

		/// <summary>
		///		Вычисляет площадь тела.
		/// </summary>
		public abstract double CalcArea();

		/// <summary>
		///		Вычисляет объем тела.
		/// </summary>
		public abstract double CalcVolume();
	}
}
