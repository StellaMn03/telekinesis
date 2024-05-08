#include "vector_class.h"
#include <iostream>

int main() {

    Vector<int> vec1;
    Vector<int> vec2(5);
    Vector<int> vec3(3, 42);
    Vector<int> vec4(vec3);
    Vector<int> vec5 = vec2;
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);
    vec1.pop_back();
    vec1.push_front(8);
   

    Vector<int> vec_1;
	vec_1.push_back(1);
	vec_1.push_back(2);
	vec_1.push_back(7);
	vec_1.push_back(9);

	Vector<int> vec_2;
	vec_2.push_back(1);
	vec_2.push_back(2);
	vec_2.push_back(4);
   /* vec2.clear();
    if (vec2.empty()) {
         std::cout << "vec2 is empty\n";
    } else {
         std::cout << "vec2 is not empty\n";
    }
    if (!vec1.empty()) {
        std::cout << vec1.front() << "\n";
	    std::cout << vec1.back()  << "\n";
     	std::cout << vec1.at(1) << "\n";
    }
    vec1.resize(5, 99);
    vec1.remove(2);
    vec1.insert(2, 42);*/

     if (vec_1 > vec_2) {
        std::cout << "vec1 is greater than vec2" << std::endl;
    } else {
        std::cout << "vec1 is not greater than vec2" << std::endl;
    }
   // vec1.print();

    return 0;
}

