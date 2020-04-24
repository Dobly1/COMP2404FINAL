#ifndef LLIST_H
#define LLIST_H

/*
Class: LList
Author: Callum M

Purpose:
    -LList is a template class for storing T* in a singly linked list
    -It's a dumb linked-list in the sense that it has the bare minimum functions and you cannot remove a single node
    -However it was necessary for the playerLogger class and can easily be expanded

Data Members:
    -Node* head
        -This is just a pointer to the node that represents the head of the linked list
    -int size
        -This represents the size of the linked list i.e. how many nodes it contains

Member Functions:
    -LList()
        -This is the default constructor to initalize head to NULL and size to 0
    -~LList()
        -This is the destructor that deletes all the dynamically allocated nodes and leaves the data untouched as we deallocate it elsewhere
    -void add(T*)
        -Adds a new node with data specified from the parameter to the end of the linked list
    -T* get(int)
        -Returns the data stored in the Node at the index specified in the constructor - Has bounds check so people don't try and get nodes that are out of bounds
    -int getSize()
        -A getter to return the size of the list and make iterating over it easier
*/

/*
Class: Node
Author: Callum M

Purpose:
    -Act as a node for a linked list

Data Members:
    -T* data
        -A pointer to the data contained in the node
    -Node* next
        -A pointer to the next node in the linked list

*/


template<class T>
class LList
{
    class Node
    {
        public:
            T* data;
            Node* next;
    };

    public:
        LList();
        ~LList();

        //Adds a new element
        void add(T*);

        //Returns item at index I
        T* get(int);

        //Returns size of the list
        int getSize();

    private:
        Node* head;
        int size;
};


template<class T>
LList<T>::LList() : head(NULL), size(0)
{
    //Nothing needed
}

template<class T>
LList<T>::~LList()
{
    Node* travNode = head;
    Node* delNode;

    //Doesn't delete the data
    while(travNode != NULL)
    {
        delNode = travNode;
        travNode = travNode->next;

        delete delNode;
    }
}

template<class T>
void LList<T>::add(T* data)
{
    //Make a new node with the data we want
    Node* addNode = new Node;
    addNode->data = data;
    addNode->next = NULL;
    size++;

    //Handle the case for empty list
    if(!head)
    {
        head = addNode;
        return;
    }

    Node* travNode = head;
    
    //Find the last element of the list
    while(travNode->next != NULL)
        travNode = travNode->next;


    //Set our new data
    travNode->next = addNode;
}


template<class T>
T* LList<T>::get(int i)
{
    //Make sure we won't get out of bounds
    if( i < 0 || i >= size)
        throw "Out of Bounds!";

    //If the list is empty don't touch something we shouldn't
    if(size == 0)
        return NULL;

    Node* travNode = head;

    for(int j = 0; j < i; j++)
        travNode = travNode->next;

    //Return the wanted item
    return travNode->data;

}

template<class T>
int LList<T>::getSize()
{
    return size;
}

#endif