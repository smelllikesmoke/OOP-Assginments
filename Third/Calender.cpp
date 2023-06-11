#include "Calender.h"

Calender::Calender() : month(0) , year (2000) {}

Calender::Calender(int month, int year) : month(month) , year(year)
{
    if(month > 12)
    {
        std::cout << "You entered the wrong month.";
        throw("bruh");
    }
}

void Calender::DisplayMonth()
{
    int days;
    std::string name;
    if((month == 2) && (( year % 400 == 0) || (( year % 100 != 0 ) && (year % 4 == 0 ))))
    {
        days = 29; 
        name = "Febuary.";

    }
    else if(month==2)
    {
        name = "Febuary.";
        days = 28;
    }
    else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
    {
        switch(month) 
        {
            case 1:
            name = "January.";
            break;
            case 3:
            name = "March.";
            break;
            case 5:
            name = "May.";
            break;
            case 7:
            name = "July.";
            break;
            case 8:
            name = "August.";
            break;
            case 10:
            name = "October.";
            break;
            case 12:
            name = "December.";
            break;


        }
        days = 31;

    }
    else if(month==4 || month==6 || month==9 || month==11)
    {
        switch(month)
        {
            case 4:
            name = "April.";
            break;
            case 6:
            name = "June.";
            break;
            case 9:
            name = "September.";
            break;
            case 11:
            name = "November.";
            break;
        }
        days = 30;
    }


    int i = 1;
    std::cout << "You entered the month of: " << name;
    while (days > 0)
    {
        if (i % 7 == 1)
        {
            std::cout << std::endl;
        }
        std::cout << i << " ";
        days--;
        i++;
    }
}

Date::Date() : month(0) , day(0), weeks(0), year(0) {}

Date::Date(int month, int day, int year = 0) : month(month) , day(day), year(year) {}

void Date::Display()
{
    std::string name;
    switch (this->month)
    {
        case 1:
        name = "January.";
        break;
        case 2:
        name = "Febuary.";
        break;
        case 3:
        name = "March.";
        break;
        case 4:
        name = "April.";
        break;
        case 5:
        name = "May.";
        break;
        case 6:
        name = "June.";
        break;
        case 7:
        name = "July.";
        break;
        case 8:
        name = "August.";
        break;
        case 9:
        name = "September.";
        break;
        case 10:
        name = "October.";
        break;
        case 11:
        name = "November.";
        break;
        case 12:
        name = "December.";
        break;
        default:
        std::cout << "Wrong month bruh";
        break;
    }

    std::cout << this->day << " " << name << " " << this->year;

}

void Date::init()
{
    std::cout << "Enter the month: ";
    std::cin >> month;
    if (month > 12)
    {
        std::cout << "Invalid input.";
        throw("bruh");
    }
    std::cout << "Now enter the day: ";
    std::cin >> day;
    if (day < 1 || day > 31)
    {
        std::cout << "Invalid day.";
        throw("bruh");
    }
    std::cout << "Finally, enter the year: ";
    std::cin >> year;


}

void Date::Difference()
{
    if (year == 0)
    {
        std::cout << "The months are: " << this->month;
        std::cout << std::endl << "The days are: " << this->day;
    }
    else
    {
        int total = this->year * 365  + this->month * 30 + this->day;
        this->month = total / 30;
        this->day = total % 30;
        this->day /= 3;
        
        std::cout << std::endl << "The months are: " << this->month;
        std::cout << std::endl << "The days are: " << this->day;
    }
}

Date Date::operator-(const Date& d)
{
    Date temp;
    temp.year = this->year - d.year;
    temp.year = abs(temp.year);
    temp.month = this->month - d.month;
    if (temp.month < 0)
        temp.year--;
    temp.month = abs(temp.month);
    temp.day = this->day - d.day;
    if (temp.day < 0)
        temp.month--;
    temp.day = abs(temp.day);
    return temp;

}


Date Date::operator+(const Date& d)
{
    Date temp = *(this);
    int total = this->year * 365 + this->month * 30 + this->day;
    int second = d.month * 30 + d.day;
    temp.day = this->day + d.day;
    if (temp.day > 31)
    {
        temp.day -= 31;
        temp.month ++;
    }
    temp.month = this->month + d.month;
    if (temp.month > 12)
    {
        temp.year ++;
        temp.month -= 12;
    }
    temp.Future(*this);
    return *(this);

}

void Date::Future(Date& d)
{
    std::cout << d.month << " Months and " << d.day << " days from ";
    d.Display();    
    std::cout << " is ";
    this->Display();
}

void Date::Past(Date& d, Date& d2)
{
    std::cout << d.month << " Months and " << d.day << " days before ";
    d2.Display();    
    std::cout << " is ";
    this->Display();
}













