#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlists.h"

template<class T> class queue {

public:
 linkedList<T> body;

 void enqueue(T value);
 T dequeue();
 void peek();

};

// Adds a value to the end of the queue
template <class T> void queue<T>::enqueue(T value) {
  body.append(value); 
}

// Removes the first value from the front of the queue
template <class T> T queue<T>::dequeue() {
  T temp = body.get(0);
  body.remove(0);
  return temp;
}

// Displays the first value of the queue
template <class T> void queue<T>::peek() {
  std::cout<<body.get(0) << std::endl;
}

#endif
