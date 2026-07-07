class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
    
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int cnt=0;
        int maxi=0;
        for(auto i:intervals){
            int e=i[1];
            if(e<=maxi) cnt++;
            else maxi=e;
        }
        
        return intervals.size()-cnt;

    }
};
// Time Complexity: O(nlogn) + O(n) = O(nlogn)
// Space Complexity: O(1)