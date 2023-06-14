#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
namespace ariel{}
class Point{
    public:
    double x ,y;
    Point(double num1, double num2);
    double distance(Point other);
    void print();
    Point static moveTowards(Point source, Point dest, double distance);
    bool operator==(const Point& other) const;
    void set(Point other);
};
#endif