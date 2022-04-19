#ifndef NODE_H
#define NODE_H

#include <iostream>

using std::string;

// Templating the node to enable linked list to hold any type of data 
template <typename T>
class Node {
    public:
        T packet; // Packet containing the data.
        Node<T>* next; // Points to next node in list.
        Node<T>* prev; // Points to previous node in the list.

        // Default constructor.
        Node() {
            next = nullptr;
            prev = nullptr;
            T packet;
        }
        // Parameterized constuctor -> creates Node with data from provided packet.
        Node(const T& pack) {
            next = nullptr;
            prev = nullptr;
            this->packet = pack;
        }
        
        // Getters and Setters:
        // - getdata() returns the data from packet.
        T getData() {
            return packet;
        }
        // - getNext() returns next Node in linked list.
        Node<T>* getNext() {
            return next;
        }
        // - getPrev() returns previous Node in linked list.
        Node<T>* getPrev() {
            return prev;
        }
        // - setData() updates nodes packet.
        void setData(const T& d) {
            this->packet = d;
        }
        // - setNext() updates nodes next pointer.
        void setNext(Node<T>* n) {
            this->next = n;
        }
        // - setPrev() updates nodes previous pointer.
        void setPrev(Node<T>* p) {
            this->prev = p;
        }
};

#endif
