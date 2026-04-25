class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int a=0;
        int b=0;
        for(auto i:moves){
             if(i=='L'){
                a--;
                b--;
             }else if(i=='R'){
                a++;
                b++;
             }else{
                a--;
                b++;
             }
        }
        return max(abs(a),b);
       
    }
};
// Time complexity:O(N)
// Space Complexity:O(1)