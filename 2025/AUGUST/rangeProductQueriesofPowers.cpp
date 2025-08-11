class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod=1e9+7;
        vector<int>powers;
        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                powers.push_back(1<<i);
            }
        }
        vector<int>ans;
        for(auto i:queries){
            long curr=1;
            for(int j=i[0];j<=i[1];j++){
                  curr=(curr*powers[j])%mod;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};