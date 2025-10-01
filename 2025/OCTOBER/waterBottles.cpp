class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
         int ans=numBottles;
         while(numBottles>=numExchange){
            int b=numBottles/numExchange;
            ans+=b;
            numBottles=b+(numBottles%numExchange);

         }
         return ans;   
    }
};