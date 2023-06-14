#ifndef YOUNGNINJA
#define YOUNGNINJA
#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
using namespace std;

namespace ariel{}
class YoungNinja : public Ninja{
    public:
    YoungNinja(string name, Point point);
};
#endif