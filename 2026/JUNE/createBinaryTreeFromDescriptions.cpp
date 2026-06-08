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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>st;
        for(auto i:descriptions){
            int p=i[0];
            int c=i[1];
            int l=i[2];
            st.insert(c);
            if(!mp.count(p)){
                mp[p]=new TreeNode(p);
            }
            if(!mp.count(c)){
                mp[c]=new TreeNode(c);
            }

            if(l==1){
                mp[p]->left=mp[c];
            }else mp[p]->right=mp[c];
        }
        for(auto &[v,node]:mp){
             if(!st.count(v)) return node;
        }
        return NULL;
    }
};
// TimeComplexity: O(N);
// SpaceComplexity: O(N);