class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0||k%5==0) return -1;
        int cnt=0;
        long long curr=1;
        while(curr<=LLONG_MAX){
            cnt++;
            if(curr%k==0) return cnt;
            curr=((curr*10)+1)%k;
        }
        return -1;
    }
};






















































































































