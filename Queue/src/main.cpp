#include "queue.h"
#include <iostream>

int main(){

    Queue<int> intQueue;


    intQueue.push(5);
    intQueue.push(10);
    intQueue.push(15);

    Queue<int> q1 {2,3,4};
    Queue<int> q2 {1,2,3};

    
/*
    std::cout << "Size of queue: " << intQueue.size_q() << std::endl;

   while (!intQueue.empty_q()) {
        std::cout << "font element: " << intQueue.front_q() << std::endl;
        intQueue.pop();
    }*/
    
  if( q1 != q2)
   {
    std::cout << "q1 < q2" <<std::endl;
   }
   else
   {
   std::cout <<"Noo"<<std::endl;
   }

    return 0;

}
