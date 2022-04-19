#ifndef QUEUE_H
#define QUEUE_H
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

// Implementing queue which is used in the simulation of first come first serve network router.
// -> templated version
template <typename T>
class Queue {
    public:
        DoublyLinkedList<T> dll; // Queue will be implemented using the doubly linked list.
        // Returns if the queue is empty.
        bool empty() {
            if (dll.getLength() == 0) 
            {   // If length is 0, queue is empty.
                return true;
            }
            return false; // Otherwise the queue has data.
        }
        // Adds to the back of the queue.
        void push_back(T data) {
            // Add the packet at the tail of the linked list.
            dll.insert(data, dll.getLength()); // Length value will add at tail of list.
        }
        // Remove the front element of the queue.
        T pop_front() { // Return the front element of the linked list.
            return dll.remove(0);
        }
        // Returns the contents of the queue as a string.
        string toString() { 
            return dll.toString();
        }
};
#endif
