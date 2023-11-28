#include "RegisterList.h"

#include <iostream>

#include "Register.h"
using namespace std;

RegisterList::RegisterList() {
  head = nullptr;
  size = 0;
}

RegisterList::~RegisterList() {
  // Delete all registers in the list
  if(head == nullptr) {
    return;
  }
  Register* temp = head;
  while(temp != nullptr) {
    Register* next = temp->get_next();
    delete temp;
    temp = next;
  }

}

Register* RegisterList::get_head() {  
  return head;
}

int RegisterList::get_size() { 
  // return number of registers 
  return size;
}


Register* RegisterList::get_min_items_register() {
  // loop all registers to find the register with least number of items

  
  Register* min = head;
  if(head == nullptr) {
    return nullptr;
  }
  Register* temp = head->get_next();

  while(temp != nullptr) {
    if(temp->get_queue_list()->get_items() < min->get_queue_list()->get_items()) {
      min = temp;
    }
    temp = temp->get_next();
  }

  return min;
}

Register* RegisterList::get_free_register() {
  // return the register with no customers
  // if all registers are occupied, return nullptr

  Register* temp = head;
  while(temp != nullptr) {
    if(temp->get_queue_list()->get_head() == nullptr) {
      return temp;
    }
    temp = temp->get_next();
  }
  return nullptr;
}

void RegisterList::enqueue(Register* newRegister) {
  // a register is placed at the end of the queue
  // if the register's list is empty, the register becomes the head
  // Assume the next of the newRegister is set to null
  // You will have to increment size 

  if(head == nullptr) {
    head = newRegister;
    size++;
    return;
  }

  Register* temp = head;
  while(temp->get_next() != nullptr) {
    temp = temp->get_next();
  }
  temp->set_next(newRegister);
  size++;
}

bool RegisterList::foundRegister(int ID) {
  // look for a register with the given ID
  // return true if found, false otherwise

  Register* temp = head;
  while(temp != nullptr) {
    if(temp->get_ID() == ID) {
      return true;
    }
    temp = temp->get_next();
  }
  return false;

}

Register* RegisterList::dequeue(int ID) {
  // dequeue the register with given ID
  // return the dequeued register
  // return nullptr if register was not found

  if(head == nullptr) {
    return nullptr;
  }
  if(head->get_ID() == ID) {
    Register* temp = head;
    head = head->get_next();
    temp->set_next(nullptr);
    size--;
    return temp;
  }
  Register* temp = head;
  while(temp->get_next() != nullptr) {
    if(temp->get_next()->get_ID() == ID) {
      Register* temp2 = temp->get_next();
      temp->set_next(temp->get_next()->get_next());
      temp2->set_next(nullptr);
      size--;
      return temp2;
    }
    temp = temp->get_next();
  }
  return nullptr;
}


Register* RegisterList::calculateMinDepartTimeRegister(double expTimeElapsed){

  // return the register with minimum time of departure of its customer
  // if all registers are free, return nullptr

  bool all_free = true;
  Register* min = head;
  if(head == nullptr) {
    return nullptr;
  }

  Register* temp = head->get_next();
  double min_time = temp->get_availableTime();
  if(temp->get_queue_list()->get_head() != nullptr) {
    Customer* ctemp = temp->get_queue_list()->get_head();
    while (ctemp != nullptr) {
      min_time += ctemp->get_numOfItems() * temp->get_secPerItem() + temp->get_overheadPerCustomer();
      ctemp = ctemp->get_next();
    }
  }

  if(min_time > expTimeElapsed) {
    all_free = false;
  }

  while(temp != nullptr) {
    double temp_time = temp->get_availableTime();
    if(temp->get_queue_list()->get_head() != nullptr) {
    Customer* ctemp = temp->get_queue_list()->get_head();
      while (ctemp != nullptr) {
        temp_time += ctemp->get_numOfItems() * temp->get_secPerItem() + temp->get_overheadPerCustomer();
        ctemp = ctemp->get_next();
      }
    }
    if(temp_time > expTimeElapsed) {
      all_free = false;
    }

    if(temp_time < min_time) {
      min = temp;
      min_time = temp_time;
    }

    temp = temp->get_next();
  }

  if(all_free) {
    return nullptr;
  }
  return min;
}

void RegisterList::print() {
  Register* temp = head;
  while (temp != nullptr) {
    temp->print();
    temp = temp->get_next();
  }
}
