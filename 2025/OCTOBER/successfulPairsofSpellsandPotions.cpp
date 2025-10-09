class Solution {
public:
int solve(int mul,vector<int>&potions,long long success){
    int s=0;
    int e=potions.size()-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        long long val=1LL*potions[mid]*mul;
        if(val>=success){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans==-1?0:potions.size()-ans;
}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(solve(spells[i],potions,success));
        }
        return ans;
    }
};