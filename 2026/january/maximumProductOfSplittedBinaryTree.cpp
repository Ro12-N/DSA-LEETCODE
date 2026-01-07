class Solution {
public:
    long long tsum = 0;
    long long ans = 0;
    const int mod = 1e9 + 7;

    long long maxip(TreeNode* root) {
        if (!root) return 0;

        long long l = maxip(root->left);
        long long r = maxip(root->right);

        long long currsum = root->val + l + r;
        long long remain = tsum - currsum;

        ans = max(ans, currsum * remain);
        return currsum;
    }

    int maxProduct(TreeNode* root) {
        tsum = maxip(root);
        maxip(root);
        return ans % mod;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree.
// Space Complexity: O(H) where H is the height of the binary tree due to recursion