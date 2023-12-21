#ifndef ZOMBIE_RAJ_H
#define ZOMBIE_RAJ_H
#include <string>
#include <iostream>
#include <stdexcept>

using namespace  std;

class Zombie{

private:
    
    //Below is the private member variable to store the type of the zombie
    char Type;

public:
    // Below are the Constructors
    Zombie();
    Zombie(char Type);

    // Below overloaded equality operator
    bool  operator==(const Zombie& OZombie) const;
    //Below is the getter method for retrieving the zombie type
    char  getType() const; 
    // Below is Friend function for streaming output
    friend  ostream& operator<<(ostream& OStream , const Zombie& Zombie);
    
    
};

#endif