using System;
using System.Collections.Generic;
using System.Xml.Serialization;

namespace Moreniell.TrafficViolationManager.Model
{
    public class Violator
    {
		private static int _counter;
		public Violator() { Id = ++_counter; }
		~Violator() { _counter--; }

		// Проверяет историю нарушений на валидность.
	    private bool IsValidHistory
	    {
		    get { return HistoryOfViolations != null && HistoryOfViolations.Count != 0; }
	    }

	    public int Id { get; set; }       // идентификатор нарушителя
	    public string FamIO { get; set; } // фамилия и инициалы нарушителя
		
	    [XmlIgnore]
		public string CarModel // марка автомобиля на которой было совершено последнее нарушение
		{
			get { return !IsValidHistory ? "" : HistoryOfViolations[NewestViolationIndex].CarModel; }
			set
			{
				if (IsValidHistory)
				{
					HistoryOfViolations[NewestViolationIndex].CarModel = value;
				}
				else
				{
					Violation v = new Violation
					{
						CarModel = value
					};

					// Создаем коллекцию и добавляем первый элемент пользуясь инициализатором коллекций.
					HistoryOfViolations = new List<Violation> {v};
				}
			}
		}

		[XmlIgnore]
		public string LastViolation // тип последнего нарушения
		{
		    get
		    {
			    return !IsValidHistory ? "" : HistoryOfViolations[NewestViolationIndex].ViolationType;
		    }
		    set
		    {
			    if (IsValidHistory)
			    {
				    HistoryOfViolations[NewestViolationIndex].ViolationType = value;
			    }
			    else
			    {
				    Violation v = new Violation
				    {
					    ViolationType = value
					};

					// Создаем коллекцию и добавляем первый элемент пользуясь инициализатором коллекций.
				    HistoryOfViolations = new List<Violation> {v};
			    }
		    }
		}

		[XmlIgnore]
		public DateTime Date // дата, когда было совершено последнее нарушение
		{
		    get { return !IsValidHistory ? new DateTime() : HistoryOfViolations[NewestViolationIndex].Date; }
		    set
		    {
				if (IsValidHistory)
				{
					HistoryOfViolations[NewestViolationIndex].Date = value;
				}
				else
				{
					Violation v = new Violation
					{
						Date = value
					};

					// Создаем коллекцию и добавляем первый элемент пользуясь инициализатором коллекций.
					HistoryOfViolations = new List<Violation> {v};
				}
			}
	    }

		[XmlIgnore]
		public double PenaltySum // сумма штрафа последнего нарушения
		{
			get { return !IsValidHistory ? 0 : HistoryOfViolations[NewestViolationIndex].PenaltySum; }
			set
			{
				if (IsValidHistory)
				{
					HistoryOfViolations[NewestViolationIndex].PenaltySum = value;
				}
				else
				{
					Violation v = new Violation
					{
						PenaltySum = value
					};

					// Создаем коллекцию и добавляем первый элемент пользуясь инициализатором коллекций.
					HistoryOfViolations = new List<Violation> {v};
				}
			}
		}

		[XmlIgnore]
		public bool Paid // оплачено ли последнее нарушение
		{
			get { return IsValidHistory && HistoryOfViolations[NewestViolationIndex].Paid; }
			set
			{
				if (IsValidHistory)
				{
					HistoryOfViolations[NewestViolationIndex].Paid = value;
				}
				else
				{
					Violation v = new Violation
					{
						Paid = value
					};

					// Создаем коллекцию и добавляем первый элемент пользуясь инициализатором коллекций.
					HistoryOfViolations = new List<Violation> {v};
				}
			}
		}
		
		[XmlIgnore]
		public double TotalSumOfPaidPenalties // вся сумма оплаченых нарушений
		{
            get
			{
                if (!IsValidHistory) return 0D;
				
                double summa = 0D;
	            foreach (var violation in HistoryOfViolations)
	            {
		            if (violation.Paid)
		            {
			            summa += violation.PenaltySum;
		            }
	            }
				
                return summa;
            }
        }

		private int NewestViolationIndex // индекс последнего нарушения в истории нарушений
		{
			get
			{
				int index = 0;
				for (int i = 0; i < HistoryOfViolations.Count; ++i)
				{
					// Ищем самую свежую дату нарушения в истории нарушителя.
					if (HistoryOfViolations[i].Date > HistoryOfViolations[index].Date)
					{
						index = i;
					}
				}
				return index;
			}
		}
		
		public List<Violation> HistoryOfViolations { get; set; } // история нарушений
	}
}
