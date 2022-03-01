/*
Auther : Abdullah Al Masum
Inspired By "Summer Wars" animation
*/
#include <bits/stdc++.h>
using namespace std;

void CalculateDay(int year,int month,int date)
{
    int century,zero_based_century,p,day,h;
    century = year % 100;
    zero_based_century = year / 100;
    p = (date + (13*(month+1)/5) + century + (century/4) + (zero_based_century/4) - 2*zero_based_century );
    h=p%7;
    day = ((h+5)%7)+1;
    cout<<"//////////////////////////////"<<endl;
    cout<<"day : ";
    switch(day)
    {
    case 0:
        cout<<"Sunday"<<endl;
        break;
    case 1:
        cout<<"Monday"<<endl;
        break;
    case 2:
        cout<<"Tuesday"<<endl;
        break;
    case 3:
        cout<<"Wednesday"<<endl;
        break;
    case 4:
        cout<<"Thursday"<<endl;
        break;
    case 5:
        cout<<"Friday"<<endl;
        break;
    case 6:
        cout<<"Saturday"<<endl;
        break;
    case 7:
        cout<<"Sunday"<<endl;
        break;
    }
    cout<<"//////////////////////////////"<<endl;
    cout<<endl;
}

void InputDate()
{
    int  year,date,month;
Year:
    cout<<"Enter the year"<<endl;
    cin>>year;
    if(year > 0)
    {
Month:
        cout<<"Enter the month"<<endl;
        cin>>month;
Date:
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout<<"Enter the date"<<endl;
            cin>>date;
            if(date > 0 && date <= 31)
            {
                CalculateDay(year,month,date);
            }
            else
            {
                cout<<"Date can't be negative or zero or more than 31"<<endl;
                goto Date;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout<<"Enter the date"<<endl;
            cin>>date;
            if(date > 0 && date <= 30)
            {
                CalculateDay(year,month,date);
            }
            else
            {
                cout<<"Date can't be negative or zero or more than 30"<<endl;
                goto Date;
            }
            break;
        case 2:
            cout<<"Enter the date"<<endl;
            cin>>date;
            if(date > 0 && date <= 29)
            {
                CalculateDay(year,month,date);
            }
            else
            {
                cout<<"Date can't be negative or zero or more than 29"<<endl;
                goto Date;
            }
            break;
        default:
            cout<<"month can't be negative or zero or bigger than 12."<<endl;
            goto Month;
        }
    }
    else
    {
        cout<<"Year can't be negative or zero"<<endl;
        goto Year;
    }
}

void Menu()
{
    cout<<"**********WELCOME**********"<<endl;
    cout<<"I am Masum Bhai Speaking..."<<endl;
    cout<<"Press: 1. To Calculate the Day."<<endl;
    cout<<"Press: 2. To EXIT the program."<<endl;
    cout<<"Enter Your Choice :";
    return ;
}
int main()
{
    cout<<"Remember all the inputs are integer"<<endl;
    int choice;
    while(1)
    {
        Menu();
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
        case 1:
            InputDate();
            break;
        case 2:
            cout<<"Programme is Terminating..."<<endl;
            cout<<"You can search the date in GOOGLE,will definitely match"<<endl;
            cout<<"Oh...Yeah,Wasn't that Cool?"<<endl;
            exit(EXIT_SUCCESS);
        default:
            cout<<"You have to choose either 1 or 2."<<endl;
        }
    }
    return 0;
}