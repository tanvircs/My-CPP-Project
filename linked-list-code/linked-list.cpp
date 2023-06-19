#include <iostream>

// Node class representing a single node in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert a new node at the beginning of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Display the elements of the linked list
    void display() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Creating the first linked list
    LinkedList list1;
    list1.insert(5);
    list1.insert(10);
    list1.insert(15);
    list1.insert(20);

    // Creating the second linked list
    LinkedList list2;
    list2.insert(3);
    list2.insert(6);
    list2.insert(9);
    list2.insert(12);

    // Displaying the first linked list
    std::cout << "First Linked List: ";
    list1.display();

    // Displaying the second linked list
    std::cout << "Second Linked List: ";
    list2.display();

    return 0;
}
