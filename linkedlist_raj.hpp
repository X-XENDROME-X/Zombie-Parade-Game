#ifndef LINKEDLIST_RAJ_HPP
#define LINKEDLIST_RAJ_HPP

#include  <stdexcept>
#include  <iostream>
#include  "termcolor.hpp"

using namespace std;

template<class> 
class LinkedList; //forward declaring

template<typename T>
class Node {

private:
    
    T  Data;
    Node<T>*  Next;
    Node<T>*  Previous;

public:
    Node() : Data(nullptr) , Next(nullptr) , Previous(nullptr){}; 
    Node(T Data):Data(Data) , Next(nullptr) , Previous(nullptr){};
    Node(T Data , Node<T>* Next,Node<T>*Prev):Data(Data) , Next(Next) , Previous(Prev){};

    // below are the getter and setter methods for Data, Next, and Previous
    T  getData() const;
    void  setData(T Data);
    void  setNext(Node<T>* Next);
    Node<T>*  getNext() const;
    Node<T>*  getPrevious() const;
    void  setPrevious(Node<T>* Previous);

    // below allows LinkedList class to access private members
    friend class LinkedList<T>;

};



template<typename T>
class LinkedList {

private:
    Node<T>*  Head;
    Node<T>*  Tail;
    int  ListSize;

public:

     // below are the constructor and Destructor
    LinkedList();
    ~LinkedList();

    //beloe are the methods for adding elements
    void  AddToFront(T Data);
    void  AddToEnd(T Data);
    void  AddAfter(Node<T>* Node, T Data);
    void  AddAtIndex(T Data, int Index);
    void  AddBefore(Node<T>* Node, T Data);

    // below are the methods for removing elements
    void  RemoveTheFirst(T Data);
    void  RemoveAllOf(T Data);
    T  RemoveFromFront();
    T  RemoveFromEnd();
    T  RemoveBefore(Node<T>* Node);
    T  RemoveAfter(Node<T>* Node);

    // below are the methods for checking and retrieving elements
    bool  ElementExists(T Data) const;
    Node<T>*  Find(T Data) const;
    T  RetrieveFront() const;
    T  RetrieveEnd() const;
    T  Retrieve(int Index) const;

    // Other utility methods
    int  IndexOf(T Data) const;
    void  PrintList() const;
    void  Empty();
    int  Length() const;
    Node<T>* GetHead() const;


};

// below is constructor for LinkedList class
template<typename T>
LinkedList<T>::LinkedList() : Head(nullptr) , Tail(nullptr) , ListSize(0) {};

// below is destructor for LinkedList class
template<typename T>
LinkedList<T>::~LinkedList()  {
    Empty();
}

// below is the getter method for the Next pointer of a Node
template<typename T>
Node<T>* Node<T>::getNext() const {
    return Next;
}

// below is the getter method for the Previous pointer of a Node
template<typename T>
Node<T>* Node<T>::getPrevious() const {
    return Previous;
}

// below is Getter method for the data stored in a Node
template<typename T>
T Node<T>::getData() const {
    return Data;
}

// below is setter method for updating the data in a Node
template<typename T>
void Node<T>::setData(T Data) {
    this->Data = Data;
}

// below is setter method for updating the Next pointer of a Node
template<typename T>
void Node<T>::setNext(Node<T>* Next) {
    this->Next = Next;
}

// below is setter method for updating the Previous pointer of a Node
template<typename T>
void Node<T>::setPrevious(Node<T>* Previous) {
    this->Previous = Previous;
}

// below is getter method for obtaining the Head pointer of the LinkedList
template<typename T>
Node<T>* LinkedList<T>::GetHead() const {
    return Head;
}

// below adds a new node with data 'Item' to the front of the linked list
template<typename T>
void LinkedList<T>::AddToFront(T Item) {

    // Create a new node with the provided data
    Node<T>* LatestNode=new Node<T>(Item);

    // If the list is empty, set both Head and Tail to the new node
    if (Head==nullptr){
        Head = LatestNode;
        Tail = LatestNode;
    }
    else {
        // If the list is not empty, insert the new node at the front
        Node<T>* Temp = Head;
        Head = LatestNode;
        LatestNode->setNext(Temp);
        Temp->setPrevious(LatestNode);
    }

    // Increment the size of the list
    ++ListSize;    
}

// below adds a new node with data 'Item' to the end of the linked list
template<typename T>
void LinkedList<T>::AddToEnd(T Item) {

    // Create a new node with the provided data
    Node<T>* LatestNode = new Node<T>(Item);

    LatestNode->setNext(nullptr);

     // If the list is empty, set both Head and Tail to the new node
    if (Head==nullptr) {
        LatestNode->setPrevious(nullptr);
        Tail = LatestNode;
        Head = LatestNode;
        
    }
    // Otherwise If the list is not empty, insert the new node at the end
     else {
        Tail->setNext(LatestNode);
        LatestNode->setPrevious(Tail);
        Tail = LatestNode;
    }
    // Increment the size of the list
    ++ListSize;  
}

// below adds a new node with data 'Item' at the specified position 'Position' in the linked list
template<typename T>
void LinkedList<T>::AddAtIndex(T Item, int Position) {
    // Start from the head of the list
    Node<T>*CurrentNode=Head;

    // Check if the specified position is out of range
    if ( Position > Length() || Position < 0 ) {    
        
        throw out_of_range("This is Out of Range");
    } 
    else if (Position == 0) {
         // If the position is 0, add the new node to the front of the list
        AddToFront(Item);
    } 
    else {
        // Create a new node with the provided data
        Node<T>*LatestNode=new Node<T>(Item);

        // Traverse the list to the node before the specified position
        for (int x=0;x<Position-1;++x) {
            CurrentNode = CurrentNode->getNext();
        }
            // Insert the new node at the specified position
            LatestNode->setNext(CurrentNode->getNext());
            LatestNode->setPrevious(CurrentNode);

            // Update the previous link of the node after the new node
            if(CurrentNode->getNext()!=nullptr){
                CurrentNode->getNext()->setPrevious(LatestNode);
            }

            // Update the next link of the specified node to the new node
            CurrentNode->setNext(LatestNode);

    }

     // Increment the size of the list
    ++ListSize;  
}

// below Add a new node with data 'Item' after the specified node
template<typename T>
void LinkedList<T>::AddAfter(Node<T>* node , T Item) {

    //below checks if the provided node is nullptr
    if (node==nullptr) {
        throw invalid_argument("This is an Invalid Argument");
    }

    // below creates a new node with the provided data, linked after the specified node
    Node<T>* LatestNode = new Node<T>(Item,node->getNext(),node);
    
    // below updates the previous link of the node after the new node
    if (node->getNext()!=nullptr) {    
       
        node->getNext()->setPrevious(LatestNode);
    
    }
    else{
        // If the specified node is the current tail, update the tail to the new node
        Tail = LatestNode;
    }
    // Update the next link of the specified node to the new node
    node->setNext(LatestNode);  
     // Increment the size of the list
    ++ListSize;      
        
}

// below adds a new node with data 'Item' before the specified node in the linked list
template<typename T>
void LinkedList<T>::AddBefore(Node<T>* node, T Item) {
    // below checks if the specified node is nullptr
    if (node==nullptr) {
        // below throw an exception for an invalid argument
        throw invalid_argument("This is an Invalid Argument");
    }

    // below creates a new node with the provided data, linking it to the previous and next nodes
    Node<T>* LatestNode = new Node<T>(Item,node,node->getPrevious());
    
    //below updates the next link of the node before the specified node
    if (node->getPrevious()!=nullptr) {          
        node->getPrevious()->setNext(LatestNode);  
    }
    else{
        // If there is no previous node, update the head of the list
        Head = LatestNode;
    }
    // Update the previous link of the specified node to the new node
    node->setPrevious(LatestNode); 
    // Increment the size of the list
    ++ListSize;  
}

// below removes and return the data from the end of the linked list
template<typename T>
T  LinkedList<T>::RemoveFromEnd()  {
    // Check if the tail of the list is nullptr
    if (Tail==nullptr) {
        // Throw an exception for an out-of-range operation
        throw out_of_range("This is Out of Range");
    }
    // Get the data from the tail of the list
    T Data=Tail->getData();
    // Create a temporary node pointing to the node before the tail
    Node<T>* Temporary = Tail;
    Temporary = Tail->getPrevious();
    
    // Update the next link of the node before the tail to nullptr
    if (Temporary != nullptr) {
        Temporary->setNext(nullptr);
    } 
    // Delete the tail node
    delete Tail;
    // Update the tail of the list to the temporary node
    Tail = Temporary;

    // If the tail is nullptr, update the head to nullptr as well
    if(Tail==nullptr){
       Head =nullptr; 
    }
        
    // Decrement the size of the list
    --ListSize; 
    // Return the removed data
    return Data;
}

// below removes and return the data from the front of the linked list
template<typename T>
T  LinkedList<T>::RemoveFromFront()  {
    // Check if the head of the list is nullptr
    if (Head==nullptr) {
        // Throw an exception for an out-of-range operation
        throw out_of_range("This is Out of Range");
    }
    // Get the data from the head of the list
    T Data=Head->getData();
    // Create a temporary node pointing to the node after the head
    Node<T>* Temporary = Head;
    Temporary = Head->getNext();
    
     // Update the previous link of the node after the head to nullptr
    if (Temporary != nullptr) {
        Temporary->setPrevious(nullptr);
    } 
    
    // Delete the head node
    delete Head;
    
    // Update the head of the list to the temporary node
    Head = Temporary;

    // If the head is nullptr, update the tail to nullptr as well
    if(Head==nullptr){
       Tail =nullptr; 
    }

    // Decrement the size of the list
    --ListSize; 
    return Data;

}

// Remove and return the data from the node after the specified node in the linked lists
template<typename T>
T  LinkedList<T>::RemoveAfter(Node<T>* node) {
    // Check if the specified node is nullptr or if it's the tail of the list
    if (node==Tail||node == nullptr||node->getNext()==nullptr) {
        // Throw an exception for an invalid argument
        throw invalid_argument("This is an Invalid Argument");
    }

    // Get the data from the node after the specified node
    T Data =  node->getNext()->getData();

    // Create a temporary node pointing to the node after the specified node
    Node<T>* Temporary = node->getNext();

    // Update the previous link of the node after the specified node to the specified node
    if(Temporary->getNext()!=nullptr){
        node->getNext()->getNext()->setPrevious(node);
        node->setNext(Temporary->getNext());}
    else{
        // If the node after the specified node is the tail, update the tail to the specified node
        Tail = node;
        node->setNext(nullptr);
    }
    // Delete the temporary node
    delete Temporary;
     // Decrement the size of the list
    --ListSize; 
    return Data;
}

// below removes and return the data from the node before the specified node in the linked list
template<typename T>
T  LinkedList<T>::RemoveBefore(Node<T>* node) {
    // Check if the specified node is the tail, is nullptr, or if the previous node is nullptr
    if (node==Tail||node == nullptr||node->getNext()==nullptr) {
        throw invalid_argument("This is an Invalid Argument");
    }

    T Data =  node->getPrevious()->getData();

    Node<T>* Temporary = node->getPrevious();
    // Update the next link of the node before the specified node to the specified node
    if(Temporary!=Head){
        node->getPrevious()->getPrevious()->setNext(node);
        node->setPrevious(Temporary->getPrevious());}
    else{
        // If the node before the specified node is the head, update the head to the specified node
        Head = node;
        node->setPrevious(nullptr);
    }
     // Delete the temporary node
    delete Temporary;

     // Decrement the size of the list
    --ListSize; 
    return Data;
}

// below removes all occurrences of the specified data in the linked list
template<typename T>
void  LinkedList<T>::RemoveAllOf(T Data) {
    // Start from the head of the list
    Node<T>* CurrentNode=Head;
    // Traverse the list
    while (CurrentNode != nullptr) {
         // Check if the data of the current node matches the specified data
        if (CurrentNode->getData() == Data) {
            // Check if the current node is the hea
            if (CurrentNode == Head) {
                // Update the head to the next node
                Head = CurrentNode->getNext();
                // If the next node is not nullptr, update its previous link to nullptr
                if(Head!=nullptr){
                    Head->setPrevious(nullptr);
                } 
                // Delete the current node
                delete CurrentNode;
                CurrentNode = Head;
            }
            else {
                 // Update the next link of the previous node to the next node
                 CurrentNode->getPrevious()->setNext(CurrentNode->getNext());
                 
                // If the next node is not nullptr, update its previous link to the previous node
                 if (CurrentNode->getNext()!=nullptr) {
                      CurrentNode->getNext()->setPrevious(CurrentNode->getPrevious());
                    } 

                  // Create a temporary node pointing to the next node  
                  Node<T>* Temporary=CurrentNode->getNext();
                  // Delete the current node
                  delete CurrentNode;
                  // Update the current node to the temporary node
                  CurrentNode = Temporary;
                  // Decrement the size of the list
                  --ListSize; 
            }
        }
                 
         else {
              // Move to the next node
            CurrentNode = CurrentNode->getNext();
        }   
    }
}

// below removes the first occurrence of a node with the specified data from the linked list
template<typename T>
void  LinkedList<T>::RemoveTheFirst(T Data) {
    // Start from the head of the list
    Node<T>* CurrentNode = Head;

    // Traverse the list until the end or until the node with matching data is found
    while ((CurrentNode!=nullptr)  &&  !(CurrentNode->getData() == Data)) {
        CurrentNode=CurrentNode->getNext();
    }

     // Check if the node with matching data was found
    if(CurrentNode !=nullptr){
        // Check if the node is the head
        if(CurrentNode == Head){
            // Update the head to the next node
             Head = CurrentNode->getNext();
            // If the next node is not nullptr, update its previous link to nullptr
            if(Head!=nullptr){
                Head->setPrevious(nullptr);
            }
        } else{
            // Update the next link of the previous node to the next node
            CurrentNode->getPrevious()->setNext(CurrentNode->getNext());
             // If the next node is not nullptr, update its previous link to the previous node
                if (CurrentNode->getNext() != nullptr){
                CurrentNode->getNext()->setPrevious(CurrentNode->getPrevious());
                }
            }
    }
     // Delete the node with matching data
    delete CurrentNode;
     // Decrement the size of the list
    --ListSize;
}

// below Retrieve data from the front of the linked list
template<typename T>
T LinkedList<T>::RetrieveFront() const{
    // Check if the list is empty
    if (Head == nullptr) {
        throw out_of_range("This is Out of Range");
    }
    // Return the data from the head node
    return Head->getData();
}


// below Retrieve data from the end of the linked list
template<typename T>
T LinkedList<T>::RetrieveEnd() const{
      // Check if the list is empty
    if (Tail == nullptr) {
        throw out_of_range("This is Out of Range");
    }
    // Return the data from the tail node
    return Tail->getData();
}

// below Retrieve data from a specific position in the linked list
template<typename T>
T LinkedList<T>::Retrieve(int Position)const{
    // Check if the specified position is out of range
    if (Position<0 || Position>=Length()) {
        throw out_of_range("This is Out of Range");
    }
     // Start from the head of the list
    Node<T>*CurrentNode=Head;
      // Traverse the list to the specified position
    for (int x=0 ; x<Position ; ++x) {
        CurrentNode=CurrentNode->getNext();
    }
     // Return the data from the node at the specified position
    return CurrentNode->getData();
}

// below Finds the index of the first occurrence of the specified data in the linked list
template<typename T>
int LinkedList<T>::IndexOf(T Data)const{
    // Start from the head of the list
    Node<T>* CurrentNode =Head;
    int x=0;

    // Traverse the list
    while (CurrentNode!=nullptr) {
         // Check if the data of the current node matches the specified data
        if (CurrentNode->getData()==Data) {
            // Return the index if a match is found
            return x;
        }
         // Move to the next node in the list
        CurrentNode=CurrentNode->getNext();
        // Increment the index
        ++x;
    }
    // Return -1 if the data is not found in the list
    return -1; 
}

// below Check if the specified data exists in the linked list
template<typename T>
bool LinkedList<T>::ElementExists(T Data)const {
     // Start from the head of the list
    Node<T>* CurrentNode=Head;
    // Traverse the list
    while (CurrentNode!=nullptr) {
          // Check if the data of the current node matches the specified data
        if (CurrentNode->getData()==Data) {
            // Return true if a match is found
            return true;
        }
        // Move to the next node in the list
        CurrentNode=CurrentNode->getNext();
    }
    // Return false if the data is not found in the list
    return false;
}

//below  find the first node containing the specified data in the linked list
template<typename T>
Node<T>* LinkedList<T>::Find(T Data)const {
    // Start from the head of the list
    Node<T>* CurrentNode = Head;
    // Traverse the list
    while (CurrentNode!=nullptr) {
        // Check if the data of the current node matches the specified data
        if (CurrentNode->getData()==Data) {
             // Return the pointer to the found node
            return CurrentNode;
        }
        // Move to the next node in the list
        CurrentNode=CurrentNode->getNext();
    }
    // Return nullptr if the data is not found in the list
    return nullptr; 
}

// below Get the length (number of nodes) of the linked list
template<typename T>
int LinkedList<T>::Length()const {
    int length =0;
    Node<T>* currentNode = Head;
    // Traverse the list and count the nodes
    while(currentNode!=nullptr){
        length+=1;
        currentNode = currentNode->getNext();
    }
    return length;
}

// below Empty the linked list by deleting all nodes
template<typename T>
void LinkedList<T>::Empty(){
    Node<T>* CurrentNode = Head;
    Node<T>* Temporary;
    // Traverse the list and delete each node
    while(CurrentNode!=nullptr){
      Temporary=CurrentNode->getNext();
      delete CurrentNode;
      CurrentNode = Temporary;
    }
    // Set both Head and Tail to nullptr, indicating an empty list
    Tail=nullptr;
    Head=nullptr;
}

// below print the contents of the linked list with colored zombie types
template<typename T>
void LinkedList<T>::PrintList() const {
    // below print the contents of the linked list with colored zombie types
    cout<<termcolor::colorize;
    // Start from the head of the list
    Node<T>* CurrentNode = Head;
    // Traverse the list
    while (CurrentNode != nullptr) {
        // Get the type of zombie stored in the current node
        char TypeOfZombie = CurrentNode->getData().getType();

        // Choose color based on the type of zombie
         if (TypeOfZombie == 'R') {
            cout << termcolor::blue;
        } else if (TypeOfZombie == 'Y') {
            cout << termcolor::cyan;
        } else if (TypeOfZombie == 'B') {
            cout << termcolor::green;
        } else if (TypeOfZombie == 'G') {
            cout << termcolor::bright_blue;
        } else if (TypeOfZombie == 'M') {
            cout << termcolor::yellow;
        } else if (TypeOfZombie == 'C') {
            cout << termcolor::red;
        } else {
            cout << termcolor::magenta;
        }

        // Print the zombie type in square brackets
        cout << "[" << TypeOfZombie << "]";
        // Reset color to default
        cout << termcolor::reset;
        // Move to the next node in the list
        CurrentNode = CurrentNode->getNext();
        
        // Print "=" if there is another node in the list
        if (CurrentNode != nullptr) {
            cout << "="; 
        }
    }
    // Print a new line after printing the list
    cout << endl;
}


#endif 