/*
Linked Lists

Motivation: Many data structure have been proposed, some are used over and over again:

- arrays & vectors
- linked lists
    - ordered
    - Queue (FIFO)
    - Stack (FILO)
- Hash Tables

Learn which is best for what and how to use

Stack:
- 2 operations push() & pop(); implemented as a linked list

#include "Node.h"

class Stack {
    private:
        Node *head;
    public:
        Stack() { head = NULL; }
        ~Stack() { delete head; }
        // We don't want people to see the implementation, which is why we don't pass a node inside but to create a node in the push function
        // Push new node to the first element
        void push(char d) {
            // Step 1: Create New Node
            Node* p = new Node(d,head);
            // New head address is p
            head = p;

        }

        char pop() {
            if (head == NULL) {
                return '\0'; // Return Null Character
            }

            Node *p = head;
            char c = p -> getData();
            head = p -> getNext();
            p -> setNext(Null); // This step prevents us from deleting the entire linked list due to destructors
            delete p;
            return c;
        }

        // Will the code work if stack is empty?
        // Will it work if you pop the last element of stack?

}

// Queues

2 operations:
enqueue(char);
dequeue();


class Node {
    private:
        char data;
        Node *next;
    
    public:
        Node();
        Node(char);
        Node(char, Node*);
        ~Node() {
            delete next;
        }
        char getData() { return data; }
        Node* getNext() { return next; }
        void setData(char c) { data = c; }
        void setNext(Node* n) { next = n; }

}




*/