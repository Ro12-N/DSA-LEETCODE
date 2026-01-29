class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>adj(26,vector<long long>(26,INT_MAX));
        int n=source.size();
        int m=original.size();
        for(int i=0;i<m;i++){
            int a=original[i]-'a';
            int b=changed[i]-'a';
            adj[a][b]=min(adj[a][b],(long long)cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int a=source[i]-'a';
            int b=source[i]-'a';
            if(a==b) continue;
            if(adj[a][b]==INT_MAX) return -1;
            ans+=adj[a][b];
        }
        return ans;
    }
};
// Time Complexity: O(26^3 + n) where n is the length of the source string.
// Space Complexity: O(1)
