/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=INT_MIN;
        int level=1;
        int res=0;
        while(!q.empty()){
            int sum=0;
            int n=q.size();
            while(n--){
               TreeNode* f=q.front();
               q.pop();
               sum+=f->val;
               if(f->left) q.push(f->left);
               if(f->right) q.push(f->right);

            }
            if(ans<sum){
                ans=sum;
                res=level;
            }
            level++;
        }
        return res;
    }
};
// Time Complexity: O(N) where N is the number of nodes in the binary tree.
// Space Complexity: O(M) where M is the maximum number of nodes at any level in the binary tree.