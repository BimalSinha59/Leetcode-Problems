class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        map<int, int> mp;
        for (int& card : hand) {
            mp[card]++;
        }
        while (mp.size()) {
            int cnt = 1;
            auto firstEle = mp.begin();
            int fkey = firstEle->first;
            int fval = firstEle->second;
            mp[fkey]--;
            if (mp[fkey] == 0) {
                mp.erase(fkey);
            }
            for (int i = fkey + 1; i < fkey + groupSize; i++) {
                if (mp.count(i) == 0) {
                    return false;
                } else {
                    mp[i]--;
                    if (mp[i] == 0) {
                        mp.erase(i);
                    }
                }
            }
        }
        return mp.empty();
    }
};