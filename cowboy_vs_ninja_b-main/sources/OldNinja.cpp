#include "OldNinja.hpp"
#include <iostream>
namespace ariel{}
    OldNinja::OldNinja(string name, Point point) : Ninja(name,point){
        this->life = 150;
        this->speed = 8;
    }
