#ifndef NINJA
#define NINJA
#include <iostream>
#include "Point.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel{}
class Ninja : public Character{
    public:
    int speed;
    virtual void move(Character* enemy);
    void slash(Character* enemy);
    Ninja(string name, Point point);
    string print() const override;
    void attackEnemy(Character* enemy) override;
};
#endif