// 1009. Complement of Base 10 Integer
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int b=log2(n)+1;
        for(int i=0;i<b;i++){
            int v=(n & (1<<i));
              n=(n^(1<<i));
        }
        return n;
    }
};
//TC: O(log n) where n is the input number. This is because we are iterating through the bits of the number, which takes logarithmic time.
//SC: O(1) because we are using a constant amount of extra space to store the variables and perform the bitwise operations.



// Approach 2: Using Bit Manipulation
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int msk=(1<<(int)(log2(n)+1))-1;
        return n^msk;
    }
};
//TC: O(log n) where n is the input number. This is because we are calculating the mask using logarithmic time.
//SC: O(1) because we are using a constant amount of extra space to store the variables and perform the bitwise operations.