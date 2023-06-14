#ifndef OLDNINJA
#define OLDNINJA
#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
using namespace std;

namespace ariel{}
class OldNinja : public Ninja{
    public:
    OldNinja(string name, Point point);

};
#endif