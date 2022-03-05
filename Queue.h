#ifndef QUEUE_H
#define QUEUE_H
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;
// Implementing queue which is used in the simulation of first come first serve network router
class Queue {
    private:
        DoublyLinkedList dll; // Queue will be implemented using the doubly linked list.
    public:
        bool empty() {
            if (dll.getLength() == 0) 
            {   // If length is 0, queue is empty.
                return true;
            }
            return false; // Otherwise the queue has data.
        }
        void push_back(NetworkPacket data) {
            // Add the network packet at the tail of the linked list.
            dll.insert(data, dll.getLength()); // Length value will add at tail of list.
        }
        NetworkPacket pop_front() { // Return the front element of the linked list.
            return dll.remove(0);
        }
        string toString() { // Returns the contents of the queue as a string.
            return dll.toString();
        }
};
#endif
