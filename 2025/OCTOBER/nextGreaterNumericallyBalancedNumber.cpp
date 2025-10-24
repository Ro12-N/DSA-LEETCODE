class Solution {
public:
    int nextBeautifulNumber(int n) {
        while(true){
            ++n;
            int val=n;
            vector<int>freq(10,0);
            while(val>0){
                freq[val%10]++;
                val/=10;
            }
            bool f=true;
            for(int i=0;i<10;i++){
                if(freq[i]!=0 && freq[i]!=i){
                    f=false;
                    break;
                }
            }
            if(f) return n;
        }
        return -1;
    }
};