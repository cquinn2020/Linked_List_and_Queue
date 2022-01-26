#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string>
#include <iostream>
#include "Node.h"

// Doubly Linked List implementation
class DoublyLinkedList {
    
    private:
        Node* front; // Pointer to the front element in list.
        Node* back; // Pointer to the back element in the list.
        int length; // Keeps track of the number of elements in the list.
    
    public:
        // Default constructor.
        DoublyLinkedList(): front(nullptr), back(nullptr), length(0) {};
        
        // Rule of 3:
        //~DoublyLinkedList(); // Destructor
        //DoublyLinkedList(const DoublyLinkedList& other); // Copy constructor
        //DoublyLinkedList& operator=(const DoublyLinkedList& other); // Copy assignment const.
        
        // Getters:
        // - getFront() returns the head of the list.
        Node* getFront() {
            return front;
        }
        // - getBack() returns the tail of the list.
        Node* getBack() {
            return back;
        }
        // - getLength() returns the number of elements in the list.
        int getLength() {
            return length;
        }


};

#endif
