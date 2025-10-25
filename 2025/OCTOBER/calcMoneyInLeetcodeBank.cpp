class Solution {
public:
    int totalMoney(int n) {
        int cnt=n/7;
        int ans=0;
        int i=0;
        for(;i<cnt;i++){
            int val=7+i;
            int add=(val)*(val+1)/2;
            int remove=i*(i+1)/2;
            ans+=add;
            ans-=remove;
        }
        int rem=n%7;
        ans+=(rem+i)*(rem+1+i)/2;
        ans-=(i)*(i+1)/2;
        return ans;
    }
};