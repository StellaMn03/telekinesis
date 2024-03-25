#ifndef VALID_PARENTHESES_H
#define VALID_PARENTHESES_H

#include <string>
#include <stack>

class valid_par {
private:
    std::string input;

public:
    void setInput(const std::string& s);
    bool isValid();
};

#include "validParentheses.hpp"

#endif // VALID_PARENTHESES_H

