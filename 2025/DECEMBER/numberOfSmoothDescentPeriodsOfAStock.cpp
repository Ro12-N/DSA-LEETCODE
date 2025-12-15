class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        int n=prices.size();
        int i=0;
        while(i<n){
            long long curr=1;
            while(i+1<n &&prices[i]-prices[i+1]==1){
                i++;
                curr++;
            }
            i++;
            ans+=(1LL*curr*(curr+1)/2);
        }
        return ans;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)