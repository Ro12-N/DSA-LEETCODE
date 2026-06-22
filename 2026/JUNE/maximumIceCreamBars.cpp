class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0;
        for(auto i:costs){
            coins-=i;
            if(coins>=0) cnt++;
            else return cnt;
        }
        return cnt;
    }
};
// TC : O(nlogn) since we are sorting the array
// SC : O(1) since we are using constant space