class DetectSquares {
public:
    int pfreq[1001][1001] = {0};
    vector<pair<int, int>> v;
    DetectSquares() {
        v.clear(); 
    }

    void add(vector<int> point) {
        pfreq[point[0]][point[1]]++;
        v.push_back({point[0], point[1]});
    }

    int count(vector<int> point) {
        int ans = 0;
        int x1 = point[0], y1 = point[1];
        for (auto it : v) {
            int x3 = it.first, y3 = it.second;
            if (abs(x1 - x3) > 0 && (abs(x1 - x3) == abs(y1 - y3))) {
                ans += pfreq[x1][y3] * pfreq[x3][y1];
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */