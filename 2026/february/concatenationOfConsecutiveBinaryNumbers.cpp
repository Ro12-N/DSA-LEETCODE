class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=0;
        int mod=1e9+7;
        int bit=0;
        for(int i=1;i<=n;i++){
           if((i &(i-1))==0) bit++;
            ans=(ans<<bit)%mod;
            ans=(ans+i)%mod;
        }
        return (int)ans;
        
    }
};
// TC: O(n) where n is the input number, since we iterate through all numbers from 1 to n.
// SC: O(1) since we are using a constant amount of extra space to store