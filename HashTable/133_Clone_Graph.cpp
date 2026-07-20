// LeetCode 133 - Clone Graph

// Difficulty: Medium

// Approach:

// 1. Use Depth First Search (DFS) or Breadth First Search (BFS) to traverse the graph.
// 2. Maintain a Hash Map that maps each original node to its cloned node.
// 3. If a node has already been cloned, return the cloned node directly.
// 4. Otherwise:

//    * Create a clone of the current node.
//    * Store it in the hash map.
// 5. Recursively (or iteratively) clone all neighboring nodes.
// 6. Add the cloned neighbors to the current cloned node.
// 7. Return the cloned starting node.

// Time Complexity: O(V + E)
// Space Complexity: O(V)

// * V = number of vertices (nodes).
// * E = number of edges.
// * The hash map stores one clone for each node.



class Solution {
public:

    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {

        if(node == NULL)
            return NULL;

        if(mp.find(node) != mp.end())
            return mp[node];

        Node* clone = new Node(node->val);

        mp[node] = clone;

        for(Node* neighbor : node->neighbors) {

            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};