// LeetCode 215 - Kth Largest Element in an Array
// Difficulty: Medium

// Approach:
// 1. Use a Min Heap of size k.
// 2. Traverse all elements in the array.
// 3. Push each element into the Min Heap.
// 4. If the heap size exceeds k:
//    - Remove the smallest element.
// 5. After processing all elements:
//    - The top of the Min Heap is the kth largest element.
// 6. Return the top element.

// Time Complexity: O(n log k)
// Space Complexity: O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> minHeap;//create minheap

        for(int num : nums) {//traverse the array

            minHeap.push(num);//insert element

            if(minHeap.size() > k) {//only want k elements in the heap
                minHeap.pop();//remove smallest element
            }
        }

        return minHeap.top();//return answer
    }
};