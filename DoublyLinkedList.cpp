#include <iostream>
#include <sstream>
#include <string>
#include "DoublyLinkedList.h"
#include "Node.h"
using namespace std;
// Implement the copy constructor.
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
    : length(0), front(nullptr), back(nullptr)
{
    // Check if the list is empty.
    if (other.front == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }
    // Create temp pointer for traversing the source list.
    Node* curr = other.front;
    int index_count = 0; // Counter for keeping track of where to insert.
    while (curr != nullptr)
    {
        NetworkPacket pack = curr->getData(); // Get current nodes data.
        this->insert(pack, index_count); // Perform the insertion.
        index_count++; // Increment counter and curr.
        curr = curr->getNext();
    }
}

// Implement the copy assignment constructor.
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other) {
    // First do check for self assignment.
    if (this != &other)
    {
        // Clear current objects memory to avoid memory leak.
        this->clear();
        // Create temp pointer for traversing the source list.
        Node* curr = other.front;
        int index_count = 0; // Counter for keeping track of where to insert.
        while (curr != nullptr)
        {
            NetworkPacket pack = curr->getData(); // Get current nodes data.
            this->insert(pack, index_count); // Perform the insertion.
            index_count++; // Increment counter and curr.
            curr = curr->getNext();
        }
    }
    return *this;
}

// Implement the destructor. (use clear helper method)
DoublyLinkedList::~DoublyLinkedList() {
    this->clear();
}

//  Defining the insert function to add a node to the list.
void DoublyLinkedList::insert(NetworkPacket packet, int index) {
    // Verify that index is in range, if not throw exception.
    if (index < 0 || index > length) 
    {
        throw std::out_of_range("Index outside of list bounds");
    }
    // Create new node for insertion.
    Node* new_node = new Node(packet);
    // Check if head is null (empty list).
    if (front == nullptr)
    {
        front = new_node; // Make head the and tail point to first node.
        back = new_node; 
    } else if (index == 0) // Inserting at front if index = 0.
    {   
        new_node->setNext(front); // Set the new head next to point to old head.
        front->setPrev(new_node); // Set the old heads previous to point to new head.
        front = new_node; // Set new head.
    } else if (index == length) // Condition to check if new tail.
    { // Update pointers.
        back->setNext(new_node);
        new_node->setPrev(back);
        back = new_node;
    } else { // Inserting in to the middle or end of list.
        // Traverse list to insertion point (create temp pointers).
        Node* curr = front;
        Node* prev = nullptr;
        int count = 0; 
        while (curr != nullptr && count < index)
        { // traverse through the list until at correct index.
            prev = curr;
            curr = curr->getNext();
            count++;
        }
        // Compute insertion.
        new_node->setNext(curr);
        prev->setNext(new_node);
        new_node->setPrev(prev);
        curr->setPrev(new_node); 
        
    }
    // Update size of list.
    length++;
}

// - toString() converts linked list into a string.
string DoublyLinkedList::toString() {
    // Create string stream variable and variables for packet components.
    stringstream ss;
    string source = "SRC: ";
    string destination = "DST: ";
    string checkSum = "CKS: ";
    string data = "Data: ";
    // Create pointer for list traversal.
    Node* curr = front;
    while (curr != nullptr) 
    {   // Get the data from the Network packet inside of the node an add to ss.
        ss << source << curr->getData().source << ", ";
        ss << destination << curr->getData().destination << ", ";
        ss << checkSum << curr->getData().checksum << ", ";
        ss << data << curr->getData().data << "\n ";
        curr = curr->getNext();
    }
    // Convert ss into string variable to return.
    string output = ss.str();
    return output;
}

// Defining the remove() function which deletes a node from
// the list at specified index. Must return the Network packet.
NetworkPacket DoublyLinkedList::remove(int index) {
    // Throw exception if the list is empty.
    if (length == 0)
    {
        throw std::out_of_range("Index outside of list bounds");
    }
    // Throw exception if the index is outside the lists bounds.
    if (index < 0 || index > (length - 1))
    {
        throw std::out_of_range("Index outside of list bounds");
    }

    // Start conditions for removal (front, back, middle).
    // Also need to be sure to return proper packet.
    // Need to remember to decrease the size before returning packet.
    if (index == 0)
    { // If index is 0 need to delete head and set the heads next as new head.
        Node* curr = front;
        NetworkPacket pack = curr->getData();
        // Check if length is 1, then need to delete single element and
        // assign head and tail to null.
        if (length == 1) 
        {
            delete curr;
            front = nullptr;
            back = nullptr;
        }
        else { // If length is not 1 only need to reassign head and delete.
            front->next->prev = nullptr;
            front = front->next;
            delete curr;
        }
        length--;
        return pack;
    } else if (index == (length - 1)) // If index is (length - 1) we will have a new tail
    {
        Node* curr = back;
        back->prev->next = nullptr;
        back = back->prev;
        NetworkPacket pack = curr->getData();
        delete curr;
        length--;
        return pack;
    } else { // If not deleting head or tail we are deleting in the middle somewhere. 
        // Set temp pointer for traversal.
        Node* curr = front;
        // Set counter to track until we are at correct index.
        int counter = 0;
        while (counter < index) {
            curr = curr->next;
            counter++;
        }
        // Now we should be at correct spot for removal.
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        NetworkPacket pack = curr->getData();
        delete curr;
        length--;
        return pack;
    }
}

// Implement helper function clear():
void DoublyLinkedList::clear() {
    // Iterate through the list and delete each node.
    while (front != nullptr)
    {   // Start at the front and create temp point then delete front.
        // Shift the front to until reaching null.
        Node* deleteNode = front;
        front = front->next;
        delete deleteNode;
    }
    // Take care of dangling pointer.
    back = nullptr;
}
