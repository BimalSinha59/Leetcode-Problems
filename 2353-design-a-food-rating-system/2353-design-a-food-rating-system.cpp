class FoodRatings {
private:
    unordered_map<string, string> ftc;
    unordered_map<string, int> ftr;
    unordered_map<string, set<pair<int, string>>> ctf;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            ftc[foods[i]] = cuisines[i];
            ftr[foods[i]] = ratings[i];
            ctf[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = ftc[food];
        int oldRating = ftr[food];
        ctf[cuisine].erase({-oldRating, food});
        ctf[cuisine].insert({-newRating, food});
        ftr[food] = newRating;
    }

    string highestRated(string cuisine) { return ctf[cuisine].begin()->second; }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */