#ifndef NODE_H
#define NODE_H
#include "NetworkPacket.h"
#include <iostream>
using std::string;
// TODO: Define the Node class
// Note: Since the functions are all small, you can put everything in this file
class Node {
    public:
        NetworkPacket packet; // Network packet containing the data.
        Node* next; // Points to next node in list.
        Node* prev; // Points to previous node in the list.

        // Default constructor.
        Node() {
            next = nullptr;
            prev = nullptr;
            NetworkPacket packet;
        }
        // Parameterized constuctor -> creates Node with data from provided packet.
        Node(const NetworkPacket& pack) {
            next = nullptr;
            prev = nullptr;
            this->packet = pack;
        }
        
        // Getters and Setters:
        // - getdata() returns the data from Network packet.
        std::string getData() {
            return packet.data;
        }
        // - getNext() returns next Node in linked list.
        Node* getNext() {
            return next;
        }
        // - getPrev() returns previous Node in linked list.
        Node* getPrev() {
            return prev;
        }
        // - setData() updates nodes network packet.
        void setData(const NetworkPacket& d) {
            this->packet = d;
        }
        // - setNext() updates nodes next pointer.
        void setNext(Node* n) {
            this->next = n;
        }
        // - setPrev() updates nodes previous pointer.
        void setPrev(Node* p) {
            this->prev = p;
        }


};


#endif
