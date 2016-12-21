#include "linkedlists.h"

// linkedList::linkedList(): Default constructor for the linked list class
// Initializes a single node whose value equals 0 and whose next point to null
linkedList::linkedList() {
  HEAD        = new node;
  HEAD->value = 0;
  HEAD->next  = 0;
  TAIL        = HEAD;
  conductor   = HEAD;
  length      = 1;
}

// linkedList::linkedList(int value): Constructor for the linkedlist class that
// sets the value of head equal to value and the next to null
linkedList::linkedList(int value) {
  HEAD        = new node;
  HEAD->value = value;
  HEAD->next  = 0;
  TAIL        = HEAD;
  conductor   = HEAD;
  length      = 1;
}

// linkedList::append(int value): Appends a new node to the list whose value is
// equal to the given value. 
void linkedList::append(int value) {
  TAIL->next = new node;
  TAIL = TAIL->next;
  TAIL->value = value;
  TAIL->next = 0;
  length++;
}

//*linkedList::getNode(int index): Returns the address of the node at the given
//index
node *linkedList::getNode(int index) {
  conductor = HEAD;
  
  if (index >= length) {
    // We asked for something that doesn't exist
  }
  int i = 0; 
  while(i != index) {  
    conductor = conductor->next;
    i++;
  }
  
  return conductor;
}

//linkedlist::get(int index) returns the value of the list at a given index
int linkedList::get(int index) {
  node *temp = getNode(index);
  return temp->value;
}

//linkedlist::set(in index, int value) sets the value of the node  at a given 
//index to the given value
void linkedList::set(int index, int value) {
  node *temp = getNode(index);
  temp->value = value;
}

//linkedList::insert(int index, value): inserts the given value at the node at 
//a given index. If the given index is greater than the length of the list, the 
//given value is appended to the end of the list.
void linkedList::insert(int index, int value) {
  if (index >= length - 1) {
    append(value);
  }
  else if (index == 0) {
    node *nodeToInsert = new node;
    nodeToInsert->value = value;
    nodeToInsert->next = HEAD;
    HEAD = nodeToInsert;
    length++;
  } 
  else {
    node *nodeToInsert = new node;
    node *nodePriorToInsert = getNode(index - 1);
    
    nodeToInsert->value = value;
    nodeToInsert->next = nodePriorToInsert->next;
    nodePriorToInsert->next = nodeToInsert;

    length++;
  }
}
//linkedList::removeLast() removes the last node in the list
void linkedList::removeLast(){
  conductor = HEAD;
  while (conductor != TAIL) {
    conductor = conductor->next;
  }
  conductor->next = 0;
  delete TAIL;
  TAIL = conductor;
  length--;
}

//linkedList::remove(int index): removes the node at a given index;
void linkedList::remove(int index) {
  if (index > length - 1) {
    // DO nothing (does not exist)
  } 
  else if (index == length - 1) {
    removeLast();
  }
  else if(index == 0){
    conductor = HEAD->next;
    delete      HEAD;
    HEAD      = conductor;
  } 
  else {
    conductor = getNode(index - 1);
    node *toRemove = conductor->next;
    conductor->next = toRemove->next;
    delete toRemove;
    length--;
  }
}

//linkedlist::print() Prints the contents of the list
void linkedList::print() {
  conductor = HEAD;
  while (conductor != TAIL) {
    std::cout << conductor->value << std::endl;
    conductor = conductor->next;
  }
  std::cout << TAIL->value << std::endl;
}

void linkedList::printStatus() {
  std::cout << "HEAD: \t\t" << HEAD << std::endl;
  std::cout << "Conductor: \t" << conductor << std::endl;
  std::cout << "TAIL: \t\t" << TAIL << std::endl << std::endl;
};
