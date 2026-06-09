class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
           vector<int>ans;
           vector<int>p;
           vector<int>l;
           for(auto i:nums){
            if(i<pivot) ans.push_back(i);
            if(i>pivot) l.push_back(i);
            if(i==pivot) p.push_back(i);
           }
           ans.insert(ans.end(),p.begin(),p.end());
           ans.insert(ans.end(),l.begin(),l.end());
           return ans;
    }
};
// TimeComplexity: O(N);
// SpaceComplexity: O(N);