// LeetCode 2058 - Find the Minimum and Maximum Number of Nodes Between Critical Points

// Difficulty: Medium

// Approach
// A node is a critical point if it is either:
// A local maximum: prev < curr > next
// A local minimum: prev > curr < next
// Traverse the linked list while keeping track of:
// prev → previous node
// curr → current node
// pos → current position
// Whenever we find a critical point:
// If it is the first critical point, store its position.
// Otherwise:
// The distance from the previous critical point gives a candidate for the minimum distance.
// The distance from the first critical point gives the maximum distance.
// If fewer than 2 critical points exist, return {-1, -1}.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        int pos = 1;
        while(head->next !=nullptr && head->next->next !=nullptr){
            int prev = head->val;
            int curr = head->next->val;
            int next = head->next->next->val;

            if((curr>prev && curr>next)||(curr<prev && curr<next)){

                int currentPos = pos+1;

                if(first ==-1){
                    first = currentPos;
                    last = currentPos;
                }
                else{
                    minDist = min(minDist, currentPos - last);

                    last = currentPos;
                }
            }
            head = head ->next;
            pos++;
        }
        if(first ==-1 || first ==last){
            return{-1, -1};
        }
        int maxDist = last - first;
        return {minDist , maxDist};
    }
};