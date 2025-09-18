class FoodRatings {
public:
unordered_map<string,string>c;
unordered_map<string,int>rate;
unordered_map<string,set<pair<int,string>>>pq;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            c[foods[i]]=cuisines[i];
            rate[foods[i]]=-ratings[i];
            pq[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cus=c[food];
        pq[cus].erase({rate[food],food});
        rate[food]=-newRating;
        pq[cus].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
       return pq[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */