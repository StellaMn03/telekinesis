#include "ForwardList.h"
#include<iostream>
int main() {
    
    Forward_list<int> myList;
    // 1 2 3
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.display();
    // -1 0 1 2 3
    myList.push_front(0);
    myList.push_front(-1);
    //  -1 0 1
    myList.pop_back();
    myList.pop_back();
    // 0 1
    myList.pop_front();
    // 0 10 1
    myList.insert(2, 10);
    myList.remove(2);
    myList.empty();
    myList.clear();
    myList.empty();

    return 0;
}

