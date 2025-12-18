class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long ans=0;
        int n=prices.size();
        long long original=0;
        long long modify=0;
        for(int i=0;i<n;i++){
            ans+=(prices[i]*strategy[i]);
            if(i<k) {
                original+=(1LL*prices[i]*strategy[i]);
                if(i>=k/2) modify+=prices[i];
            }
        }
        long long maxi=0;
        int i=0;
        int j=k-1;
        while(j<n){
            if(j-i+1==k){
               maxi=max(maxi,modify-original);
               original-=(1LL*prices[i]*strategy[i]);
               modify-=prices[i+k/2];
               i++;
            }
            j++;
            if(j>=n) break;
            modify+=(1LL*prices[j]);
            original+=(1LL*prices[j]*strategy[j]);        
        }
        
        return ans+maxi;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)