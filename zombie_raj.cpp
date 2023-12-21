#include  "zombie_raj.h"
#include  "termcolor.hpp"

using namespace std;

//Below is the default constructor initializes the 'Type' attribute to a default value (space).
Zombie::Zombie() : Type(' ') { 
    
}

//Below is the parameterized constructor that initializes the 'Type' attribute with the provided value.
Zombie::Zombie(char Type) : Type(Type) { 

}

//Below is the getter function to retrieve the 'Type' attribute.
char Zombie::getType()  const {
    return Type;
}

// Below is the overloaded stream insertion operator (<<) for easy printing of Zombie objects.
ostream& operator<<(ostream& OStream , const Zombie& Zombie) {
    
        //Below outputs the type of the zombie
        OStream << "Type: " << Zombie.getType();
        return OStream;
}

//Below is overloaded equality operator (==) for comparing two Zombie objects.
bool Zombie::operator==(const Zombie&  OZombie)  const {
    
    //Below the Zombies are considered equal if their types are the same
    return Type==OZombie.Type;
}

