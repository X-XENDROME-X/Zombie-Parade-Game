#include  "conga_raj.h"
#include "linkedlist_raj.hpp"
#include  "termcolor.hpp"


#include  <stdexcept>
#include  <cstdlib>

using namespace std;

//Below adds a zombie to the end of the conga line
void Conga::ActionCaboose(LinkedList<Zombie> *CongaLine , Zombie ZombieR) {
    CongaLine->AddToEnd(ZombieR);
}

//below adds a zombie to the front of the conga line
void Conga::ActionEngine(LinkedList<Zombie> *CongaLine , Zombie ZombieR) {
    CongaLine->AddToFront(ZombieR);
}

//below adds a zombie at a random position in the conga line
void Conga::ActionJumpIn(LinkedList<Zombie> *CongaLine , Zombie ZombieR) {

    // below generates a random position between 0 and the current length of the conga line
    int Position = rand() % (CongaLine->Length() + 1);

    // below checks if the random position is at the front of the conga line
    if (Position == 0) {
        // below adds the zombie to the front of the conga line
        CongaLine->AddToFront(ZombieR); 
    }

    // below checks if the random position is at the end of the conga line
    else if (Position == CongaLine->Length()) {
        // below adds the zombie to the end of the conga line
        CongaLine->AddToEnd(ZombieR); 
    }
    
    // If the random position is neither the front nor the end
    else {
        // Add the zombie at the randomly generated index
        CongaLine->AddAtIndex(ZombieR, Position);
    }
}

// below removes the first occurrence of a zombie from the conga line
void Conga::ActionYouOut(LinkedList<Zombie> *CongaLine , Zombie ZombieR) {
    // below checks if the conga line is not empty
   if (!(CongaLine->Length()==0)) {
    // below removes the first occurrence of the specified zombie type
        CongaLine->RemoveTheFirst(ZombieR);
    }
}

// below removes all occurrences of a zombie from the conga line
void Conga::ActionEveryoneOut(LinkedList<Zombie> *CongaLine , Zombie ZombieR) {
    CongaLine->RemoveAllOf(ZombieR);
}

// below adds a rainbow of zombies to the conga line
void Conga::ActionRainbow(LinkedList<Zombie> *CongaLine , Zombie ZombieR) {
    // below adds the original zombie to the front of the conga line (Engine)
    ActionEngine(CongaLine , ZombieR);

    // below adds zombies of different colors (Rainbow) to the end of the conga line (Caboose)
    ActionCaboose(CongaLine , Zombie('R'));
    ActionCaboose(CongaLine , Zombie('Y'));
    ActionCaboose(CongaLine , Zombie('G'));
    ActionCaboose(CongaLine , Zombie('B'));
    ActionCaboose(CongaLine , Zombie('C'));
    ActionCaboose(CongaLine , Zombie('M'));
}

// below adds two zombies to the conga line (Engine and Caboose) and place one in the middle
void Conga::ActionBrains(LinkedList<Zombie>* CongaLine ,Zombie ZombieR)  {

    // below creates two new zombies with the same type as ZombieR
    Zombie Zombie1(ZombieR.getType());
    Zombie Zombie2(ZombieR.getType());

    // below adds the first zombie to the front of the conga line (Engine)
    ActionEngine(CongaLine, Zombie1);
    // below adds the second zombie to the end of the conga line (Caboose)
    ActionCaboose(CongaLine ,Zombie2);
    
    // below calculates the index for adding the third zombie to the middle
    int RoundDownMiddle = (CongaLine->Length())/2;
    // below adds the third zombie (ZombieR) at the calculated index (RoundDownMiddle)
    CongaLine->AddAtIndex(ZombieR , RoundDownMiddle);

}

// below prints the current state of the conga line
void Conga::PrintingCongaLine(LinkedList<Zombie>* CongaLine) {
        CongaLine->PrintList();
}

// below gets the current size of the conga line
int Conga::GetCongaSize(LinkedList<Zombie>* CongaLine)  {
    return CongaLine->Length();
}

// below removes a zombie from the front of the conga line
void Conga::RemoveFromTheFront(LinkedList<Zombie>* CongaLine)  {
        CongaLine->RemoveFromFront();
}

// below removes a zombie from the end of the conga line
void Conga::RemoveFromTheEnd(LinkedList<Zombie>* CongaLine)  {
        CongaLine->RemoveFromEnd();
}
 
// below add a zombie next to an existing zombie of the same color, otherwise add to the end
void Conga::ActionFriends(LinkedList<Zombie>* CongaLine , Zombie ZombieR) {
    // below gets the color of the zombie to be added
    char ColorOfZombie = ZombieR.getType();

    // below finds the first occurrence of a zombie with the same color
    Node<Zombie>* NodeWeGot=CongaLine->Find(ColorOfZombie);

    // If no zombie with the same color exists, add the new zombie to the end
    if (NodeWeGot == nullptr) {
        ActionCaboose(CongaLine , ZombieR);
    } 
    else {
         // Otherwise if a zombie with the same color exists, randomly add before or after it
        if (rand()%2 == 0) {
            CongaLine->AddBefore(NodeWeGot , ZombieR);
        } else {
            CongaLine->AddAfter(NodeWeGot , ZombieR);
        }
    }
}
