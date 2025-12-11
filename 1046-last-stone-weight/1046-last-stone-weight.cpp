class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int& it : stones) {
            pq.push(it);
        }
        while (!pq.empty()) {
            if (pq.size() == 1) {
                break;
            }
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (y > x) {
                pq.push(y - x);
            }
        }
        if (pq.empty()) {
            return 0;
        }
        return pq.top();
    }
};