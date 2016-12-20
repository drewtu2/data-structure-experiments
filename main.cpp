#include "linkedLists.h"
#include <iostream>

using namespace std;

int main(){
  cout << "Hello World" << endl;  

  linkedList list1;
  list1.print();
  list1.append(1);
  list1.append(2);
  list1.print();
  cout << "Length: " << list1.length << endl;
  cout << "Index 1: " << list1.get(1) << endl;
  cout << "Set Index 1 to 5" << endl;
  list1.set(1, 5);
  cout << "Index 1: " << list1.get(1) << endl;

  return 0;
}
