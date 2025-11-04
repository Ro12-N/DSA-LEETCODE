class Solution {
public:
int solve(unordered_map<int,int>&mp,int x){
    priority_queue<pair<int,int>>pq;
    for(auto i:mp){
        pq.push({i.second,i.first});
    }
    int cnt=0;
    while(!pq.empty() && x--){
        auto [a,b]=pq.top();
        pq.pop();
        cnt+=(a*b);
    }
    return cnt;
}
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        ans.push_back(solve(mp,x));
        for(int i=k;i<n;i++){
            mp[nums[i-k]]--;
            mp[nums[i]]++;
            ans.push_back(solve(mp,x));
            
        }
        return ans;
    }
};