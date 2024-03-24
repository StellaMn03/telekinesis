#include "stack.h"
#include <iostream>

int main(){
    Stack<int> intStack;
    
    Stack<int> stack1 {1, 2, 3};
    Stack<int> stack2 {1, 2, 4};
    intStack.push(5);
    intStack.push(10);
    intStack.push(15);
    std::cout << "Size of stack: " << intStack.size_s() << std::endl;
    while (!intStack.empty_s()) {
        std::cout << "Top element: " << intStack.top() << std::endl;
        intStack.pop();
    }

    if (stack1 > stack2)
        std::cout << "stack1 is less than stack2" << std::endl;
        
    return 0;

}
