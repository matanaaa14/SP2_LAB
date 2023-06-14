#include "YoungNinja.hpp"
#include <iostream>
namespace ariel{}
    YoungNinja::YoungNinja(string name, Point point) : Ninja(name,point){
        this->life = 100;
        this->speed = 14;
    }
