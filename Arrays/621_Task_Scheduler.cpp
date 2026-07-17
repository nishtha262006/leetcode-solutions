// LeetCode 621 - Task Scheduler

// Difficulty: Medium

// Approach:

// 1. Count the frequency of each task.
// 2. Find the maximum frequency among all tasks.
// 3. Count how many tasks have this maximum frequency.
// 4. Compute the minimum intervals required using the scheduling formula:

//    * `(maxFreq - 1) × (n + 1) + countMaxFreq`
// 5. The answer is the maximum of:

//    * The total number of tasks.
//    * The calculated minimum intervals.
// 6. Return the result.

// Time Complexity: O(n)
// Space Complexity: O(1)

// * n = number of tasks.
// * Since there are only 26 uppercase English letters, the extra space is constant.



class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for(char task : tasks)
            freq[task - 'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());

        int maxCount = 0;

        for(int f : freq) {
            if(f == maxFreq)
                maxCount++;
        }

        return max((int)tasks.size(),
                   (maxFreq - 1) * (n + 1) + maxCount);
    }
};