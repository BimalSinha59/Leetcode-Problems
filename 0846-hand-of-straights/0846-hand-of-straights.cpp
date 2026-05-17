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
            auto firstEle = mp.begin();
            int fkey = firstEle->first;
            for (int i = fkey; i < fkey + groupSize; i++) {
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
        return true;
    }
};