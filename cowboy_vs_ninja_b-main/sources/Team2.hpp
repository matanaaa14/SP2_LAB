#ifndef TEAM2
#define TEAM2
#include <iostream>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "array"
#include "vector"
#include "Team.hpp"
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