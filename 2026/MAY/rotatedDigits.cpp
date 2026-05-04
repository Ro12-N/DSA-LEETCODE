class Solution {
public:
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            int curr=i;
            bool ex=true;
           bool diff=false;
            while(curr){
                int d=curr%10;
                curr/=10;
                if(d==3||d==4||d==7){
                    ex=false;
                    break;
                }
                else if(d==2||d==5||d==6||d==9){
                    diff=true;
                }
            }
            if(ex&&diff) cnt++;
        }
        return cnt;
    }
};
// TC: O(n*logn) where n is the input number and logn is the number of digits in n
// SC: O(1) as we are using only constant space to store the count and