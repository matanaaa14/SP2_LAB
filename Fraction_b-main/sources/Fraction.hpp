#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

namespace ariel{}
//Fraction class has 2 int fields numerator and denominator
//each time the client trys to do any operation I first it wouldn't cause an overflow 
//if the operation involves an float number I first convert it to Fraction with convert() function
class Fraction {
public:
    int numerator, denominator;
    Fraction(int, int);
    Fraction(float num);
    Fraction();

    Fraction operator+(const Fraction& other)const;
    Fraction operator+(float num)const;
    friend Fraction operator+(float num, const Fraction& fraction);
    //friend Fraction operator+(const Fraction& fraction,float num);
    
    Fraction operator-(const Fraction& other)const;
    Fraction operator-(float num)const;
    friend Fraction operator-(float num, const Fraction& fraction);
    //friend Fraction operator-(const Fraction& fraction,float num);

    Fraction operator*(const Fraction& other)const;
    Fraction operator*(float num)const;
    friend Fraction operator*(float num, const Fraction& fraction);
    //friend Fraction operator*(const Fraction& fraction,float num);

    Fraction operator/(const Fraction& other)const;
    Fraction operator/(float num)const;
    friend Fraction operator/(float num, const Fraction& fraction);
    //friend Fraction operator/(const Fraction& fraction,float num);

    bool operator==(const Fraction& other) const;
    friend bool operator==(float num, const Fraction& fraction);
    friend bool operator==(const Fraction& fraction,float num);

    bool operator<(const Fraction& other)const;
    bool operator<(float num)const;
    friend bool operator<(float num, const Fraction& fraction);

    bool operator<=(const Fraction& other)const;
    friend bool operator<=(float num, const Fraction& fraction);
    bool operator<=(float num)const;

    bool operator>(const Fraction& other)const;
    bool operator>(float num)const;
    friend bool operator>(float num, const Fraction& fraction);

    bool operator>=(const Fraction& other) const;
    friend bool operator>=(float num, const Fraction& fraction);
    bool operator>=(float num)const;

    Fraction operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    friend std::istream& operator>>(std::istream& input, Fraction& fraction);

    friend std::ostream& operator<<(std::ostream& ostreamm, const Fraction& other);

    int GCD(int num1 ,int num2);
    Fraction convert(float num)const;

    int getNumerator();
    int getDenominator();

};



#endif