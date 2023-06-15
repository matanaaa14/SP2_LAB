/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */
//https://github.com/cpp-exercises/cowboy_vs_ninja_b/tree/main
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/Team2.hpp"
#include "sources/smartTeam.hpp"
using namespace ariel;


int main() {
   Point a(0,0);
   Point b(100,100);
   Point c(20,30);
   Cowboy* c1= new Cowboy("cowboy1",a);
   Cowboy* c2 = new Cowboy("cowboy2",b);
   Cowboy* c3 = new Cowboy("cowboy3",c);
   Cowboy* c4 = new Cowboy("cowboy4",a);
   Cowboy* c5 = new Cowboy("cowboy5",b);
   Cowboy* c6 = new Cowboy("cowboy6",c);

   Ninja* n1 = new Ninja("ninja1",a);
   Ninja* n2 = new Ninja("ninja2",b);
   Ninja* n3 = new Ninja("ninja3",c);
   Ninja* n4 = new Ninja("ninja4",a);
   Ninja* n5 = new Ninja("ninja5",b);
   Ninja* n6 = new Ninja("ninja6",c);

   smartTeam smartT(n4);
   Team2 team2(c1);
   smartT.add(n5);
   smartT.add(n6);
   smartT.add(c4);
   smartT.add(c5);
   smartT.add(c6);
   team2.add(c2);   
   team2.add(c3);   
   team2.add(n1);   
   team2.add(n2);   
   team2.add(n3);   
   cout << "smartT num of live members: " << smartT.stillAlive() << endl;
   cout << "team2 num of live members: " << team2.stillAlive() << endl;
     while(smartT.stillAlive() > 0 && team2.stillAlive() > 0){

        smartT.attack(&team2);
        team2.attack(&smartT);
        smartT.print();
        team2.print();
     }
     if (smartT.stillAlive() > 0) cout << "winner is smartT" << endl;
     else cout << "winner is team2" << endl;

    cout << "end" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
