class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    double f(int a, int b,
             unordered_map<pair<int, int>, double, pair_hash>& mp) {
        if (a <= 0 && b > 0) {
            return 1;
        }
        if (b <= 0 && a > 0) {
            return 0;
        }
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (mp.find({a, b}) != mp.end()) {
            return mp[{a, b}];
        }
        return mp[{a, b}] =
                   0.25 * (f(a - 100, b, mp) + f(a - 75, b - 25, mp) +
                           f(a - 50, b - 50, mp) + f(a - 25, b - 75, mp));
    }
    double soupServings(int n) {
        if(n>=4800){
            return 1.00000;
        }
        unordered_map<pair<int, int>, double, pair_hash> mp;
        return f(n, n, mp);
    }
};