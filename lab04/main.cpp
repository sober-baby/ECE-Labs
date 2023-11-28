#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>

#include "Customer.h"
#include "QueueList.h"
#include "Register.h"
#include "RegisterList.h"

using namespace std;

// Function Declarations:

// Set mode of the simulation
string getMode();

// Register
void parseRegisterAction(stringstream &lineStream, string mode);
void openRegister(
    stringstream &lineStream,
    string mode);  // register opens (it is upto customers to join)
void closeRegister(stringstream &lineStream,
                   string mode);  // register closes 

// Customer
void addCustomer(stringstream &lineStream,
                 string mode);  // customer wants to join


// Helper functions
bool getInt(stringstream &lineStream, int &iValue);
bool getDouble(stringstream &lineStream, double &dValue);
bool foundMoreArgs(stringstream &lineStream);

void update_single();
void update_multiple();

// Global variables
RegisterList *registerList; // holding the list of registers
QueueList *doneList; // holding the list of customers served
QueueList *singleQueue; // holding customers in a single virtual queue
double expTimeElapsed; // time elapsed since the beginning of the simulation

// List of commands:
// To open a register
// register open <ID> <secPerItem> <setupTime> <timeElapsed>
// To close register
// register close <ID> <timeElapsed>
// To add a customer
// customer <items> <timeElapsed>


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//helper function to check if the first customer in the queue of a given register is done, but not dequeue it

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


int main() {
  registerList = new RegisterList();
  doneList = new QueueList();
  singleQueue = new QueueList();
  expTimeElapsed = 0;

  // Set mode by the user
  string mode = getMode();

  string line;
  string command;

  cout << "> ";  // Prompt for input
  getline(cin, line);

  while (!cin.eof()) {
    stringstream lineStream(line);
    lineStream >> command;
    if (command == "register") {
      parseRegisterAction(lineStream, mode);
    } else if (command == "customer") {
      addCustomer(lineStream, mode);
    } else {
      cout << "Invalid operation" << endl;
    }
    cout << "> ";  // Prompt for input
    getline(cin, line);
  }

 // ToDo********************************************************************************************************************************************************
  


double max = 0;
double avg = 0;
int count = 0;
double s_d = 0;

Customer* temp = doneList->get_head();
while(temp != nullptr) {
  if(temp->get_departureTime() - temp->get_arrivalTime() > max) {
    max = temp->get_departureTime() - temp->get_arrivalTime();
  }
  avg += temp->get_departureTime() - temp->get_arrivalTime();
  count ++;
  temp = temp->get_next();
}
avg = avg / count;
temp = doneList->get_head();
while(temp != nullptr) {
  s_d += pow(temp->get_departureTime() - temp->get_arrivalTime() - avg, 2);
  temp = temp->get_next();
}

s_d = sqrt(s_d / count);

cout << endl;
cout << "Finished at time " << expTimeElapsed << endl;
cout << "Statistics:" << endl;
cout << "Maximum wait time: " << max << endl;
cout << "Average wait time: " << avg << endl;
cout << "Standard Deviation of wait time: " << s_d << endl;

  return 0;

  
}



string getMode() {
  string mode;
  cout << "Welcome to ECE 244 Grocery Store Queue Simulation!" << endl;
  cout << "Enter \"single\" if you want to simulate a single queue or "
          "\"multiple\" to "
          "simulate multiple queues: \n> ";
  getline(cin, mode);

  if (mode == "single") {
    cout << "Simulating a single queue ..." << endl;
  } else if (mode == "multiple") {
    cout << "Simulating multiple queues ..." << endl;
  }
  return mode;
}

void addCustomer(stringstream &lineStream, string mode) {
  int items;
  double timeElapsed;
  if (!getInt(lineStream, items) || !getDouble(lineStream, timeElapsed)) {
    cout << "Error: too few arguments." << endl;
    return;
  }
  if (foundMoreArgs(lineStream)) {
    cout << "Error: too many arguments." << endl;
    return;
  }
  
  Customer* newCustomer = new Customer(timeElapsed+expTimeElapsed, items);
  expTimeElapsed += timeElapsed;

  // Depending on the mode of the simulation (single or multiple),
  // add the customer to the single queue or to the register with
  // fewest items
  if(mode == "single") {
    //update the single queue
    update_single();
    cout << "A customer entered " << endl;
    if (registerList->get_free_register() == nullptr) {
      cout << "No free registers " << endl;
    }
    singleQueue->enqueue(newCustomer);
    update_single();
  }
  else if(mode == "multiple") {
    update_multiple();
    cout << "A customer entered " << endl;
    cout << "Queued a customer with quickest register " <<  registerList->get_min_items_register()->get_ID() << endl;
    registerList->get_min_items_register()->get_queue_list()->enqueue(newCustomer);
    update_multiple();
  } 
  else {
    cout << "Invalid mode" << endl;
  }
}

void parseRegisterAction(stringstream &lineStream, string mode) {
  string operation;
  lineStream >> operation;
  if (operation == "open") {
    openRegister(lineStream, mode);
  } else if (operation == "close") {
    closeRegister(lineStream, mode);
  } else {
    cout << "Invalid operation" << endl;
  }
}

void openRegister(stringstream &lineStream, string mode) {

  int ID;
  double secPerItem, setupTime, timeElapsed;
  // convert strings to int and double
  if (!getInt(lineStream, ID) || !getDouble(lineStream, secPerItem) ||
      !getDouble(lineStream, setupTime) ||
      !getDouble(lineStream, timeElapsed)) {
    cout << "Error: too few arguments." << endl;
    return;
  }
  if (foundMoreArgs(lineStream)) {
    cout << "Error: too many arguments" << endl;
    return;
  }

   // Check if the register is already open
   // If it's open, print an error message
   // Otherwise, open the register

   // If we were simulating a single queue, 
   // and there were customers in line, then 
   // assign a customer to the new register
    if(registerList->foundRegister(ID)) {
        cout << "Error: register " << ID << " is already open" << endl;
        return;
    }
    Register *newRegister = new Register(ID, secPerItem, setupTime, timeElapsed+expTimeElapsed);
    registerList->enqueue(newRegister);
    expTimeElapsed += timeElapsed;
    cout << "Opened register " << ID << endl;
    //check if the mode is single or multiple
    if (mode == "single")
    {
      //assign the 
        update_single();
    }
    else if (mode == "multiple")
    {
        update_multiple();
    }
    else
    {
        cout << "Invalid mode" << endl;
    }
}

void closeRegister(stringstream &lineStream, string mode) {
  int ID;
  double timeElapsed;
  // convert string to int
  if (!getInt(lineStream, ID) || !getDouble(lineStream, timeElapsed)) {
    cout << "Error: too few arguments." << endl;
    return;
  }
  if (foundMoreArgs(lineStream)) {
    cout << "Error: too many arguments" << endl;
    return;
  }

  // Check if the register is open
  // If it is open dequeue it and free it's memory
  // Otherwise, print an error message 
  if(!(registerList->foundRegister(ID))) {
    cout << "Error: register " << ID << " is not open" << endl;
    return;
  }
  expTimeElapsed += timeElapsed;
  if (mode == "single")
    {
        update_single();
    }
  else if (mode == "multiple")
    {
        update_multiple();
    }
  else{
        cout << "Invalid mode" << endl;
  }

  delete registerList->dequeue(ID);
  cout << "Closed" << "register " << ID << endl;
  return;
}



void update_single() {
  while (singleQueue->get_head() != nullptr){
    Register* empty = registerList->get_free_register();
    if(empty != nullptr) {
      empty->get_queue_list()->enqueue(singleQueue->dequeue());
      cout << "Queued a customer with free register " <<  empty->get_ID() << endl;
    }else{
      break;
    }
  }

  Register* temp = registerList->get_head();
  Register* min = nullptr;
  if (temp == nullptr) {
    return;
  }
  double cur_time = expTimeElapsed;

  while(temp!= nullptr) {
    if(temp->get_queue_list()->get_head() != nullptr) {
      if (cur_time >= temp->calculateDepartTime()) {
        cur_time = temp->calculateDepartTime();
        min = temp;
      }
    }
    temp = temp->get_next();
  }

  if (min != nullptr){
    min->departCustomer(doneList);
    cout << "Departed a customer at register ID " <<  min->get_ID() << " at " << min->get_availableTime() << endl;
    update_single();
  }

  return;
}

void update_multiple() {

  Register* temp = registerList->get_head();
  Register* min = nullptr;
  if (temp == nullptr) {
    return;
  }
  double time = expTimeElapsed;


  while(temp != nullptr) {
    if(temp -> get_queue_list()->get_head() != nullptr) {
      if (time >= temp->calculateDepartTime()) {
        time = temp->calculateDepartTime();
        min = temp;
      }
    }
    temp = temp->get_next();
  }

  if (min == nullptr) {
    return;
  }

  min->departCustomer(doneList);
  cout << "Departed a customer at register ID " <<  min->get_ID() << " at " << min->get_availableTime() << endl;
  update_multiple();
}




bool getInt(stringstream &lineStream, int &iValue) {
  // Reads an int from the command line
  string command;
  lineStream >> command;
  if (lineStream.fail()) {
    return false;
  }
  iValue = stoi(command);
  return true;
}

bool getDouble(stringstream &lineStream, double &dvalue) {
  // Reads a double from the command line
  string command;
  lineStream >> command;
  if (lineStream.fail()) {
    return false;
  }
  dvalue = stod(command);
  return true;
}

bool foundMoreArgs(stringstream &lineStream) {
  string command;
  lineStream >> command;
  if (lineStream.fail()) {
    return false;
  } else {
    return true;
  }
}
