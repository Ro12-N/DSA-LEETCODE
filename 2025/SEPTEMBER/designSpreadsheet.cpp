class Spreadsheet {
public:
unordered_map<string,int>mp;
    Spreadsheet(int rows) {
        mp.clear();
    }
    
    void setCell(string cell, int value) {
        mp[cell]=value;
    }
    
    void resetCell(string cell) {
        mp[cell]=0;
    }
    
    int getValue(string formula) {
        int idx=1;
        string a="";
        int n=formula.size();
        while(idx<n&&formula[idx]!='+'){
            a+=formula[idx++];
        }
        idx++;
        string b=formula.substr(idx);
        int ans=0;
        if(mp.count(a)){
            ans+=mp[a];
        }else if(isdigit(a[0])){
            ans+=stoi(a);
        }
        if(mp.count(b)){
            ans+=mp[b];
        }else if(isdigit(b[0])){
            ans+=stoi(b);
        }
        return ans;
    }
};

