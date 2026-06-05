class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for(int i=num1;i<=num2;i++){
            string curr=to_string(i);
            int s=curr.size();
            for(int i=1;i<s-1;i++){
                int a=curr[i-1]-'0';
                int c=curr[i+1]-'0';
                int b=curr[i]-'0';
                if((a<b &&b>c)||(a>b&&b<c)) cnt++;
            }
        }
        return cnt;
    }
};
// Time Complexity: O(n*m) where n is the number of integers in the range [num1, num2] and m is the average number of digits in those integers.
// Space Complexity: O(m) where m is the average number of digits in the integers, as we are converting each integer to a string to check for waviness.