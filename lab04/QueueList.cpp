#include "QueueList.h"

#include "Customer.h"

QueueList::QueueList() { head = nullptr; }

QueueList::QueueList(Customer* customer) { head = customer; }

QueueList::~QueueList() {
  // Delete all customers in the queue
  if(head != nullptr) {
    Customer* temp = head;
    while(temp != nullptr) {
      Customer* next = temp->get_next();
      delete temp;
      temp = next;
    }
  }
  return;
}

Customer* QueueList::get_head() {  
  return head;
}

void QueueList::enqueue(Customer* customer) {
  // a customer is placed at the end of the queue
  // if the queue is empty, the customer becomes the head

  if (head == nullptr) {
    head = customer;
    return;
  }
  Customer* temp = head;
  while (temp->get_next() != nullptr) {
    temp = temp->get_next();
  }
  temp->set_next(customer);
  
}

Customer* QueueList::dequeue() {
  // remove a customer from the head of the queue 
  // and return a pointer to it

  if (head == nullptr) {
    return nullptr;
  }
  Customer* temp = head;
  head = head->get_next();
  temp->set_next(nullptr);
  return temp;
  
}

int QueueList::get_items() {
  // count total number of items each customer in the queue has
  int total = 0;
  Customer* temp = head;
  while (temp != nullptr) {
    total += temp->get_numOfItems();
    temp = temp->get_next();
  }
  return total;
}

bool QueueList::empty_queue() {
  // if the queue is empty, return false
  // if the queue is not empty, delete all customers
  // and return true

  if (head == nullptr) {
    return false;
  }

  Customer* temp = head;
  while (temp != nullptr) {
    Customer* next = temp->get_next();
    delete temp;
    temp = next;
  }

  return true;

}

void QueueList::print() {
  // print customers in a queue
  Customer* temp = head;
  while (temp != nullptr) {
    temp->print();
    temp = temp->get_next();
  }
}


