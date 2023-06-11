#include "Fraction.h"

Fraction::Fraction():num(0),denum(1) {}

Fraction::Fraction(int num):num(num){ denum = 1;}

Fraction::Fraction(int num, int denum) : num(num),denum(denum) 
{
    int result;
    if (this->num < this->denum)
    {
        result = num;
    }
    else 
        result = denum;

    while (result > 0)
    {
        if (this->num % result == 0 && this->denum % result == 0)
        {
            break;
        }
        else 
            result--;
    }

    this->num = this->num / result;
    this->denum = this->denum / result;
}

void Fraction::setNum(int num) {this->num = num;}
int  Fraction::getNum() {return this->num;}
void Fraction::setDenum(int num) {this->denum = num;}
int  Fraction::getDenum() {return this->denum;}
      
void Fraction::display() { cout << num << '/' << denum; }

Fraction Fraction::operator+(const Fraction& frac)  const
{
    int num, denum;
    if (frac.denum == this->denum)
    {
        num = this->num + frac.num;
        denum = this->denum;
        return Fraction(num, denum);
    }
    denum = this->denum * frac.denum;
    num = (denum / this->denum) * this->num;
    num += (denum / frac.denum) * frac.num;
    return Fraction(num, denum);
}
Fraction Fraction::operator-(const Fraction& frac) const
{

    int num, denum;
    if (frac.denum == this->denum)
    {
        num = this->num - frac.num;
        denum = this->denum;
        return Fraction(num, denum);
    }
    denum = this->denum * frac.denum;
    num = (denum / this->denum) * this->num;
    num -= (denum / frac.denum) * frac.num;
    return Fraction(num, denum);


    // int num, denum;
    // num = this->num * frac.denum - this->denum * frac.num;
    // denum = this->denum * frac.denum;
    // return Fraction(num ,denum);
}
Fraction Fraction::operator*(const Fraction& frac) const
{
    int num , denum;
    num = this->num * frac.num;
    denum = this->denum * frac.denum;
    return Fraction(num,denum);
}
Fraction Fraction::operator/(const Fraction& frac) const
{
    int num , denum;
    num = this->num * frac.denum;
    denum = this->denum * frac.num;
    return Fraction(num,denum);
}

Fraction& Fraction::operator+=(const Fraction& frac)
{
    (*this) = (*this) + frac;
    return (*this);
}
Fraction& Fraction::operator-=(const Fraction& frac)
{
    (*this) = (*this) - frac;
    return (*this);
}

Fraction& Fraction::operator*=(const Fraction& frac)
{
    (*this) = (*this) * frac;
    return (*this);
}
Fraction& Fraction::operator/=(const Fraction& frac)
{
    (*this) = (*this) / frac;
    return (*this);
}

// comparison operators
bool Fraction::operator==(const Fraction& frac) const
{
    if((this->num == frac.num) && (this->denum == frac.denum))
    {
        return true;
    }
    else    
        return false;


}
bool Fraction::operator!=(const Fraction& frac) const
{
    if (*this == frac)
        return false;

    return true;
}
bool Fraction::operator<(const Fraction& frac)  const
{
    double first = this->num / this->denum;
    double sec = frac.num / frac.denum;
    if (first < sec)
        return true;
    return false;
}
bool Fraction::operator>(const Fraction& frac)  const
{   
    return (!((*this) < frac));
}
bool Fraction::operator<=(const Fraction& frac) const
{
    if ((*this) == frac)
        return true;

    return ((*this) < frac);
}
bool Fraction::operator>=(const Fraction& frac) const
{
    if ((*this) == frac)
        return true;

    return ((*this) > frac);
}

// increment and decrement operators
Fraction& Fraction::operator++() // pre-increment
{       
    (*this) += Fraction(1, 1);
    return (*this);
}
Fraction Fraction::operator++(int) // post-increment
{
    Fraction temp = (*this);
    ++(*this);
    return temp;
}

Fraction& Fraction::operator--() // pre-decrement
{
    (*this) -= Fraction(1, 1);
    return (*this);
}
Fraction  Fraction::operator--(int) // post-decrement
{
    Fraction temp = (*this);
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac)
{
    out << frac.num << '/' << frac.denum;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& frac)
{
    cout << endl <<  "Enter the num: ";
    in >> frac.num;
    cout << "Enter the denum: ";
    in >> frac.denum;
    return in;
}

bool Fraction::operator||(const Fraction& frac) const
{
    return (this->num != 0) || (frac.num != 0);
}

bool Fraction::operator&&(const Fraction& frac) const
{
    return (this->num != 0) && (frac.num != 0);
}

















