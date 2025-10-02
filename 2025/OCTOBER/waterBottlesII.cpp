class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        int full=numBottles;
        int empty=0;
        while(full>0){
            ans+=full;
            empty+=full;
            full=0;
            if(empty>=numExchange){
                full++;
                empty-=numExchange;
                numExchange++;
            }
        }
        return ans;
    }
};