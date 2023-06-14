#ifndef SMARTTEAM
#define SMARTTEAM
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
class smartTeam : public Team{
    public:
    void attack(Team* enemy) override;
    void print() override;
    smartTeam(Character* leader);
    smartTeam& operator=(const Team& other);

};
#endif