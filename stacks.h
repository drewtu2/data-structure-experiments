#ifndef STACKS_H
#define STACKS_H

#include "linkedlists.h"

#include <iostream>

// A linked list that follows the "Last In First Out" principle. 

template <class T> class stack{

public:
 linkedList<T> body;

 void push(T value);
 void pop();
 void pip();

};


// Adds a value to the top of the stack
template <class T> void stack<T>::push(T value) {
  body.append(value);
}

// Deletes the value at the top of the stack
template <class T> void stack<T>::pop() {
  body.removeLast();
}

// Displays the contents of the top of the stack
template <class T> void stack<T>::pip() {
  std::cout<< body.get(body.length) << std::endl;
}

#endif
