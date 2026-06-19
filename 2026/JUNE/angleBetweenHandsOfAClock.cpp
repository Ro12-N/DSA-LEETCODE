class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a=hour*30+minutes*0.5;
        double b=minutes*6;
        double curr=abs(a-b);
        return min(curr,(360-curr));
    }
};
// TC : O(1) since we are doing constant time calculations
// SC : O(1) since we are using constant space