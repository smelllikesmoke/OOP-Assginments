#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>

class Calender {
private: 
    int month;
    bool is_leap;
    int year;

public:
    // Constructors
    Calender(); 
    Calender(int months, int year);

    void DisplayMonth(); // for task 1
};

class Date {
private: 
    int month;
    int day;
    int year;
    int weeks;

public:
    // Constructors
    Date();
    Date(int month, int day, int year);
    
    // Methods
    void Display();
    void init();
    void Difference();
    void Future(Date& d);
    void Past(Date& d, Date& d2);

    // Overloading functions
    Date operator-(const Date& d); // for task 2
    Date operator+(const Date& d); // for task 3


};