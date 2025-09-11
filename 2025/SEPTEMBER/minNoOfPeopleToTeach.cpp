class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>sad;
        for(auto i:friendships){
            int a=i[0]-1;
            int b=i[1]-1;
            unordered_set<int>st(languages[a].begin(),languages[a].end());
            bool f=false;
            for(auto j:languages[b]){
                if(st.count(j)){
                    f=true;
                    break;
                }
            }
            if(!f){
                sad.insert(a);
                sad.insert(b);
            }

        }
        int ans=0;
        vector<int>mp(n+1,0);
        for(auto i:sad){
            for(auto j:languages[i]){
                mp[j]++;
                ans=max(ans,mp[j]);
            }
        }
        return sad.size()-ans;
    }
};