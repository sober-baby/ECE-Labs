char dequeue(){
    if(head == NULL){
        return '\0';
    }
    Node *p = head;
    head = head -> getNext();
    if(head == NULL){
        tail = NULL;
    }
    c = p -> getData();
    p -> setNext(NULL);
    delete p;
    return c;
}

//Linked lists
//Requirements:
//-ordered:
//basic operations:
/*
insert()
search()
delete()
copy
*/
//destructor

#include "Node.h"
class List{
    private: 
        Node *head;
    public:
        List(){head = NULL;}
        ~List(){delete head;}
        void insertData(char);
        bool dataExists(char);
        bool deleteData(char);
        List(const List&);
        List& operator=(const List&);
}

//search solution 1
    bool List::dataExists(char c){
        for(Node* p=head; p!=NULL; p=p->getNext()){
            if(p->getData() == c){
                return true;
            }
        }
    }
//solution 2: only search as far as we have to
    bool List::dataExists(char c){
        for(Node* p=head; p!=NULL; p=p->getNext()){
            if(p->getData() == c){
                return true;
            }
            if(p->getData() > c){
                return false;
            }
        }
    }


//Insert into list 
//Strategy: - search through list to find where to insert
//- use ptr p to walk through the list
//- how far until first node where p->getData() > c
// Node then has to be inserted immediately to the left
// Problem: we lost track of prev node. to change its ptr.
//Idea： use a ptr prev that follows p one node behind