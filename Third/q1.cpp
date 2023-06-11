#include "Calender.cpp"

int main()
{
    int year, day, month;

    time_t tttime = time(0);
    tm *local_time = localtime(&tttime);
    month = 1 + local_time->tm_mon;
    std::cout << "Welcome to the program, here is the display of current month:  " << std::endl;
    Calender dummy(month, 2023);
    dummy.DisplayMonth();

    std::cout << std::endl << std::endl << "Testing for task 1: ";
    std::cout << std::endl << "Please enter the month: ";
    std::cin >> month;
    std::cout << "Now, please enter the year: ";
    std::cin >> year;

    Calender c1(month, year);   
    c1.DisplayMonth();
    std::cout << std::endl << "First task done." << std::endl << std::endl;
    std::cout << "Enter info for first date: " << std::endl;
    Date d1;
    d1.init();
    Date d2;
    std::cout << "Now enter info for second date: " << std::endl;
    d2.init();
    Date d3;
    d3 = d1 - d2;
    d3.Difference();
    std::cout << std::endl << "Second task done." << std::endl << std::endl;

    std::cout << "Enter a date." << std::endl << "Enter the Month: ";
    std::cin >> month;
    std::cout << "Now enter day: ";
    std::cin >> day;
    std::cout << "Now enter the Year: ";
    std::cin >> year;
    Date d4(month, day, year);
    std::cout << std::endl << "To calculate a future date, how many months you'd like to add? ";
    std::cin >> month;
    std::cout << "And how many days? ";
    std::cin >> day;
    Date d5(month, day);
    d4 + d5;
    std::cout << std::endl << "Third task done." << std::endl << std::endl;


    std::cout << "Enter a date." << std::endl << "Enter the Month: ";
    std::cin >> month;
    std::cout << "Now enter day: ";
    std::cin >> day;
    std::cout << "Now enter the Year: ";
    std::cin >> year;
    Date d6(month, day, year);
    std::cout << std::endl << "To calculate a past date, how many months you'd like to subtract? ";
    std::cin >> month;
    std::cout << "And how many days? ";
    std::cin >> day;
    Date d7(month, day);
    Date d8 = d6 - d7;
    d8.Past(d7, d6);
    std::cout << std::endl << "Forth task done." << std::endl << std::endl;


    return 0;
}