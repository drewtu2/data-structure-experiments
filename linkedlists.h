#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>


template<class T> class linkedList{

  struct node {
    T   value;
    node  *next;
  };
 
 public:
  node  *HEAD;
  node  *conductor;
  node  *TAIL;
  int   length;

  linkedList();
  linkedList(T value);
  
  void  append(T value);
  T   get(int index);
  void  set(int index, T value);
  void  insert(int index, T value);
  void  removeLast();
  void  remove(int index);
  void  print();
  void  printStatus();
 private:
  node  *getNode(int index);
};

// linkedList<T>::linkedList(): Default constructor for the linked list class
// Initializes a single node whose value equals 0 and whose next point to null
template <class T> linkedList<T>::linkedList() {
  //Create the empty linkedList
  length  = 0;
}

// linkedList<T>::linkedList(T value): Constructor for the linkedlist class that
// sets the value of head equal to value and the next to null
template <class T> linkedList<T>::linkedList(T value) {
  HEAD        = new node;
  HEAD->value = value;
  HEAD->next  = 0;
  TAIL        = HEAD;
  conductor   = HEAD;
  length      = 1;
}

// linkedList<T>::append(T value): Appends a new node to the list whose value is
// equal to the given value.
template <class T> void linkedList<T>::append(T value) {
  if (length == 0) {
    HEAD        = new node;
    HEAD->value = value;
    HEAD->next  = 0;
    TAIL        = HEAD;
    conductor   = HEAD;
    length      = 1;
  } else {
    TAIL->next = new node;
    TAIL = TAIL->next;
    TAIL->value = value;
    TAIL->next = 0;
    length++;
  }
}

//*linkedList<T>::getNode(int index): Returns the address of the node at the given
//index
template <class T> typename linkedList<T>::node *linkedList<T>::getNode(int index) {
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

//linkedlist<T>::get(T index) returns the value of the list at a given index
template <class T> T linkedList<T>::get(int index) {
  node *temp = getNode(index);
  return temp->value;
}

//linkedlist<T>::set(int index, T value) sets the value of the node  at a given
//index to the given value
template <class T> void linkedList<T>::set(int index, T value) {
  node *temp = getNode(index);
  temp->value = value;
}

//linkedList<T>::insert(int index, T value): inserts the given value at the node at
//a given index. If the given index is greater than the length of the list, the
//given value is appended to the end of the list.
template <class T> void linkedList<T>::insert(int index, T value) {
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
//linkedList<T>::removeLast() removes the last node in the list
template <class T> void linkedList<T>::removeLast(){
  conductor = HEAD;
  while (conductor != TAIL) {
    conductor = conductor->next;
  }
  conductor->next = 0;
  delete TAIL;
  TAIL = conductor;
  length--;
}

//linkedList<T>::remove(int index): removes the node at a given index;
template <class T> void linkedList<T>::remove(int index) {
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

//linkedlist<T>::print() Prints the contents of the list
template <class T> void linkedList<T>::print() {
  if(length == 0) {
    std::cout << "Empty List" << std::endl;
  } else {
    conductor = HEAD;
    while (conductor != TAIL) {
      std::cout << conductor->value << std::endl;
      conductor = conductor->next;
    }
    std::cout << TAIL->value << std::endl;
  }
}

template <class T> void linkedList<T>::printStatus() {
  std::cout << "HEAD: \t\t" << HEAD << std::endl;
  std::cout << "Conductor: \t" << conductor << std::endl;
  std::cout << "TAIL: \t\t" << TAIL << std::endl << std::endl;
};

#endif
