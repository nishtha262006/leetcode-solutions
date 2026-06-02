//
LeetCode 32 - Longest Valid Parentheses
Difficulty: Hard

Approach:
1. Use a stack to store indices.
2. Push -1 initially as a base index.
3. For each character:
   - If it is '(', push its index.
   - If it is ')', pop from the stack.
4. After popping:
   - If the stack becomes empty, push the current index.
   - Otherwise, calculate the length of the current valid substring
     as (current index - stack top).
5. Keep track of the maximum length found.

Time Complexity: O(n)
Space Complexity: O(n)


class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int>st;//create a stack
        st.push(-1);//imaginary baoundary before string

        int maxLength=0;// stores longets valid length found
        for(int i =0;i<s.size();i++){//visit each character
            if(s[i] =='('){
            st.push(i);// when there is a open bracket push it onto the stack
        }
        else{
            st.pop();// if closing bracket pop it from stack
            if(st.empty()){//if stack is empty
                st.push(i);// make it a new boundary
            }
            else{
                maxLength= max(maxLength,i-st.top());//length
            }
        }
    }
    return maxLength;// return the final answer asit  denotes the longest valid parentheses substring
    }
};