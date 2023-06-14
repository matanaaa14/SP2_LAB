#include "Team2.hpp"
#include "Character.hpp"
#include <iostream>
namespace ariel{}
    void Team2::print(){
      for(unsigned long i = 0; i < this->arr.size(); i++){
        if(this->arr[i] != nullptr ){
            this->arr[i]->print();
          }
        }
    }

    //construcotr 
        Team2::Team2(Character* leader) : Team(leader){

    }
    void Team2::attack(Team* enemy){
      if(enemy == nullptr)
        __throw_invalid_argument  ("can't attack null pointer\n");
      if(enemy->stillAlive() <= 0)
        __throw_runtime_error("can't attack a dead team\n");
      int index = 0;
      unsigned long index2 = 0;
      if(!this->leader_->isAlive())
        this->newLeader();
      unsigned long j = this->whoToAttack(enemy);
      if(j == 11){
        return;
      }

      
      while( index2 < this->arr.size()){

        if(!enemy->arr[j]->isAlive()){
          j = this->whoToAttack(enemy);
          if(j == 11)
            return;
        }
        if(this->arr[index2] != nullptr && this->arr[index2]->isAlive()){
          if(Cowboy* cowboy = dynamic_cast<Cowboy*>(this->arr[index2]) ){
            if(cowboy->hasboolets()){
              cowboy->shoot(enemy->arr[j]);
            }
            else{
              cowboy->reload();
            }
          }
          else if(Ninja* ninja = dynamic_cast<Ninja*>(this->arr[index2]) ){
            if(ninja->distance(enemy->arr[j]) <= 1){
              ninja->slash(enemy->arr[j]);
            }
            else{
              ninja->move(enemy->arr[j]);
            }
          }
        }
        index2++;
      }
    }
    Team2& Team2::operator=(const Team& other){

      for(unsigned long i = 0; i < this->arr.size(); i++){
            this->arr[i] = other.arr[i];
        }      
      return *this;
    }