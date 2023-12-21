#include  <iostream>
#include  "linkedlist_raj.hpp"
#include  "conga_raj.h"
#include  "zombie_raj.h"
 
 // Below is the function to determine the winner based on the counts array
 char Winner(int Counter[]) {
     // below iterate through the Counter array for each zombie type (0 to 5)
        for (int x=0; x<6;++x) {
            // below checks if there are remaining zombies of the current type
            if (0< Counter[x]) {
            // below returns the winning zombie type (converted to a character)
            return (char)('A'+x);
            }
        }
        // Below returns when there are no winners;
        return 'X'; 
}

// Below is the function to count the remaining colors of zombies based on the counts array
int CountRemainingColors(int Counter[]) {
    int ColorsRemaining=0;
    
    // below Iterates through the Counter array for each zombie type (0 to 5)
    for (int x= 0; x< 6; ++x) {
        //below checks if there are remaining zombies of the current type
        if (0 < Counter[x]) {
            //Below increments the count of remaining colors
            ++ColorsRemaining;
        }
    }
    // below returns the total count of remaining colors
    return ColorsRemaining;
}

//Below is the function to count the occurrences of each zombie type in the Conga line
void ZombieTypesCounter(LinkedList<Zombie>* CongaLine , int counts[]) {
    Node<Zombie>* CurrentZ = CongaLine->GetHead();
    
    //Below traverses the Conga line until the end of the linked list is reached
    while (CurrentZ != nullptr) {
        
        //Below gets the zombie type from the current node's data
        char type = CurrentZ->getData().getType();
        //Below increments the count for the respective zombie type
        ++counts[type - 'A']; 
        CurrentZ = CurrentZ->getNext();
    
    }
}

//Below is the function to simulate a fight between zombies based on the counts array
void FightingZombies(int Counter[]) {
    int Position1 , Position2;

    //Below keeps randomly selecting two different positions (zombie types) until they are distinct
    do {
       //Below randomly selects two different positions (zombie types)
        Position1 = rand()%6;
        Position2 = rand()%6;
    
    } 
    
    while (Position1==Position2); 

    //Below maps the selected positions to corresponding zombie types
    char ZType1 = (char)('A'+Position1);
    char ZType2 = (char)('A'+Position2);

    //Below rolls dice for each zombie type, generating random numbers from 1 to 6
    int DRoll1 = rand()%6+1; 
    int DRoll2 = rand()%6+1; 


     //Below adjusts dice rolls based on zombie types (G vs. R gives advantage)
    if (ZType1=='G' && ZType2=='R') {
        //Below increases the value of the first dice roll
        DRoll1 = (int)(DRoll1*1.5);
    } 
    else if (ZType1=='R' && ZType2=='G') {
        //Below increases the value of the second dice roll
        DRoll2 = (int)(DRoll2*1.5);
    }

    //Below compares dice rolls to determine the winner of the fight
    if (DRoll1>DRoll2) {
        //Below decreases the count of the losing zombie type
        --Counter[Position2];
    } 
    else {
        //Below decreases the count of the losing zombie type of pos2
        --Counter[Position1];
    }
}