class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[0]>=complexity[i]) return 0;
        }
        int i=n-1;
        long long ans=1;
        int mod=1e9+7;
        while(i){
            ans=(ans*i)%mod;
            i--;
        }
        return ans;

    }
};