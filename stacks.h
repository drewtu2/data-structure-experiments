#ifndef STACKS_H
#define STACKS_H

#include "linkedlists.h"

#include <iostream>

// A linked list that follows the "Last In First Out" principle. 

template <class T> class stack{

public:
 linkedList<T> body;

 stack(); 
 void push(T value);
 T pop();
 void pip();

};

template <class T> stack<T>::stack(){
  
}

// Adds a value to the top of the stack
template <class T> void stack<T>::push(T value) {
  body.append(value);
}

// Deletes the value at the top of the stack
template <class T> T stack<T>::pop() {
  T temp = body.get(body.length);
  body.removeLast();
  return temp;
}

// Displays the contents of the top of the stack
template <class T> void stack<T>::pip() {
  std::cout<< body.get(body.length) << std::endl;
}

#endif
