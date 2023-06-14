#include "Character.hpp"
#include <iostream>
using namespace std;
namespace ariel{}
    bool Character::isAlive()const{
      if(this->life > 0){
        return true;}
      return false;
    }
    //use point function for distance
    double Character::distance(Character* other)const{return other->loaction_.distance(this->loaction_);}
    void Character::hit(int num){
      if(num < 0)
        __throw_invalid_argument("error: hit\n");

      this->life = this->life - num;

    }
    string Character::getName()const{return this->name_;}
    Point Character::getLocation()const{return this->loaction_;}
    //constructors:

    Character::Character(string name, Point point) : inTeam(false) ,name_(name), loaction_(point){}
    ostream& operator<<(ostream& output,const Character& other){
        return output << "nothing";
      }
    Character::Character(const Character& other): inTeam(false), name_(other.name_), loaction_(other.loaction_){}
    Character::Character(Character&& other) noexcept : name_(other.name_), loaction_(other.loaction_){
      other.name_ = nullptr;
      other.loaction_.x = 0;
      other.loaction_.y = 0;
    }
    Character::~Character(){}
    //virtual fucntion
    void Character::attackEnemy(Character* enemy){}
    Character& Character::operator=(const Character& other){
      this->name_ = other.name_;
      this->loaction_ = other.loaction_;
      this->life = other.life;
      return *this;
    }
    Character& Character::operator=(Character&& other) noexcept {
      return *this;
    }
    Character::Character() : name_("nothing"), loaction_(Point(0,0)){
    }