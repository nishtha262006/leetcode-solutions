// LeetCode 2029 - Stone Game IX

// Difficulty: Medium

// Approach

// The trick is to ignore the actual values and only look at their remainder when divided by 3. We count:

// cnt[0] → numbers divisible by 3
// cnt[1] → numbers with remainder 1
// cnt[2] → numbers with remainder 2

// There is an even simpler condition:

// If cnt[0] is even → Alice wins only when both cnt[1] and cnt[2] are present.
// If cnt[0] is odd → Alice wins when abs(cnt[1] - cnt[2]) > 2.


class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] ={0};
        for(int x:stones){
            cnt[x%3]++;
        }
        if(cnt[0] %2 ==0){
            return cnt[1]>0 && cnt[2] >0;
        }
        return abs(cnt[1]- cnt[2])>2;
    }
};