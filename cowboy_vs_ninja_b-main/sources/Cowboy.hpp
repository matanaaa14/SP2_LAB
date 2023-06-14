#ifndef COWBOY
#define COWBOY
#include <iostream>
#include "Character.hpp"
namespace ariel{}
using namespace std;
class Cowboy : public Character{
    public:
    int numOfBullets;
    void shoot(Character* enemy);
    bool hasboolets();
    void reload();
    Cowboy();
    Cowboy(string name, Point point);
    string print() const override;
    friend std::ostream& operator<<(std::ostream& ostreamm, const Cowboy& other);
    void attackEnemy(Character* enemy) override;

};
#endif