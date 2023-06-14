#include "Fraction.hpp"
#include <iostream>
#include <limits>
#include <limits.h>
#include <cstdlib>

using namespace std;

namespace ariel{}

#define MAX_INT numeric_limits<int>::max()

    // implementation of member functions
    //builtin_add/sub/mul_overflow are builtin functions that check that the operation the client trys to do not case an overflow
    Fraction Fraction::operator+(const Fraction& other)const{
      int num2 = 0; 
      if(__builtin_add_overflow(this->numerator * other.denominator,other.numerator *this->denominator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);
      }

      Fraction f(this->numerator * other.denominator + other.numerator *this->denominator, this->denominator *other.denominator);
      return f;
    }
    
    Fraction Fraction::operator+(float num)const{
      Fraction temp = convert(num);
      int num2;
      if(__builtin_add_overflow(this->numerator * temp.denominator,temp.numerator *this->denominator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);
      }
      Fraction result(this->numerator * temp.denominator +temp.numerator *this->denominator, this->denominator *temp.denominator) ;
      return result;}
              
      Fraction operator+(float num,const Fraction& fraction){
      Fraction temp = fraction.convert(num);
      int num2;
      if(__builtin_add_overflow(fraction.numerator * temp.denominator ,temp.numerator *fraction.denominator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);
      }
      Fraction result(fraction.numerator * temp.denominator +temp.numerator *fraction.denominator, fraction.denominator *temp.denominator);   
      return result;}



    Fraction Fraction::operator-(const Fraction& other)const{
      int num2;
      if(__builtin_sub_overflow(this->numerator * other.denominator ,other.numerator *this->denominator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);
      }
      Fraction f(this->numerator * other.denominator -other.numerator *this->denominator, this->denominator *other.denominator);
      return f;   }

    Fraction Fraction::operator-(float num)const{
      int num2;
      Fraction temp = convert(num);
      if(__builtin_sub_overflow(this->numerator * temp.denominator ,temp.numerator *this->denominator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);
      }
      Fraction result(this->numerator * temp.denominator -temp.numerator *this->denominator, this->denominator *temp.denominator) ;
      return result;   }
    

    Fraction operator-(float num,const Fraction& fraction){
      Fraction temp = fraction.convert(num);
      //Fraction result(fraction.numerator * temp.denominator -temp.numerator *fraction.denominator, fraction.denominator *temp.denominator);   
      Fraction result = temp - fraction;
      return result;   }


    Fraction Fraction::operator*(const Fraction& other)const{
      int num2;
      if(__builtin_mul_overflow(this->numerator,other.numerator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);   
      }
      if(__builtin_mul_overflow(this->denominator,other.denominator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);   
      }
      Fraction f(this->numerator * other.numerator,this->denominator * other.denominator);
      return f; }

    Fraction Fraction::operator*(float num)const{
      Fraction temp = convert(num);
      int num2;
      if(__builtin_mul_overflow(this->numerator,temp.numerator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);   
      }
      if(__builtin_mul_overflow(this->denominator,temp.denominator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);   
      }
      Fraction result(this->numerator * temp.numerator, this->denominator *temp.denominator) ;
      return result;   }
    
   

    Fraction operator*(float num,const Fraction& fraction){
      Fraction temp = fraction.convert(num);
      //Fraction result(fraction.numerator * temp.numerator,fraction.denominator *temp.denominator) ;
      Fraction result = temp * fraction;
      return result;     }

    
    Fraction Fraction::operator/(const Fraction& other)const{
      if(other.numerator == 0){
        perror("division by 0 is illegal\n");
        __throw_runtime_error("ERROR: denominator can't be-0\n");
        exit(1);
      }
      int num2;
      if(__builtin_mul_overflow(this->numerator,other.denominator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);   
      }
      if(__builtin_mul_overflow(this->denominator,other.numerator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);   
      }
      Fraction result(this->numerator * other.denominator,this->denominator * other.numerator);
      return result;  }

    Fraction Fraction::operator/(float num)const{
      if(num == 0){
        perror("division by 0 is illegal\n");
        __throw_runtime_error("ERROR: denominator can't be-0\n");
        exit(1);
      }
      Fraction temp = convert(num);
      int num2;
      if(__builtin_mul_overflow(this->numerator,temp.denominator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);   
      }
      if(__builtin_mul_overflow(this->denominator,temp.numerator,&num2)){
        __throw_overflow_error("numbers to big\n");
        exit(1);   
      }
      Fraction result(this->numerator * temp.denominator , this->denominator *temp.numerator) ;
      return result;   }
    

    Fraction operator/(float num,const Fraction& fraction){
      if(fraction.numerator == 0){
        perror("division by 0 is illegal\n");
        __throw_runtime_error("ERROR: denominator can't be-0\n");
        exit(1);
      }
      Fraction temp = fraction.convert(num);
      //Fraction result(fraction.numerator * temp.denominator ,fraction.denominator *temp.numerator) ;
      Fraction result = temp / fraction;
      return result;     }

    bool Fraction::operator==(const Fraction& other) const{
      float num1 =(float) this->numerator / this->denominator;
      float num2 = (float) other.numerator / other.denominator;
      int num3 = num1 * 1000;
      int num4 = num2 * 1000;
      num1 = (float) num3 / 1000;
      num2 = (float) num4 / 1000;
      //the accuracy is only 3 numbers ofter the (.)
      if(abs(num1 -num2) <= 0.01 && abs(num1 - num2) >= -.01)
        return true;
      return false;
    }
    bool operator==(float num, const Fraction& fraction){
      Fraction temp = fraction.convert(num);
      return fraction == temp;
    }
    bool operator==(const Fraction& fraction,float num){
      return num == fraction;
    }

    bool Fraction::operator<(const Fraction& other)const{
      Fraction stam1 = other;
      Fraction temp = stam1 - *this;
      if((temp.numerator > 0 & temp.denominator > 0)||(temp.numerator < 0 & temp.denominator < 0) )
          return true;
      return false;
    }
    bool operator<(float num, const Fraction& fraction){
      Fraction temp = fraction.convert(num);
      return temp < fraction; 
    }
    
    bool Fraction::operator<(float num)const{
      Fraction fraction2 =*this;
      Fraction temp = convert(num);
      return fraction2 < temp; 
    }
    
    bool Fraction::operator<=(const Fraction& other)const{
      Fraction temp = *this;
      if(temp < other || temp == other)
        return true;
      return false;
    }
    bool operator<=(float num ,const Fraction& fraction){
      Fraction temp1 = fraction;
      Fraction temp2 = temp1.convert(num);
      if(temp2 < temp1 || temp1 == temp2)
        return true;
      return false;
    }
    
    bool Fraction::operator<=(float num)const{
      Fraction temp = convert(num);
      Fraction temp2 = *this;
      return temp2 <= temp;
    }
    
    bool Fraction::operator>(const Fraction& other)const{
      if (*this == other){
        return false;
      }
      return !(*this < other);
    }
    
    bool Fraction::operator>(float num)const{
      Fraction temp = convert(num);
      return *this > temp;
    }
    bool operator>(float num, const Fraction& fraction){
      Fraction temp = fraction;
      return temp < num;
    }
    
    
    bool Fraction::operator>=(const Fraction& other)const{
      return (*this > other || *this == other);
    }
    bool operator>=(float num, const Fraction& fraction){
      return !(num < fraction);
    }
    
    bool Fraction::operator>=(float num)const{
      return (!(*this < num));
    }
    
    Fraction Fraction::operator++(){
      Fraction temp(this->numerator + this->denominator, this->denominator);
      this->numerator = temp.numerator;
      this->denominator = temp.denominator;
      return *this;
    }
    
    Fraction Fraction::operator++(int){
      Fraction temp2(this->numerator,this->denominator);
      Fraction temp(this->numerator + this->denominator, this->denominator);
      this->numerator = temp.numerator;
      this->denominator = temp.denominator;
      return temp2;
    }
    
    Fraction& Fraction::operator--(){
      Fraction temp(this->numerator - this->denominator, this->denominator);
      this->numerator = temp.numerator;
      this->denominator = temp.denominator;
      return *this;
    }
    
    Fraction Fraction::operator--(int){
      Fraction temp2(this->numerator,this->denominator);
      Fraction temp(this->numerator - this->denominator, this->denominator);
      this->numerator = temp.numerator;
      this->denominator = temp.denominator;
      return temp2;
    }
    
    ostream& operator<<(ostream& output,const Fraction& other){
        return output << other.numerator << "/" << other.denominator;
      }
    
    // implementation of friend functions

  

    istream& operator>>(istream& input, Fraction& fraction){
      char slash = '/';
      input >> fraction.numerator >> fraction.denominator; 
      if(input.fail() || fraction.denominator == 0){
        __throw_runtime_error("ERROR: input not good\n");
        exit(1);
      }
      Fraction temp(fraction.numerator,fraction.denominator);
      fraction = temp;
      return input;
  }
    //constructor
    Fraction::Fraction(int num1, int num2){

      if(num2 == 0){
        __throw_invalid_argument("ERROR: denominator can't be-0\n");
        exit(1);
      }
      //doesn't really matter what the denominator if the numerator is 0
      if(num1 == 0){
        this->numerator = 0;
        this->denominator = 1;
        return;
      }
      //for the GCD function
      if(num1 < 0 && num2 < 0){
        num1 = (-1) * num1;
        num2 = (-1) * num2;
      }
      else if(num1 > 0 && num2 < 0){
        num1 = (-1) * num1;
        num2 = (-1) * num2;
      }
      int gcd = GCD(num1, num2);
      if(gcd < 0){
        gcd = (-1) * gcd;
      }
      //using the gcd to get the reduced fraction
      this->numerator = num1 / gcd;
      this->denominator = num2 / gcd;
    }
    //default constrincot
    Fraction::Fraction(){
      this->denominator = 1;
      this->denominator = 1;
    }
    Fraction::Fraction(float num){
      Fraction temp = convert(num);
      this->numerator = temp.getNumerator();
      this->denominator = temp.getDenominator();
    }
    Fraction Fraction::convert(float num)const{
      int Int = 0;
      //the accuracy is only 3 numbers ofter the (.)
      if(num < 0.001 && num > -0.001)
        return Fraction(0,1);
      //the complete part of the number
      if(num >= 1 || num <= -1)
        Int = (int) num;
      //the decimal part of the number
      int temp = (int)(num * 1000);
      temp = temp % 1000;
      return Fraction(temp + (Int * 1000),1000);
    }
    int Fraction::GCD(int num1, int num2){
      if( num2 == 0)
        return num1;
      return GCD(num2, num1 % num2);
    }

    int Fraction::getDenominator(){
      return this->denominator;
    }
    int Fraction::getNumerator(){
      return this->numerator;
    }


