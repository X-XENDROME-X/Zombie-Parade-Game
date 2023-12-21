#ifndef CONGA_RAJ_H
#define CONGA_RAJ_H
#include "linkedlist_raj.hpp"  
#include "zombie_raj.h"     

class Conga {


public:
    //below function to perform the 'Engine' action in the conga line
    void ActionEngine(LinkedList<Zombie> *CongaLine ,Zombie ZombieR);

    //below function to perform the 'Caboose' action in the conga line
    void ActionCaboose(LinkedList<Zombie> *CongaLine , Zombie ZombieR);

    //below function to perform the 'Rainbow' action in the conga line
    void ActionRainbow(LinkedList<Zombie> *CongaLine ,Zombie ZombieR);

    //below function to perform the 'Friends' action in the conga line
    void ActionFriends(LinkedList<Zombie> *CongaLine  ,Zombie ZombieR);

    //below function to perform the 'Jump In' action in the conga line
    void ActionJumpIn( LinkedList<Zombie> *CongaLine , Zombie ZombieR);

    //below function to perform the 'Everyone Out' action in the conga line
    void ActionEveryoneOut(LinkedList<Zombie> *CongaLine  , Zombie ZombieR);

    //below function to perform the 'You Out' action in the conga line
    void ActionYouOut(LinkedList<Zombie>* CongaLine  , Zombie ZombieR);

    //below function to perform the 'Brains' action in the conga line
    void ActionBrains(LinkedList<Zombie>* CongaLine , Zombie ZombieR);

    //below function to print the current state of the conga line
    void PrintingCongaLine(LinkedList<Zombie>* CongaLine) ;

    //below function to get the current size of the conga line
    int GetCongaSize(LinkedList<Zombie> *CongaLine);

    //below function to remove a zombie from the front of the conga line
    void RemoveFromTheFront(LinkedList<Zombie>* CongaLine);

    //below function to remove a zombie from the end of the conga line
    void RemoveFromTheEnd(LinkedList<Zombie>* CongaLine);
};

#endif 