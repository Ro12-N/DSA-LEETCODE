class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>res;
        for(int h=0;h<12;h++){
            for(int m=0;m<60;m++){
                if(__builtin_popcount(h)+__builtin_popcount(m)==turnedOn){
                    string ans=to_string(h);
                    ans+=":";
                    ans+=((m<10)?"0":"")+to_string(m);
                    res.push_back(ans);
                }
            }
        }
        return res;
    }
};
// TC: O(1) since the loops run a fixed number of times (12 for hours and 60 for minutes).
// SC: O(1) for the output list, as the maximum number of valid times is limited (720 combinations).