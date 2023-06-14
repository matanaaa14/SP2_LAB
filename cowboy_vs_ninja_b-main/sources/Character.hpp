#ifndef CHARACTER
#define CHARACTER
#include <iostream>
#include "Point.hpp"
using namespace std;

namespace ariel{}
class Character{
    public:
    Point loaction_;
    string name_;
    int life;
    bool inTeam;
    bool isAlive()const;
    double distance(Character* other)const;
    void hit(int num);
    string getName()const;
    Point getLocation()const;
    virtual string print() const = 0;
    Character(string name, Point point);
    friend std::ostream& operator<<(std::ostream& ostreamm, const Character& other);
    virtual ~Character();
    Character();
    Character(const Character& other);
    Character(Character&& other) noexcept;
    Character& operator=(const Character& other);
    Character& operator=(Character&& other) noexcept;
    virtual void attackEnemy(Character* enemy);
};
#endif
