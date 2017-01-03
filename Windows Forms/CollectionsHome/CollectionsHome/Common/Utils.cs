using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace MaZaiPC.CollectionsHome.Common
{
	public static class Utils
	{
		public static string CollectionToString(IEnumerable<int> stack)
		{
			StringBuilder sb = new StringBuilder();

			sb.Append("{ ");
			foreach (int item in stack)
			{
				sb.Append(item).Append(' ');
			}
			sb.Append('}');

			return sb.ToString();
		} // CollectionToString::END

		public static int Min(IEnumerable<int> source)
		{
			if (source == null) throw new ArgumentNullException(nameof(source));
			int value = 0;
			bool hasValue = false;
			foreach (int x in source)
			{
				if (hasValue)
				{
					if (x < value) value = x;
				}
				else
				{
					value = x;
					hasValue = true;
				}
			}
			if (hasValue) return value;
			throw new InvalidOperationException("Коллекция пуста!");
		} // Min::END

		// Извлекает из очереди элемент с указанным значением.
		public static void Extract(Queue<int> source, int value)
		{
			if (source == null) throw new ArgumentNullException(nameof(source));
			
			for (int i = 0; i < source.Count; ++i)
			{
				int deq = source.Dequeue(); // извлекаем очередной элемент
				
				if (deq != value)
				{
					// Возвращаем элемент на место (если он не является извлекаемым).
					source.Enqueue(deq); 
				}
			}
		} // Extract::END
	}
}