#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string>
#include <iostream>
#include "Node.h"

// Doubly Linked List implementation (templated)
template <typename T>
class DoublyLinkedList {
    
    private:
        Node<T>* front; // Pointer to the front element in list.
        Node<T>* back; // Pointer to the back element in the list.
        int length; // Keeps track of the number of elements in the list.
    
    public:
        // Default constructor.
        DoublyLinkedList(): front(nullptr), back(nullptr), length(0) {};
        
        // Rule of 3:
        ~DoublyLinkedList(); // Destructor
        DoublyLinkedList(const DoublyLinkedList& other); // Copy constructor
        DoublyLinkedList& operator=(const DoublyLinkedList& other); // Copy assignment constructor
        
        // Getters:
        // - getFront() returns the head of the list.
        Node<T>* getFront() {
            return front;
        }
        // - getBack() returns the tail of the list.
        Node<T>* getBack() {
            return back;
        }
        // - getLength() returns the number of elements in the list.
        int getLength() {
            return length;
        }

        // - insert() is used to add a new node at the specified
        // index in the LL
        void insert(T packet, int index);
        // - remove() deletes a node at the specified index
        T remove(int index);

        // - toString() converts the list into a string
        string toString();

        // - clear() is a helper function for the destructor and copy assignment
        // to delete a linked list.
        void clear();
};

#endif
