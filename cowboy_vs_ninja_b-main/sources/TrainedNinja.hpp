#ifndef TRAINEDNINJA
#define TRAINEDNINJA
#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
using namespace std;

namespace ariel{}
class TrainedNinja : public Ninja{
    public:
    TrainedNinja(string name, Point point);

};
#endif