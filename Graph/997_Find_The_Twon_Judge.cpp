// LeetCode 997 - Find the Town Judge

// Difficulty: Easy

// Approach:

// 1. Use an indegree and outdegree count for each person.
// 2. Traverse the trust relationships:

//    * Increase the indegree of the trusted person.
//    * Increase the outdegree of the person who trusts someone.
// 3. After processing all relationships:

//    * The Town Judge should have:

//      * indegree = n - 1 (trusted by everyone else)
//      * outdegree = 0 (trusts no one)
// 4. Return the label of the Town Judge.
// 5. If no such person exists, return -1.

// Time Complexity: O(n + m)
// Space Complexity: O(n)

// * n = number of people.
// * m = number of trust relationships.




class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        for(auto relation : trust) {

            int a = relation[0];
            int b = relation[1];

            outdegree[a]++;
            indegree[b]++;
        }

        for(int i = 1; i <= n; i++) {

            if(indegree[i] == n - 1 &&
               outdegree[i] == 0) {

                return i;
            }
        }

        return -1;
    }
};