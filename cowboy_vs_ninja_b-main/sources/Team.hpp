#ifndef TEAM
#define TEAM
#include <iostream>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "array"
#include "vector"
using namespace std;
//#define  arraySize 10
constexpr int arraySize = 10;
namespace ariel{}
class Team{
    public:
    vector<Character*> arr;
    Character* leader_;
    void add(Character* fighter);
    virtual void attack(Team* enemy);
    int stillAlive();
    virtual void print();
    Team(Character* leader);
    virtual ~Team();
    Team(const Team& other);
    Team(Team&& other) noexcept;
    Team& operator=(const Team& other);
    Team& operator=(Team&& other) noexcept;
    unsigned long whoToAttack(Team* enemy);
    unsigned long newLeader();
};
#endif
