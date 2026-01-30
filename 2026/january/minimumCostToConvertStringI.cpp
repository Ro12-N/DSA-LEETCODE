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


class Solution {
public:
void dijkstra(char s,unordered_map<char,vector<pair<char,int>>>&mp,vector<vector<long long>>&adj){
    priority_queue<pair<int,char>,vector<pair<int,char>>,greater<>>pq;
    pq.push({0,s});
    adj[s-'a'][s-'a']=0;
    while(!pq.empty()){
        int d=pq.top().first;
        char ch=pq.top().second;
        pq.pop();
        for(auto nt:mp[ch]){
            char nxt=nt.first;
            int dist=nt.second;
            if(d+dist<adj[s-'a'][nxt-'a']){
                adj[s-'a'][nxt-'a']=d+dist;
                pq.push({d+dist,nxt});
            }
        }
    }
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>adj(26,vector<long long>(26,INT_MAX));
        unordered_map<char,vector<pair<char,int>>>mp;
        int n=original.size();
        for(int i=0;i<n;i++){
            mp[original[i]].push_back({changed[i],cost[i]});
        }
        int m=source.size();
        for(int i=0;i<26;i++){
            dijkstra(i+'a',mp,adj);
        }

        long long ans=0;
        for(int i=0;i<m;i++){
            int a=source[i]-'a';
            int b=target[i]-'a';
            if(a==b) continue;
            if(adj[a][b]==INT_MAX) return -1;
            ans+=adj[a][b];
        }
        return ans;
    }
};
// Time Complexity: O(26 * (E + V) log V + n) where E is the number of edges and V is the number of vertices in the graph.
// Space Complexity: O(E + V)
