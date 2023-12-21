#ifndef EC_H
#define EC_H
#include  "linkedlist_raj.hpp"
#include  "conga_raj.h"
#include  "zombie_raj.h"
     
//Below is the function to count the occurrences of each zombie type in the Conga line
void ZombieTypesCounter(LinkedList<Zombie>* CongaLine , int Counter[]);

//Below is the function to count the remaining colors of zombies based on the counts array
int CountRemainingColors(int Counter[]);

//Below is the function to simulate a fight between zombies based on the counts array
void FightingZombies(int Counter[]);

//Below is the function to determine the winner based on the counts array
char Winner(int Counter[]);

#endif
