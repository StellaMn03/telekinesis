#include "Longest_valid.h"
#include <stack>

int Longest_parentheses::longestValidParentheses(std::string s) {
    std::stack<int> st;
    int last_invalid = -1;
    int max_length = 0;
        
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } 
		else if (st.empty())
		{ //    s[i] == ')'
            last_invalid = i;
        }
	    else 
		{ //   !st.empty() s[i] == ')'    
            st.pop();
            if (st.empty())         
		    {
               max_length = (max_length < (i - last_invalid)) ? (i - last_invalid) : max_length;
            }
		    else
		    {
               max_length = (max_length < (i - st.top())) ? (i - st.top()) : max_length;
            }
        }
    }
    return max_length;
}

