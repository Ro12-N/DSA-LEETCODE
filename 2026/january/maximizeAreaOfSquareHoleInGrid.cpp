class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int cnt=1;
        int a=1;
        int b=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-1==hBars[i-1]) cnt++;
            else cnt=1;
            a=max(a,cnt);
        }
        cnt=1;
          for(int i=1;i<vBars.size();i++){
            if(vBars[i]-1==vBars[i-1]) cnt++;
            else cnt=1;
            b=max(b,cnt);
        }
        int side=min(a,b)+1;
        return side*side;
    }
};
// https://leetcode.com/problems/maximize-area-of-square-hole-in-a-grid/description/
// Tc:O(nlogn + mlogm)  
// Sc:O(1)