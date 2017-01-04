#include "stdafx.h"
#include "Account.h"
#include "Utils.h"

Account::Account(const Account &time) {}
 
Account::~Account() {}

// Регистрация персональных данных аккаунта.
void Account::Input() 
{ 
	tMark("Регистрация",1);
    cout << "\nВведите ФИО: "; cin >> name;
    cout << "Введите номер банковского счёта: "; cin >> number;
    cout << "Введите сумму: "; cin >> summa; 
    cout << "Введите проценты: "; cin >> percent; 
} 

// Вывод персональных данных аккаунта.
void Account::Show() 
{
	tMark("Персональные данные",1);
    cout << "\nФамилия: " << name  << endl; 
    cout << "Номер банковского счёта: " << number << endl; 
    cout << "Сумма равна: " << summa << endl; 
    cout << "Ваши проценты равны: " << percent << endl; 
}  

// Функция смены владельца банковского счета.
void Account::Chown() 
{ 
	tMark("Смена владельца счета",1);
    cout << "\nВведите ФИО нового владельца: "; cin >> name; 
} 

// Функция снятия суммы с банковского счета.
void Account::Pull_of() 
{   
    int s;
    tMark("Снятие суммы со счета",1);
    cout << "\nВведите сумму которую вы хотите снять " << endl; 
    cin >> s; 
 
    if ( s > summa) 
        cout << "Вы не можете снять такую сумму, у вас на счету не такой суммы " << endl; 
	else if (s < 0)
	{
		summa += s;
		cout << "Остаток равен " << summa << endl;
	}
	else
    { 
        summa -= s; 
        cout << "Остаток равен " << summa << endl; 
    } 
} 

// Функция начисления суммы на банковский счет.
void Account::Put() 
{   
    int s;
	tMark("Начисление суммы на счет",1);
    cout << "\nВведите сумму, которую вы хотите внести " << endl; 
    cin >> s; 
	
	if (s < 0)
	{
		summa += -s;
		cout << "Обнаружено отрицательное значение, знак сменен на +.\n";
		cout << "Сумма на вашем счету равна " << summa << endl;
	}
	else
	{
		summa += s;
		cout << "Сумма на вашем счету равна " << summa << endl;
	}
} 
 
void Account::Per()
{
	tMark("Инфо",1);
    cout << "\nПроизошло начисление суммы по процентам " << endl; 
    cout << "Процент по вашему вклдау равен " << percent << endl;  
    summa = summa + ((summa*percent) / 100); 
    cout << "Сумма после начисления процента равна " << endl; 
    cout << summa  << endl;
} 

// Реализация функции конвертации валют: долар/евро.
void Account::Change() 
{   
    int number;
	tMark("Перевод валют",1);
    cout << "\nВ какую валюту хотите перевести " << endl; 
    cout << "1) доллар " << endl; 
    cout << "2) евро " << endl;   
    cout << "Введите ваш вариант " << endl; 
    cin >> number;  
    if(number == 1) 
        cout << "Ваша сумма в долларах равна " << summa / 30 << endl;  	// Было бы неплохо получать актуальные данные о курсах валют из облака, 
    else if(number == 2) 												// но думаю это еще рано делать :)
        cout << "Ваша сумма в евро равна " << summa / 40 << endl; 
    else 
        cout << "Не корретный ввод "<< endl;
 
} 

// Преобразование числа в текст
char* Numeral(int n, size_t size, char* buf) 
{ 
    char *one[] = {"","один ","два ","три ","четыре ","пять ","шесть ","семь ","восемь ","девять ",
                  "десять ","одиннадцать ","двенадцать ","тринадцать ","четырнадцать ","пятнадцать ",
                  "шестнадцать ","семнадцать ","восемнадцать ","девятнадцать " };
    char *ten[] = {"","", "двадцать ", "тридцать ", "сорок ", "пятьдесят ", "шестьдесят ", "семьдесят ", 
                  "восемьдесят ", "девяносто " };
    char *hundred[] = {"","сто ","двести ", "триста ", "четыреста ", "пятьсот ", "шестьсот ", 
                      "семьсот ", "восемьсот ", "девятьсот " };
    char *thouOne[] =  {"","одна ","две ","три ","четыре ","пять ","шесть ","семь ","восемь ","девять ",
                  "десять ","одиннадцать ","двенадцать ","тринадцать ","четырнадцать ","пятнадцать ",
                  "шестнадцать ","семнадцать ","восемнадцать ","девятнадцать " };                     
    char *thousand[] = {"тысяч ", "тысяча ", "тысячи ", "тысячи ", "тысячи ", "тысяч " ,"тысяч ", "тысяч ",
                "тысяч ","тысяч ","тысяч ","тысяч ","тысяч ","тысяч ","тысяч ","тысяч ","тысяч ","тысяч ","тысяч "
                "тысяч "};
 
    buf = new char[size];
    sprintf(buf, "%u", n);
    int len = strlen(buf);
    int temp, temp2;
        switch(len)
{
    case 1:
        sprintf(buf,"%s", one[n]);
        break;
    case 2:
        if(n < 20)
        {
            sprintf(buf,"%s", one[n]);
        }
        else if(n < 100)
        {
            if((n%10)==0) sprintf(buf,"%s", ten[n/10]);
            else sprintf(buf,"%s%s", ten[n/10], one[n%10]);
        }
        break;
    case 3:
        temp = n/100;
        n -= (n/100)*100;
        if(n < 20)
        {
            sprintf(buf,"%s%s", hundred[temp], one[n]);
            
        }
        else if(n < 100)
        {
            if((n%10)==0) sprintf(buf,"%s%s", hundred[temp], ten[n/10]);
            else sprintf(buf,"%s%s%s", hundred[temp], ten[n/10], one[n%10]);
        }
        break;
    case 4:
        temp = n/1000;
        n -= (n/1000)*1000;
        sprintf(buf,"%s%s", thouOne[temp], thousand[temp]);
        temp = n/100;
        n -= (n/100)*100;
        if(n < 20)
        {
            strncat(buf, hundred[temp], 30);
            strncat(buf, one[n], 15);
        }
        else if(n < 100)
        {
            if((n%10)==0){
                 strncat(buf, hundred[temp], 30);
                 strncat(buf, ten[n/10], 30); 
             }
            else {
                strncat(buf, hundred[temp], 30);
                strncat(buf, ten[n/10], 30); 
                strncat(buf, one[n%10], 30);
            }
        }
        break;
    case 5:
        temp = n/1000;
        n -= (n/1000)*1000;
        if(temp<20){
            sprintf(buf,"%s%s", thouOne[temp], thousand[temp%10]);
        }
        else if(temp < 100)
        {
            if((temp%10)==0) sprintf(buf,"%s%s", ten[temp/10], thousand[temp%10]);
            else sprintf(buf,"%s%s%s", ten[temp/10], thouOne[temp%10], thousand[temp%10]);
        }
        temp = n/100;
        n -= (n/100)*100;
        if(n < 20)
        {
            strncat(buf, hundred[temp], 30);
            strncat(buf, one[n], 30);
            
        }
        else if(n < 100)
        {
            if((n%10)==0){
                 strncat(buf, hundred[temp], 30);
                 strncat(buf, ten[n/10], 30); 
             }
            else {
                strncat(buf, hundred[temp], 30);
                strncat(buf, ten[n/10], 30); 
                strncat(buf, one[n%10], 30);
            }
        }
        break;
    case 6:
        temp2 = n/1000;
        n -= (n/1000)*1000;
        
        temp = temp2/100;
        temp2 -=temp*100;
        
        if(temp2<20){
            sprintf(buf,"%s%s%s", hundred[temp], thouOne[temp2], thousand[temp2]);
        }
        else if(temp2 < 100)
        {
            if((temp%10)==0) sprintf(buf,"%s%s%s",hundred[temp], ten[temp2/10], thousand[temp2%10]);
            else sprintf(buf,"%s%s%s%s", hundred[temp],ten[temp2/10], thouOne[temp2%10], thousand[temp2%10]);
        }
        temp = n/100;
        n -= (n/100)*100;
        if(n < 20)
        {
            strncat(buf, hundred[temp], 30);
            strncat(buf, one[n], 30);
            
        }
        else if(n < 100)
        {
            if((n%10)==0){
                 strncat(buf, hundred[temp], 30);
                 strncat(buf, ten[n/10], 30); 
             }
            else {
                strncat(buf, hundred[temp], 30);
                strncat(buf, ten[n/10], 30); 
                strncat(buf, one[n%10], 30);
            }
        }
        break;
}

return StrUpperFirst(buf);
}
 
// Вывод суммы прописью 
void Account::Propis() 
{ 
	char* str; 
    char buf [100]; 
    int choice = summa;
        str = Numeral(choice, 256, buf); 
		tMark("Ваша сумма",1);
        cout << endl << str << endl;
}