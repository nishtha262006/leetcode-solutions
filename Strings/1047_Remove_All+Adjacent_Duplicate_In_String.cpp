// LeetCode 1047 - Remove All Adjacent Duplicates In String

// Difficulty: Easy

// Approach:

// 1. Use a stack (or string as a stack) to process characters.
// 2. Traverse the string from left to right.
// 3. For each character:

//    * If the stack is not empty and the top character matches the current character, remove the top character.
//    * Otherwise, push the current character onto the stack.
// 4. Continue until all characters are processed.
// 5. The remaining characters in the stack form the final string.
// 6. Return the resulting string.

// Time Complexity: O(n)
// Space Complexity: O(n)

// * In the worst case, all characters are stored in the stack.




class Solution {
public:
    string removeDuplicates(string s) {
        

        stack<char>st;// create stack

        for(char ch:s){// visit every element
            if(!st.empty() && st.top() == ch){//duplicate found?
                st.pop();//remove duplicate
            }
            else{
                st.push(ch);//other store current character
            }
        }
        string result ="";

        while(!st.empty()){
            result+=st.top();// build answer
            st.pop();
        }
        reverse(result.begin(), result.end());// reverse the string

        return result;
    }
};