#include "linkedLists.h"
#include "stacks.h"
#include "queue.h"
#include <iostream>

using namespace std;

void prompt();

int main(){
  int sentinel = 0;
  int temp_value;
  int temp_index;
  linkedList<int> list1;
  while (sentinel != -1) {
    prompt();
    cin >> sentinel;

    switch(sentinel){
      case 1:
        cout << "Append: ";
        cin >> temp_value;
        list1.append(temp_value);
        break;
      case 2:
        cout << "Insert: " << endl;
        cout << "Index: ";
        cin >> temp_index;
        cout << endl << "Value: ";
        cin >> temp_value;
        list1.insert(temp_index, temp_value);
        break;
      case 3:
        cout << "Remove: " << endl;
        cout << "Index: ";
        cin >> temp_index;
        list1.remove(temp_index);
        break;
      case 4:
        cout << "Remove Last" << endl;
        list1.removeLast();
        break;
      case 5:
        cout << "Print List" << endl;
        list1.print();
        cout << endl;
        break;
      case 6:
        cout << "Get (index): ";
        cin >> temp_index;
        cout << endl << list1.get(temp_index) << endl;
        break;
      case 7:
        cout << "Set: " << endl;
        cout << "Index: " << endl;
        cin >> temp_index;
        cout << endl << "Value: ";
        cin >> temp_value;
        break;
      case 8:
        cout << "Length: " << list1.length << endl;
        break;
      default:
        sentinel = -1;
        break;
    }
  }
  return 0;
}

void prompt() {
  cout << "LinkedList" << endl;
  cout << "\t 1 to append to linkedList" << endl;
  cout << "\t 2 to insert to linkedList" << endl;
  cout << "\t 3 to remove (index) to linkedList" << endl;
  cout << "\t 4 to remove last from linkedList" << endl;
  cout << "\t 5 to print linkedList" << endl;
  cout << "\t 6 to get (index) from linkedList" << endl;
  cout << "\t 7 to set (index) of linkedList" << endl;
  cout << "\t 8 to print length of list" << endl;
  cout << "\t -1 to exit" << endl;
}
