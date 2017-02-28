using System;
using static Moreniell.TrigonometricFunctionTable.Common.Utils;

namespace Moreniell.TrigonometricFunctionTable.Entities
{
	public class ColumnInfoGenerator
	{
		// Колонка для исходных данных.
		public static ColumnInfo Description
		{
			get { return new ColumnInfo("Angle\\Func", x => x); }
		}

		// NOTE: Постфикс -Deg сокращенно degree (градусы)
		public static ColumnInfo SinDeg
		{
			get { return new ColumnInfo("Sin(a)", x => Math.Sin(DegreeToRadians(x))); }
		}

		public static ColumnInfo CosDeg
		{
			get { return new ColumnInfo("Cos(a)", x => Math.Cos(DegreeToRadians(x))); }
		}

		// Не используется по заданию, но сделано для того, чтобы показать, что
		// в таблицу можно подставлять любую функцию схожую по сигнатуре с нашим делегатом
		public static ColumnInfo TanDeg
		{
			get { return new ColumnInfo("Tg(a)", x => Math.Tan(DegreeToRadians(x))); }
		}

		public static ColumnInfo CotDeg
		{
			get { return new ColumnInfo("Ctg(a)", x => 1/Math.Tan(DegreeToRadians(x))); }
		}
	}
}