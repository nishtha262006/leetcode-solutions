/*
LeetCode 225 - Implement Stack using Queues
Difficulty: Easy

Approach:
1. Use a single queue to simulate stack operations.
2. For push(x):
   - Push the new element into the queue.
   - Rotate all previous elements to the back of the queue.
   - This ensures the newest element stays at the front.
3. For pop():
   - Remove and return the front element.
4. For top():
   - Return the front element.
5. For empty():
   - Check if the queue is empty.

Time Complexity:
- push(): O(n)
- pop(): O(1)
- top(): O(1)
- empty(): O(1)

Space Complexity: O(n)
*/

class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {
        q.push(x);

        int size = q.size();

        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};