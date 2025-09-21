class MovieRentingSystem {
private:
    map<int, set<pair<int, int>>> avlMovies;
    set<tuple<int, int, int>> rtdMovies;
    map<pair<int, int>, int> prc;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            prc[{shop, movie}] = price;
            avlMovies[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        if (avlMovies.count(movie)) {
            auto& shops = avlMovies.at(movie);
            int count = 0;
            for (const auto& p : shops) {
                if (count >= 5)
                    break;
                result.push_back(p.second);
                count++;
            }
        }
        return result;
    }

    void rent(int shop, int movie) {
        int price = prc.at({shop, movie});
        avlMovies.at(movie).erase({price, shop});
        rtdMovies.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = prc.at({shop, movie});
        rtdMovies.erase({price, shop, movie});
        avlMovies.at(movie).insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (const auto& t : rtdMovies) {
            if (count >= 5)
                break;

            result.push_back({get<1>(t), get<2>(t)});
            count++;
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */