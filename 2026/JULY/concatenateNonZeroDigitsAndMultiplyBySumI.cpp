class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long s=0;
        while(n){
            int d=n%10;
            n/=10;
            if(d!=0){
            s+=d;
            x=x*10+d;
            }
        }
        long long ans=0;
        while(x){
            int d=x%10;
            x/=10;
            ans=ans*10+d;
        }
        return ans*s;
    }
};
// Time Complexity: O(logn) + O(logn) = O(logn)
// Space Complexity: O(1)