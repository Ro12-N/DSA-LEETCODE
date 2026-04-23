class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(auto i:queries){
            for(auto j:dictionary){
                int n=j.size();
                int cnt=0;
                bool f=false;
                for(int k=0;k<n;k++){
                    if(i[k]!=j[k]) cnt++;
                }
                if(cnt<3){
                    ans.push_back(i);
                    f=true;
                }
                if(f) break;
            }
        }
        return ans;
    }
};
//Time Complexity: O(m*n) where m is the size of queries and n is the size of dictionary.
//Space Complexity: O(1)