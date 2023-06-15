#ifndef TEAM2
#define TEAM2
#include "Team.hpp"
#include <iostream>
#include "array"
#include "vector"
using namespace std;
//#define  arraySize 10
namespace ariel{}
class Team2 : public Team{
    public:
    void attack(Team* enemy) override;
    void print() override;
    Team2(Character* leader);
    Team2& operator=(const Team& other);

};
#endif