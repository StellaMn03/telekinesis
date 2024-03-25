#ifndef VALID_PARENTHESES_HPP
#define VALID_PARENTHESES_HPP

#include "validParentheses.h"

void valid_par::setInput(const std::string& s) {
    input = s;
}

bool valid_par::isValid() {
    std::stack<char> st;
    for(char c : input) {
        if(c == '(' || c == '{' || c == '[')
            st.push(c);
        else if(c == ')') {
            if(st.empty() || st.top() != '(')
                return false;
            else
                st.pop();
        }
        else if(c == '}') {
            if(st.empty() || st.top() != '{')
                return false;
            else
                st.pop();
        }
        else if(c == ']') {
            if(st.empty() || st.top() != '[')
                return false;
            else
                st.pop();
        }
        else
            return false;
    }
    if(!st.empty())
        return false;
    return true;
}

#endif
