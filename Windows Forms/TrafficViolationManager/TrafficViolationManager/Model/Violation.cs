using System;

namespace MaZaiPC.TrafficViolationManager.Model
{
    public class Violation
    {
	    public int Id { get; set; } = 1;          // идентификатор нарушения
		public string CarModel { get; set; }      // марка машины нарушителя
		public string ViolationType { get; set; } // тип нарушения
		public DateTime Date { get; set; } = new DateTime(); // дата нарушения
	    public double PenaltySum { get; set; }    // сумма штрафа
		public bool Paid { get; set; }            // оплачен ли штраф
	}
}
