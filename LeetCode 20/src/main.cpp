#include <iostream>
#include "validParentheses.h"

int main() {
    valid_par s;
    std::string input;
    std::cout << "Enter a string containing brackets` ";
    std::cin >> input;
    s.setInput(input);
    if(s.isValid())
	{
        std::cout << "Valid string" << std::endl;
	}
    else
	{
        std::cout << "Invalid string" << std::endl;
    }
    return 0;
}

