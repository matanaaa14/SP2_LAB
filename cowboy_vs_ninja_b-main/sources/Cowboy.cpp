#include "Cowboy.hpp"
#include "Character.hpp"
#include <iostream>
namespace ariel{}
    void Cowboy::shoot(Character* enemy){
      //checks if the situation is possiable
        if(!enemy->isAlive())
          __throw_runtime_error("cannot attack dead character\n");
        if(!this->isAlive())
          __throw_runtime_error("dead caracter can't attack\n");
        if(this == enemy)
          __throw_runtime_error("friendly fire\n");
      if(this->numOfBullets  < 1)
        this->reload();
      else{
      enemy->hit(10);
      this->numOfBullets--;
    }
    }
    bool Cowboy::hasboolets(){
      if(this->numOfBullets > 0)
        return true;
      return false;
    
    }
    void Cowboy::reload(){
      if(!this->isAlive())
        __throw_runtime_error("dead cowboy can't reload\n");
      this->numOfBullets = 6;
    }
    string Cowboy::print() const{
      if(!this->isAlive())
        return "C ("+this->name_+")" +"("+to_string(this->loaction_.x)+", "+to_string(this->loaction_.y)+")" ;
      return "C "+this->name_+" "+ to_string(this->life)+" ("+to_string(this->loaction_.x)+", "+to_string(this->loaction_.y)+")" ;}

    Cowboy::Cowboy(string name, Point point) : Character(name,point){
      this->numOfBullets = 6;
      this->life = 110;
    }
    ostream& operator<<(ostream& output,const Cowboy& other){
        return output << "nothing";
      }
    void Cowboy::attackEnemy(Character* enemy){
      this->shoot(enemy);
    }