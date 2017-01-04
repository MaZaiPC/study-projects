#include "stdafx.h"
#include "Account.h"
#include "Utils.h"

Account::Account(const Account &time) {}
 
Account::~Account() {}

// ����������� ������������ ������ ��������.
void Account::Input() 
{ 
	tMark("�����������",1);
    cout << "\n������� ���: "; cin >> name;
    cout << "������� ����� ����������� �����: "; cin >> number;
    cout << "������� �����: "; cin >> summa; 
    cout << "������� ��������: "; cin >> percent; 
} 

// ����� ������������ ������ ��������.
void Account::Show() 
{
	tMark("������������ ������",1);
    cout << "\n�������: " << name  << endl; 
    cout << "����� ����������� �����: " << number << endl; 
    cout << "����� �����: " << summa << endl; 
    cout << "���� �������� �����: " << percent << endl; 
}  

// ������� ����� ��������� ����������� �����.
void Account::Chown() 
{ 
	tMark("����� ��������� �����",1);
    cout << "\n������� ��� ������ ���������: "; cin >> name; 
} 

// ������� ������ ����� � ����������� �����.
void Account::Pull_of() 
{   
    int s;
    tMark("������ ����� �� �����",1);
    cout << "\n������� ����� ������� �� ������ ����� " << endl; 
    cin >> s; 
 
    if ( s > summa) 
        cout << "�� �� ������ ����� ����� �����, � ��� �� ����� �� ����� ����� " << endl; 
	else if (s < 0)
	{
		summa += s;
		cout << "������� ����� " << summa << endl;
	}
	else
    { 
        summa -= s; 
        cout << "������� ����� " << summa << endl; 
    } 
} 

// ������� ���������� ����� �� ���������� ����.
void Account::Put() 
{   
    int s;
	tMark("���������� ����� �� ����",1);
    cout << "\n������� �����, ������� �� ������ ������ " << endl; 
    cin >> s; 
	
	if (s < 0)
	{
		summa += -s;
		cout << "���������� ������������� ��������, ���� ������ �� +.\n";
		cout << "����� �� ����� ����� ����� " << summa << endl;
	}
	else
	{
		summa += s;
		cout << "����� �� ����� ����� ����� " << summa << endl;
	}
} 
 
void Account::Per()
{
	tMark("����",1);
    cout << "\n��������� ���������� ����� �� ��������� " << endl; 
    cout << "������� �� ������ ������ ����� " << percent << endl;  
    summa = summa + ((summa*percent) / 100); 
    cout << "����� ����� ���������� �������� ����� " << endl; 
    cout << summa  << endl;
} 

// ���������� ������� ����������� �����: �����/����.
void Account::Change() 
{   
    int number;
	tMark("������� �����",1);
    cout << "\n� ����� ������ ������ ��������� " << endl; 
    cout << "1) ������ " << endl; 
    cout << "2) ���� " << endl;   
    cout << "������� ��� ������� " << endl; 
    cin >> number;  
    if(number == 1) 
        cout << "���� ����� � �������� ����� " << summa / 30 << endl;  	// ���� �� ������� �������� ���������� ������ � ������ ����� �� ������, 
    else if(number == 2) 												// �� ����� ��� ��� ���� ������ :)
        cout << "���� ����� � ���� ����� " << summa / 40 << endl; 
    else 
        cout << "�� ��������� ���� "<< endl;
 
} 

// �������������� ����� � �����
char* Numeral(int n, size_t size, char* buf) 
{ 
    char *one[] = {"","���� ","��� ","��� ","������ ","���� ","����� ","���� ","������ ","������ ",
                  "������ ","����������� ","���������� ","���������� ","������������ ","���������� ",
                  "����������� ","���������� ","������������ ","������������ " };
    char *ten[] = {"","", "�������� ", "�������� ", "����� ", "��������� ", "���������� ", "��������� ", 
                  "����������� ", "��������� " };
    char *hundred[] = {"","��� ","������ ", "������ ", "��������� ", "������� ", "�������� ", 
                      "������� ", "��������� ", "��������� " };
    char *thouOne[] =  {"","���� ","��� ","��� ","������ ","���� ","����� ","���� ","������ ","������ ",
                  "������ ","����������� ","���������� ","���������� ","������������ ","���������� ",
                  "����������� ","���������� ","������������ ","������������ " };                     
    char *thousand[] = {"����� ", "������ ", "������ ", "������ ", "������ ", "����� " ,"����� ", "����� ",
                "����� ","����� ","����� ","����� ","����� ","����� ","����� ","����� ","����� ","����� ","����� "
                "����� "};
 
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
 
// ����� ����� �������� 
void Account::Propis() 
{ 
	char* str; 
    char buf [100]; 
    int choice = summa;
        str = Numeral(choice, 256, buf); 
		tMark("���� �����",1);
        cout << endl << str << endl;
}