class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>cnt;
        for(auto b:bank){
            int o=0;
            for(auto i:b){
                if(i=='1') o++;
            }
            if(o!=0)
            cnt.push_back(o);
        }
        int  ans=0;
        for(int i=1;i<cnt.size();i++){
              ans+=cnt[i-1]*cnt[i];
        }
        return ans;
    }
};