// LeetCode 207 - Course Schedule

// Difficulty: Medium

// Approach:

// 1. Represent the courses and prerequisites as a directed graph using an adjacency list.
// 2. Compute the indegree (number of incoming edges) for each course.
// 3. Add all courses with indegree `0` to a queue.
// 4. Perform Kahn's Algorithm (Topological Sort):

//    * Remove a course from the queue.
//    * Mark it as completed.
//    * Decrease the indegree of all its neighboring courses.
//    * If a neighbor's indegree becomes `0`, add it to the queue.
// 5. Count the number of completed courses.
// 6. If all courses are completed, return `true`; otherwise, return `false`.

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// * V = number of courses.
// * E = number of prerequisite relationships.


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while(!q.empty()) {

            int course = q.front();
            q.pop();

            count++;

            for(int next : adj[course]) {

                indegree[next]--;

                if(indegree[next] == 0)
                    q.push(next);
            }
        }

        return count == numCourses;
    }
};