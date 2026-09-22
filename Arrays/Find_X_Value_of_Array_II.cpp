class Solution {
public:

    struct Node {
        int prod = 1;
        int cnt[5] = {0};
    };

    int k;
    vector<Node> tree;

    Node merge(Node left, Node right) {
        Node res;

        // Product of the complete segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside left
        for (int i = 0; i < k; i++) {
            res.cnt[i] += left.cnt[i];
        }

        // Prefixes that cross from left into right
        for (int i = 0; i < k; i++) {
            int newRemainder = (left.prod * i) % k;
            res.cnt[newRemainder] += right.cnt[i];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {
            int x = nums[l] % k;

            tree[node].prod = x;
            tree[node].cnt[x] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, 2 * node + 1, l, mid);
        build(nums, 2 * node + 2, mid + 1, r);

        tree[node] = merge(
            tree[2 * node + 1],
            tree[2 * node + 2]
        );
    }

    void update(int node, int l, int r, int index, int value) {

        if (l == r) {
            int x = value % k;

            tree[node] = Node();
            tree[node].prod = x;
            tree[node].cnt[x] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(2 * node + 1, l, mid, index, value);
        } else {
            update(2 * node + 2, mid + 1, r, index, value);
        }

        tree[node] = merge(
            tree[2 * node + 1],
            tree[2 * node + 2]
        );
    }

    Node query(int node, int l, int r, int ql, int qr) {

        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(2 * node + 1, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(2 * node + 2, mid + 1, r, ql, qr);
        }

        Node left = query(
            2 * node + 1, l, mid, ql, qr
        );

        Node right = query(
            2 * node + 2, mid + 1, r, ql, qr
        );

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {

        k = K;

        int n = nums.size();

        tree.resize(4 * n);

        build(nums, 0, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(
                0, 0, n - 1,
                index, value
            );

            // Query [start ... n-1]
            Node res = query(
                0, 0, n - 1,
                start, n - 1
            );

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};