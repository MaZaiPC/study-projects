using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataGridView_DataBinding
{
    public class Student
    {
        // Идентификационный номер студента
        private int id;
        public int Id {
            get { return id; }
            set { id = value; }
        } // Id

        // Фамилия и инициалы
        private string surname;
        public string Surname {
            get { return surname; }
            set { surname = value; }
        } // Surname

        // Пол
        private string gender;
        public string Gender {
            get { return gender; }
            set { gender = value; }
        } // Gender

        // Дата рождения
        private DateTime birthDate;
        public DateTime BirthDate {
            get { return birthDate; }
            set { birthDate = value; }
        } // BirthDate

        // Курс обучения
        private int course;
        public int Course {
            get { return course; }
            set { course = value; }
        } // Course

        // Название группы 
        private string group;
        public string Group {
            get { return group; }
            set { group = value; }
        } // Group

        // Получает ли стипендию (true)
        private bool scholarship;
        public bool Scholarship {
            get { return scholarship; }
            set { scholarship = value; }
        } // Scholarship

    } // class Student
}
