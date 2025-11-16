class Solution {
public:
    int numSub(string s) {
        int ans=0;
        int n=s.size();
        int m=1e9+7;
        long long cnt=0;
        for(auto i:s){
           if(i=='1') cnt++;
           else {
            ans+=((cnt)*(cnt+1)/2)%m;
            cnt=0;
           }
        }
        ans+=((cnt)*(cnt+1)/2)%m;
        return ans;
    }
};