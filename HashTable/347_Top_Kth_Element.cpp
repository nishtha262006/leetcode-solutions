// LeetCode 347 - Top K Frequent Elements

// Difficulty: Medium

// Approach:

// 1. Use a hash map to count the frequency of each element.
// 2. Store each element along with its frequency.
// 3. Use a max heap (priority queue) to keep elements ordered by frequency.
// 4. Remove the top k elements from the heap.
// 5. Store these elements in the result vector.
// 6. Return the result.

// Time Complexity: O(n log n)
// Space Complexity: O(n)

// * n = number of elements in the array.
// * The hash map stores frequencies, and the heap orders elements by frequency.




class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequency
        for(int num : nums) {
            freq[num]++;
        }

        // Min Heap (frequency, number)
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;

        // Push into heap
        for(auto it : freq) {

            minHeap.push({it.second, it.first});

            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> ans;

        while(!minHeap.empty()) {

            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};