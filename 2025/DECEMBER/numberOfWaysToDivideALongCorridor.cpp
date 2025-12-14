class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int>ans;
        int n=corridor.size();
        for(int i=0;i<n;i++){
            if(corridor[i]=='S') ans.push_back(i);
        }
        if(ans.size()%2||ans.size()==0) return 0;
        int mod=1e9+7;
        long long res=1;
       for(int i=2;i<ans.size();i+=2){
        int l=ans[i]-ans[i-1];
        res=(res*l)%mod;
       }
       return res;
    }
};