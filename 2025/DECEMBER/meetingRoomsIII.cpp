class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        priority_queue<int,vector<int>,greater<>>st;
        for(int i=0;i<n;i++) st.push(i);
        vector<int>used(n,0);
         for(auto i:meetings){
            int s=i[0];
            int e=i[1];
            while(!pq.empty() &&pq.top().first<=s){
                st.push(pq.top().second);
                pq.pop();
            }
            if(st.empty()){
                auto [v,r]=pq.top();
                   pq.pop();
                   pq.push({v+(e-s) ,r});
                used[r]+=1;
                
                
            }
            else{
            long long curr=st.top();
            st.pop();
            pq.push({e,curr});
            used[curr]+=1;
            }
         }
        int maxi=0;
        int res;
        for(int i=0;i<n;i++){
              if(used[i]>maxi){
                maxi=used[i];
                res=i;
              }
        }
        return res;
        
    }
};
// Time Complexity: O(M log M + M log N) where M is the number of meetings
// Space Complexity: O(N)
