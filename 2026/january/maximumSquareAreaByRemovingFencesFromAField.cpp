class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_set<int>st;
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                int dist=abs(hFences[j]-hFences[i]);
                st.insert(dist);
            }
        }
        int ans=0;
         for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                int dist=abs(vFences[j]-vFences[i]);
                 if(st.count(dist)) ans=max(ans,dist);
            }
        }
        int mod=1e9+7;
        if(ans==0) return -1;
        return (1LL*ans*ans) %mod;
    }
};
// Time Complexity: O((h+k)^2) where h is the number of horizontal fences and k is the number of vertical fences
// Space Complexity: O(h) where h is the number of horizontal fences