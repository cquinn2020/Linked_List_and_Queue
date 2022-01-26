#include <iostream>
#include "DoublyLinkedList.h"
//#include "Node.h"

using namespace std;

int main() {
    // Create packet.
    string source = "65.80.56.41";
    string destination = "113.255.154.162";
    string checkSum = "0d3821aac0479550e5c33bb66696085e";
    string data = "HTTPS 1.1 GET www.tamu.edu";

    NetworkPacket testPack = NetworkPacket(source, destination, checkSum, data);
    // Output to console.
    cout << "Test Packet:\n";
    cout << testPack;

    // Create Node;
    Node testNode = Node(testPack);

    // Do basic tests.
    cout << endl << "Running basic tests on the Node:" << endl;
    if (testNode.next == nullptr && testNode.prev == nullptr)
    {
        cout << "PASSED: Both next and previous nodes point to nullptr.\n";
    }
    else {
        cout << "FAILED: Either next or previous node is not nullptr.\n";
    }
    cout << "Checking if we can access the packet and still output the data.\n";
    cout << testNode.packet << endl;

    // Testing nodes getters and setters.
    cout << endl << "Testing nodes getters and setters.\n";
    if (testNode.getNext() == nullptr && testNode.getPrev() == nullptr)
    {
        cout << "PASSED: Both the getNext() and getPrev() are returning nullptr.\n";
    }
    else {
        cout << "FAILED: getNext or getPrev not working correctly.\n";
    }
    cout << "\nTesting getData():\n";
    if (testNode.getData() == "HTTPS 1.1 GET www.tamu.edu")
    {
        cout << "PASSED: getData() returned correct string.\n";
    }
    else {
        cout << "FAILED: getData() not working correctly.\n";
    }
    
    // Test setters for Node.
    cout << "\nTestings Nodes setters.\n";
    // Create new node.
    Node n(NetworkPacket("0","0","A","Hello!"));
    // Update the data.
    n.setData(NetworkPacket("0","0","Z","Goodbye!"));
    if (n.getData() == "Goodbye!")
    {
        cout << "PASSED: Successfully updated the nodes data.\n";
    }
    else {
        cout << "FAILED: Did not successfully update the nodes data.\n";
    }

    // Beginning of tests for doubly linked list.
    cout << endl << "Beginning of testing for doubly linked list.\n";
    cout << "First creating linked list object.\n";
    // Create a linked list object.
    DoublyLinkedList LL;
    // Check default constructor.
    cout << "Testing getters (front, back, length):\n";
    if (LL.getFront() == nullptr && LL.getBack() == nullptr)
    {
        cout << "PASSED: Both the front/back of the list were intially set as null.\n";
    }
    else {
        cout << "FAILED: Either front or back is not set as null.\n";
    }
    if (LL.getLength() == 0)
    {
        cout << "PASSED: Length was initially set to 0.\n";
    }
    else {
        cout << "FAILED: Length not initially set as 0.\n";
    }
    
    
    


    
    
}