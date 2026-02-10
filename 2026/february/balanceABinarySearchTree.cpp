class Solution {
public:
void dfs(TreeNode* root,vector<int>&ans){
    if(!root) return ;
    dfs(root->left,ans);
    ans.push_back(root->val);
    dfs(root->right,ans);
}

TreeNode* solve(vector<int>&ans,int s,int e){
    if(s>e) return NULL;
    int mid=s+(e-s)/2;
    TreeNode* root=new TreeNode(ans[mid]);
    root->left=solve(ans,s,mid-1);
    root->right=solve(ans,mid+1,e);
    return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        dfs(root,ans);
        return solve(ans,0,ans.size()-1);
    }
};
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(n) where n is the number of nodes in the tree due to