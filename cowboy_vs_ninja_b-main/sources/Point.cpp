#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace std;
namespace ariel{}
    Point::Point(double num1, double num2) : x(num1), y(num2){}
    double Point::distance(Point other){
        double temp1 = this->x - other.x;
        double temp2 = this->y - other.y;
        return sqrt(pow(temp1,2)+pow(temp2,2));
    }
    void Point::print(){cout << "( " << this->x << ", " << this->y << ")" << endl;}
    Point Point::moveTowards(Point source, Point dest, double distance){
        if(distance < 0){
            __throw_invalid_argument("distance not good\n");
        }
        double dis = source.distance(dest);
        if(dis <= distance)
            return dest;
        double a = dest.x - source.x;
        double b = dest.y - source.y;
        double c = a / dis;
        double d = b / dis;
        double e = source.x + c * distance;
        double f = source.y + d * distance;
        return Point(e,f);

    }
    bool Point::operator==(const Point& other) const{
        if(this->x != other.x)
            return false;
        if(this->y != other.y)
            return false;
        return true;
    }
    void Point::set(Point other){
        this->x = other.x;
        this->y = other.y;
    }