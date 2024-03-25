#include <iostream>
#include "Longest_valid.h"

int main() {
    Longest_parentheses  s;
    std::string input;
	std::cout << "input the text here` ";
	std::cin >> input;
    int result = s.longestValidParentheses(input);
    std::cout << "Longest valid parentheses length: " << result << std::endl;
    return 0;
}

