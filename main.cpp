#include "linkedLists.h"
#include "stacks.h"
#include <iostream>

using namespace std;

int main(){
  cout << "Hello World" << endl;  

  linkedList<int> list1;
  list1.print();

  for(int i = 0; i < 10; i++) {
    list1.append(i + 1);
  }
  list1.print();

  list1.removeLast();
  list1.remove(1);
  list1.insert(1, 11);
  list1.set(2, 12);
  list1.print();

  return 0;
}
