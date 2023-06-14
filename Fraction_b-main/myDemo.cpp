
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;
#define MAX_INT numeric_limits<int>::max()


int main() {
    Fraction a(140,1120), b(19,23);
    cout << "a: " << a << ", b: " << b << endl;
    cout << "a + b = " << a+b << endl; 
    cout << "a - b = " << a-b << endl; 
    cout << "a / b = " << a/b << endl; 
    cout << "a * b = " << a*b << endl; 
    cout << "2.3 * b = " << 2.3*b << endl; 
    cout << "a+2.421" << a+2.421 << endl; 
    Fraction c(1,2);
    cout << c++ << endl;
    cout << --c << endl;
    c++;
    cout << c << endl;
    c--;
    c--;
    cout << c << endl;
    c++;
    Fraction d(1,4);
    cout << "c >=b ? : " << (c >= b) << endl;
    if (c > 0.5) cout << " c is bigger than 0.5" << endl;
    if (c >= 0.5) cout << " c is bigger than 0.5" << endl;
    if (c > 0.25) cout << " c is bigger than 0.25" << endl;
    if (c > d) cout << " c is bigger than d" << endl;
    if (c < d) cout << " d is bigger than c" << endl;
    float num = 0.1;
    Fraction e = c.convert(num);
    cout << " e is: " << e << endl;
    int num1 = 13596;
    int num2 = 36;
    cout << "the gcd of 13596 and 36 is: " << e.GCD(num1,num2) << endl;

}
