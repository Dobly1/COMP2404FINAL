#ifndef LLIST_H
#define LLIST_H

#include <iostream>
using namespace std;

template<class T>
class LList
{
    class Node
    {
        public:
        T* data;
        Node* next;
        Node* prev;
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
    //
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