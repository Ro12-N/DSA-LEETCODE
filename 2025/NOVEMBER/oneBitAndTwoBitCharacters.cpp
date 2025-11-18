class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int i=0;
        while(i<n-1){
            if(bits[i]) i+=2;
            else i++;
        }
        return i==n-1 && bits[i]==0;
    }
};