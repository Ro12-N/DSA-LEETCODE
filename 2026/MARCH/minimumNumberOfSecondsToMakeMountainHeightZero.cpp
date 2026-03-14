class Solution {
public:
    bool check(long long m, vector<int>& w, int mh){
        long long h = 0;

        for(auto &t : w){
            h += (long long)(sqrt(2.0*m/t + 0.25) - 0.5);
            if(h >= mh) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int mx = *max_element(workerTimes.begin(), workerTimes.end());

        long long s = 1;
        long long e = 1LL * mx * mountainHeight * (mountainHeight + 1) / 2;
        long long ans = 0;

        while(s <= e){
            long long m = (s + e) / 2;

            if(check(m, workerTimes, mountainHeight)){
                ans = m;
                e = m - 1;
            } 
            else s = m + 1;
        }

        return ans;
    }
};
// Time Complexity: O(n log(mx * mh * (mh + 1) / 2))
// Space Complexity: O(1)