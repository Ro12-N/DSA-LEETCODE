class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        unordered_set<int>st;
        q.push(0);
        int l=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int idx=q.front();
                st.insert(idx);
                q.pop();
                if(idx==n-1) return l;
                if(idx-1>=0&& !st.count(idx-1)) q.push(idx-1);
                if(idx+1<n&&!st.count(idx+1)) q.push(idx+1);
                for(auto j:mp[arr[idx]]){
                    if(j!=idx&& !st.count(j)) q.push(j);
                }
                 mp[arr[idx]].clear();
            }
            l++;
        }
        return 0;
    }
};
// TC : O(n) where n is the size of the input array arr
// SC : O(n) as we are using a queue to store the indices to be processed