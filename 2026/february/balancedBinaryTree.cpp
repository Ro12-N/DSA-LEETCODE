class Solution {
public:
int solve(TreeNode* root){
    if(!root) return 0;
    int l=solve(root->left);
    if(l==-1) return -1;
    int r=solve(root->right);
    if(r==-1) return -1;
    if(abs(l-r)>1) return -1;
    return 1+max(l,r);
}
    bool isBalanced(TreeNode* root) {
        return solve(root)!=-1;
    }
};
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(h) where h is the height of the tree due to recursive stack space