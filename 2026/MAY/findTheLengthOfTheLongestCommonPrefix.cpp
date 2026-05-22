class Solution {
public:
struct trieNode{
     trieNode* v[10]={NULL}; 
};
void insert(trieNode* & root,int a){
    string s=to_string(a);
    trieNode* curr=root;
    for(auto i:s){
        int n=i-'0';
       if(!curr->v[n]){
           curr->v[n]=new trieNode();
       }
       curr=curr->v[n];
    }
}
int solve(trieNode* root,int a){
        string s=to_string(a);
    trieNode* curr=root;
    int len=0;
    for(auto i:s){
        int n=i-'0';
       if(!curr->v[n]){
           break;
       }
       len++;
       curr=curr->v[n];
    }
    return len;
}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trieNode* root =new trieNode();
        for(auto i:arr1){
            insert(root,i);
        }
        int ans=0;
        for(auto i:arr2){
            int curr=solve(root,i);
            ans=max(ans,curr);
        }
        return ans;
    }
};
// TC : O(n*m) where n is the size of the input arrays arr1 and arr2 and m is the maximum number of digits in the elements of the input arrays
// SC : O(n*m) where n is the size of the input array arr1 and m is the maximum number of digits in the elements of the input array arr1 as we are using a trie data structure to store the elements of arr1