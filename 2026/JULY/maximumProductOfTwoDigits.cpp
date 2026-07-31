class Solution {
public:
    int maxProduct(int n) {
        int a=0;
        int b=0;
        while(n){
            int d=n%10;
            n/=10;
            if(d>a){
                b=a;
                a=d;
            }else if(d>b) b=d;
        }
        return a*b;
    }
};
// Time Complexity: O(log n) since the function iterates through the digits of the number n, which has a logarithmic relationship with its value.
// Space Complexity: O(1) since the function uses a constant amount of space regardless of the input size.