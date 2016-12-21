#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct node {
  int   value;
  node  *next;
};

class linkedList {

 public:
  node  *HEAD;
  node  *conductor;
  node  *TAIL;
  int   length;

  linkedList();
  linkedList(int value);
  
  void  append(int value);
  int   get(int index);
  void  set(int index, int value);
  void  insert(int index, int value);
  void  removeLast();
  void  remove(int index);
  void  print();
  void  printStatus();
 private:
  node  *getNode(int index);
};


#endif
