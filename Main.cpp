#include "linkedlist_raj.hpp"
#include  "conga_raj.h"
#include  "zombie_raj.h"
#include  <iostream>
#include  <ctime>
#include  "termcolor.hpp"
#include  "EC.h"

using namespace std;

int main(int argc , char* argv[]) {

    // below sets default seed
    int seed=(150);

    // below checks if a custom seed is provided as a command-line argument
    if (argc>2&&string(argv[1])=="-s") {
        
        seed=atoi(argv[2]);
        srand(seed);   
    } 
    else {
       
        srand(seed);
    }
    
    // below checks if "-EC" flag is provided for EC mode
    bool EC=false;
    if (argc>1 && string(argv[1])=="-EC") {
        EC = true;
    }
 
    // below creates a linked list to store zombies
    LinkedList<Zombie>* ZombieList= new LinkedList<Zombie>;

    // below create a Conga object
    Conga* CongaObject = new Conga();
    
    // below simulates adding zombies to the conga line based on random events
    // Each event is associated with a color and the corresponding Conga action
    int  Random1 = rand()%6;
    switch (Random1) {
        case 0:  CongaObject->ActionRainbow(ZombieList, Zombie('R')); break;
        case 1:  CongaObject->ActionRainbow(ZombieList, Zombie('Y')); break;
        case 2:  CongaObject->ActionRainbow(ZombieList, Zombie('G')); break;
        case 3:  CongaObject->ActionRainbow(ZombieList, Zombie('B')); break;
        case 4:  CongaObject->ActionRainbow(ZombieList, Zombie('C')); break;
        case 5:  CongaObject->ActionRainbow(ZombieList, Zombie('M')); break;
    }

    // below simulates adding zombies to the conga line based on random events
    // Each event is associated with a color and the corresponding Conga action
    int Random2 = rand()%6;
    switch (Random2) {
        case 0:  CongaObject->ActionBrains(ZombieList, Zombie('R')); break;
        case 1:  CongaObject->ActionBrains(ZombieList, Zombie('Y')); break;
        case 2:  CongaObject->ActionBrains(ZombieList, Zombie('G')); break;
        case 3:  CongaObject->ActionBrains(ZombieList, Zombie('B')); break;
        case 4:  CongaObject->ActionBrains(ZombieList, Zombie('C')); break;
        case 5:  CongaObject->ActionBrains(ZombieList, Zombie('M')); break;
    }

    // below simulates adding zombies to the conga line based on random events
    // Each event is associated with a color and the corresponding Conga action
    int Random3 = rand()%6;
    switch (Random3) {
        case 0:  CongaObject->ActionBrains(ZombieList, Zombie('R')); break;
        case 1:  CongaObject->ActionBrains(ZombieList, Zombie('Y')); break;
        case 2:  CongaObject->ActionBrains(ZombieList, Zombie('G')); break;
        case 3:  CongaObject->ActionBrains(ZombieList, Zombie('B')); break;
        case 4:  CongaObject->ActionBrains(ZombieList, Zombie('C')); break;
        case 5:  CongaObject->ActionBrains(ZombieList, Zombie('M')); break;
    }

    // below simulates adding zombies to the conga line based on random events
    // Each event is associated with a color and the corresponding Conga action
    int Random4 = rand()%6;
    switch (Random4) {
        case 0:  CongaObject->ActionBrains(ZombieList, Zombie('R')); break;
        case 1:  CongaObject->ActionBrains(ZombieList, Zombie('Y')); break;
        case 2:  CongaObject->ActionBrains(ZombieList, Zombie('G')); break;
        case 3:  CongaObject->ActionBrains(ZombieList, Zombie('B')); break;
        case 4:  CongaObject->ActionBrains(ZombieList, Zombie('C')); break;
        case 5:  CongaObject->ActionBrains(ZombieList, Zombie('M')); break;
    }  

    // below initializes the number of rounds
    int Rounds;
    if (EC) {
        // If in EC mode, set a fixed number of rounds
        Rounds = 1000;

    } else {
        // If not in EC mode, prompt the user for the number of rounds
        cout << "Number of Rounds do you want to Run? ";
        cin >> Rounds;
    }

    for (int x=0 ; x<Rounds ;++x) {

        // Every 5 rounds, remove a zombie from the front and the end of the conga line
        if (x % 5 == 0) {
            if (CongaObject->GetCongaSize(ZombieList) > 0) {
                CongaObject->RemoveFromTheFront(ZombieList);
                CongaObject->RemoveFromTheEnd(ZombieList);
            }
        }
         
        //below randomly choose an action and a zombie type for the current round
        int ChoiceOfAction =rand()%8;
        int ChoiceOfZombie =rand()%6;

        // below display information about the current round
        cout << "Round: " << x << "\n";
        cout << "Size: " << CongaObject->GetCongaSize(ZombieList) << " :: ";

        // below prints the line.
        CongaObject->PrintingCongaLine(ZombieList);

        // below creates a Zombie object based on the randomly chosen zombie type 
        Zombie ZombieS;
        switch (ChoiceOfZombie) {
            case 0:ZombieS=Zombie('R');  break;
            case 1:ZombieS=Zombie('Y');  break;
            case 2:ZombieS=Zombie('G');  break;
            case 3:ZombieS=Zombie('B');  break;
            case 4:ZombieS=Zombie('C');  break;
            case 5:ZombieS=Zombie('M');  break;
        }

        // below perform a Conga action based on the randomly chosen action
        switch (ChoiceOfAction) {
            case 0:CongaObject->ActionEngine(ZombieList , ZombieS);  break;
            case 1:CongaObject->ActionCaboose(ZombieList , ZombieS);  break;
            case 2:CongaObject->ActionJumpIn(ZombieList , ZombieS);  break;
            case 3:CongaObject->ActionEveryoneOut(ZombieList , ZombieS);  break;
            case 4:CongaObject->ActionYouOut(ZombieList , ZombieS);  break;
            case 5:CongaObject->ActionBrains(ZombieList , ZombieS);  break;
            case 6:CongaObject->ActionRainbow(ZombieList , ZombieS);  break;
            case 7:CongaObject->ActionFriends(ZombieList , ZombieS);  break;
        }

        cout << "New Zombie: " ;
        cout<<termcolor::colorize;

        // below sets color based on the type of the new zombie
        if (ZombieS.getType() == 'R') {    
            cout << termcolor::blue;
        } 
        else if (ZombieS.getType() == 'Y') {
            cout << termcolor::cyan;
        }
        else if (ZombieS.getType() == 'B') {
            cout << termcolor::green;
        } 
        else if (ZombieS.getType() == 'G') {
            cout << termcolor::bright_blue;
        } 
        else if (ZombieS.getType() == 'M') {
            cout << termcolor::yellow;
        } 
        else if (ZombieS.getType() == 'C') {
            cout << termcolor::red;
        } 
        else {
            cout << termcolor::magenta;
        }

        //below displays the action performed
        cout << "[";
        cout << ZombieS.getType() ;
        cout << "]";
        cout << termcolor::reset;
        cout << " -- Action: [";

        //below displays the action performed
        switch (ChoiceOfAction) {
            
            case 0:cout<<"Engine!";  break;
            case 1:cout<<"Caboose!";  break;
            case 2:cout<<"Jump In!";  break;
            case 3:cout<<"Everyone Out!";  break;
            case 4:cout<<"You Out!";  break;
            case 5:cout<<"Brains!";  break;
            case 6:cout<<"Rainbow!";  break;
            case 7:cout<<"New Friends!";  break;
        
        }
        // below displays the current state of the conga line
        cout<<"]\n";
        cout<<"The New CongaLine Line is Now:\n";
        cout <<"Size: "<<CongaObject->GetCongaSize(ZombieList) <<" :: ";
        CongaObject->PrintingCongaLine(ZombieList);
        cout << "********************************************\n";

    }
    
    char Continue;
    cout<<"The Party is Over. Do you want to Continue (y/n)? ";
    cin>>Continue;
    // below asks If the user wants to continue, prompt for the number of additional rounds
    if (Continue== 'Y'||Continue== 'y') {
        cout<<"How many More Rounds do you want to Run now? ";
        cin>>Rounds;
     }
    
    // below initializes an array to count the occurrences of each zombie type
    int CountsOfZombie[6]={0}; 
    // below counts the occurrences of each zombie type in the current conga line
    ZombieTypesCounter(ZombieList , CountsOfZombie);

    // below continues fighting zombies until only one type remains
    while (CountRemainingColors(CountsOfZombie)>1) {
        FightingZombies(CountsOfZombie);
    }
    // below determines the winner zombie type
    char WinnerZ = Winner(CountsOfZombie);
    cout << "The Winner Zombie is: " << WinnerZ << endl;

    // below deallocates memory for the dynamically allocated objects
    delete ZombieList;
    delete CongaObject;
 
    // below returns 0 to indicate successful program execution
    return 0;
 }
 




