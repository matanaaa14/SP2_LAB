#include "MagicalContainer.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
    MagicalContainer::MagicalContainer(){}
    void MagicalContainer::addElement(int element){
        this->myVector.emplace_back(element);
        //update the itearator help vector 
        if(this->AscendVector.size() > 0){
            AscendingIterator temp(*this);
            for(unsigned long i = 0; i < this->AscendVector.size(); i++){
                if(this->AscendVector.at(i) != nullptr)
                    this->AscendVector.at(i) = &temp;
            }
        }
        //update the itearator help vector 

        if(this->primeVector.size() > 0){
            PrimeIterator temp(*this);
            for(unsigned long i = 0; i < this->primeVector.size(); i++){
                if(this->primeVector.at(i) != nullptr)
                    this->primeVector.at(i) = &temp;
            }
        }
        //update the itearator help indexes 
        if(this->AscendVector.size() > 0){
            SideCrossIterator temp(*this);
            for(unsigned long i = 0; i < this->sideVector.size(); i++){
                if(this->sideVector.at(i) != nullptr)
                    this->sideVector.at(i) = &temp;
            }
        }
    }
    int MagicalContainer::size()const{return this->myVector.size();}
    void  MagicalContainer::removeElement(int element){
        //first find the element then delete it
        auto e = find(this->myVector.begin(), this->myVector.end(), element);
        if( e != myVector.end()){
            this->myVector.erase(e);
        }
        else{
            __throw_runtime_error("removeElement\n");
        }
        //update the itearator help vector 
        if(this->AscendVector.size() > 0){
            AscendingIterator temp(*this);
            for(unsigned long i = 0; i < this->AscendVector.size(); i++){
                if(this->AscendVector.at(i) != nullptr)
                    this->AscendVector.at(i) = &temp;
            }
        }
        //update the itearator help vector 
        if(this->primeVector.size() > 0){
            PrimeIterator temp(*this);
            for(unsigned long i = 0; i < this->primeVector.size(); i++){
                if(this->primeVector.at(i) != nullptr)
                    this->primeVector.at(i) = &temp;
            }
        }
        //update the itearator help indexes     
        if(this->AscendVector.size() > 0){
            SideCrossIterator temp(*this);
            for(unsigned long i = 0; i < this->sideVector.size(); i++){
                if(this->sideVector.at(i) != nullptr)
                    this->sideVector.at(i) = &temp;
            }
        }
    }
    void MagicalContainer::addTovector(AscendingIterator& vec){
        AscendingIterator* pointer = &vec;
        this->AscendVector.emplace_back(pointer);
    } 
////////////////////////////
    //constructor that get refernce to MagicalContainer
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& other) : Index_(0){
        this->container_ = &other;
        int lastMin = -100000;
        //set a vector of const int pointers that will point to element of the container and will be ascending order
        for(unsigned long i = 0; i < other.myVector.size(); i++){
            int min = 100000;
            unsigned long index = 0;
            //each run finds the lowest int that doesn't already have pointer in the pointer's vector
            for(unsigned long j = 0; j < other.myVector.size(); j++){
                if(other.myVector.at(j) < min && other.myVector.at(j) > lastMin ){
                    min = other.myVector.at(j);
                    index = j;
                }
            }
            lastMin = other.myVector.at(index);
            const int* a = &(other.myVector.at(index));
            this->pointersVector.emplace_back(a);
        }
        other.AscendVector.emplace_back(this);
    }
    MagicalContainer::AscendingIterator::~AscendingIterator(){}
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
        if(this->container_ != NULL)
            __throw_runtime_error("not empty\n");
        this->container_ = other.container_;
        this->Index_ = other.Index_;
        this->pointersVector = other.pointersVector;
        return *this;
        }
    bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator& other) const{
        return (this->Index_ == other.Index_ );}
    bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator& other) const{return !(*this == other);}
    bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator& other){return this->Index_ < other.Index_;}
    bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator& other){return this->Index_ > other.Index_;}
    int MagicalContainer::AscendingIterator::operator*(){
            return *(this->pointersVector.at(this->Index_));}
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        if(this->Index_ == this->container_->size() )
            __throw_runtime_error("++\n");
        this->Index_++;
        return *this;}
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin(){this->Index_ = 0;return *this;}
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end(){this->Index_ = (unsigned long)this->container_->size(); return *this;}
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other){
        this->container_ = other.container_;
        this->Index_ = other.Index_;
        this->pointersVector = other.pointersVector;
    }
    //for tidy
    MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator&& other) noexcept{}
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(AscendingIterator&& other) noexcept{return *this;}        
    ////////////////////////////////////////
    //MagicalContainer::PrimeIterator::PrimeIterator(){}
    //constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& other) : Index_(0){
        this->container_ = &other;
        for(unsigned long i = 0; i < other.size(); i++){
            //set a vector of pointers that each pointer will point to a prime number in the container
            if(isPrime(other.myVector.at(i))){
            const int* a = &other.myVector.at(i);
            this->pointersVector.emplace_back(a);}
        }
    }
    MagicalContainer::PrimeIterator::~PrimeIterator(){}
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
        if(this->container_ != NULL)
            __throw_runtime_error("not empty\n");
        this->container_ = other.container_;
        this->Index_ = other.Index_;
        return *this;
        }
    bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator& other) const{
        return (this->Index_ == other.Index_ );}
    bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator& other) const{return !(*this == other);}
    bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator& other){return this->Index_ < other.Index_;}
    bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator& other){return this->Index_ > other.Index_;}
    int MagicalContainer::PrimeIterator::operator*(){   
         int value = *(this->pointersVector.at(0));
         return *(this->pointersVector.at(static_cast<std::vector<unsigned long>::size_type>(this->Index_)));}
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
        if(this->Index_ == this->pointersVector.size())
            __throw_runtime_error("++");
        this->Index_++;
        return *this;}
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin(){this->Index_ = 0;return *this;}
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end(){this->Index_ = this->pointersVector.size(); return *this;}
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other){
        this->container_ = other.container_;
        this->Index_ = other.Index_;
        this->pointersVector = other.pointersVector;
    }

    bool MagicalContainer::PrimeIterator::isPrime(int number) {
        // Handle special cases
        if (number <= 1) {
            return false;
        }

        // Check for divisibility up to the square root of the number
        int sqrtNumber = static_cast<int>(std::sqrt(number));
        for (int i = 2; i <= sqrtNumber; ++i) {
            if (number % i == 0) {
                return false;
            }
        }

        return true;
    }

    //for tidy
    MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator&& other) noexcept{}
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(PrimeIterator&& other) noexcept{return *this;}        
     ///////////////////////////////
    //MagicalContainer::SideCrossIterator::SideCrossIterator(){}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& other) : Index_(0),fromTheBegin(1), fromTheEnd(other.size()-1), cnt(1){
        this->container_ = &other;
    }
    MagicalContainer::SideCrossIterator::~SideCrossIterator(){}
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
        if(this->container_ != NULL)
            __throw_runtime_error("not empty\n");
        this->container_ = other.container_;
        this->Index_ = other.Index_;
        this->fromTheBegin = other.fromTheBegin;
        this->fromTheEnd = other.fromTheEnd;
        return *this;

        }
    bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator& other) const{
        return (this->fromTheBegin == other.fromTheBegin && this->fromTheEnd == other.fromTheEnd  );}
    bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator& other) const{return !(*this == other);}
    bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator& other){return this->Index_ < other.Index_;}
    bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator& other){return this->Index_ > other.Index_;}
    int MagicalContainer::SideCrossIterator::operator*(){    return this->container_->myVector.at(static_cast<std::vector<int>::size_type>(this->Index_));}
    //there are 2 index addition to the iteator place index
    //one starts in the begining of the vector and the other in the end
    //each time ++ happend the iterator index swittch between them
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
        if((this->container_->myVector.size() % 2 == 0)&&(this->Index_ == this->container_->size() / 2) &&(this->fromTheBegin == this->container_->size() / 2) &&(this->fromTheEnd == this->container_->size() / 2))
            __throw_runtime_error("++\n");
        else if(this->Index_ == this->container_->size() / 2 && this->fromTheBegin == this->container_->size() / 2 + 1 && this->fromTheEnd == this->container_->size() / 2 - 1)
            __throw_runtime_error("++\n");
    
        if(this->cnt % 2 == 0){
            this->Index_ = this->fromTheBegin;
            this->fromTheBegin++;
        }
        else{
            this->Index_ = this->fromTheEnd;
            this->fromTheEnd--;
        }
        this->cnt++;
        
        return *this;}
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin()
    {this->Index_ = 0;
    this->fromTheBegin = 1;
    this->fromTheEnd = this->container_->size() - 1;
    this->cnt = 1;
    return *this;}
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end(){
        //sets when to stop and distinguishes between 2 differents cases
        //one when the vector size is odd 
        //second when the vector size is even
        if(this->container_->myVector.size() % 2 == 0){
            this->Index_ = this->container_->size() / 2;
            this->fromTheBegin = this->container_->size() / 2 ;
            this->fromTheEnd = this->container_->size() / 2;}
        else{
            this->Index_ = this->container_->size() / 2 ;
            this->fromTheBegin = this->container_->size() / 2 + 1;
            this->fromTheEnd = this->container_->size() / 2 - 1;
        }
         return *this;}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other){

        this->container_ = other.container_;
        this->Index_ = other.Index_;
        this->fromTheBegin = other.fromTheBegin;
        this->fromTheEnd = other.fromTheEnd ;
        this->cnt = other.cnt;
    }
    //for tidy
    MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator&& other) noexcept{}
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(SideCrossIterator&& other) noexcept
    {  
        return *this;}        
  