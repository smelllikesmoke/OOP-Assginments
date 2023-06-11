#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

class Fraction {

private:
    int num;
    int denum;    

public:
    Fraction();
    Fraction(int num);
    Fraction(int num,int denum);

    void setNum(int num);
    int  getNum();
    void setDenum(int num);
    int  getDenum();
    void display();


// binary arithmetic operators
    Fraction operator+(const Fraction& frac) const;
    Fraction operator-(const Fraction& frac) const;
    Fraction operator*(const Fraction& frac) const;
    Fraction operator/(const Fraction& frac) const;

// compound assignment operators
    Fraction& operator+=(const Fraction& frac);
    Fraction& operator-=(const Fraction& frac);
    Fraction& operator*=(const Fraction& frac);
    Fraction& operator/=(const Fraction& frac);

// comparison operators
    bool operator==(const Fraction& frac) const;
    bool operator!=(const Fraction& frac) const;
    bool operator<(const Fraction& frac) const;
    bool operator>(const Fraction& frac) const;
    bool operator<=(const Fraction& frac) const;
    bool operator>=(const Fraction& frac) const;


// increment and decrement operators
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

// function call operator
    int operator()(int arg) const;
// subscript operator
    int operator[](int index) const;

// logical operators
    bool operator&&(const Fraction& frac) const;
    bool operator||(const Fraction& frac) const;

// bitwise operators
    Fraction operator&(const Fraction& frac) const;
    Fraction operator|(const Fraction& frac) const;

// pointer operators
    Fraction* operator->();
    const Fraction* operator->() const;
    Fraction& operator*();
    const Fraction& operator*() const;
    Fraction& operator->*(int index);
    const Fraction& operator->*(int index) const;

// stream insertion operators
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
    friend std::istream& operator>>(std::istream& in, Fraction& frac);


};
      