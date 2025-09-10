class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {

        set<int> st;
        for(const auto& it : friendships) {
            auto u = it[0] - 1, v = it[1] - 1;
            bool flg = false;
            for(const auto x : languages[u]) {
                for(const auto y : languages[v]) {
                    if (x == y) 
                    { 
                        flg = true; 
                        break; 
                    }
                }
            }
            if (!flg) { 
                st.insert(u);
                st.insert(v); 
            }
        }
        
        int ans = languages.size() + 1;
        for(int i = 1; i <= n; i++) {
            int cans = 0;
            for(auto v : st) {
                bool found = false;
                for(auto c : languages[v]) {
                    if (c == i) { 
                        found = true; 
                        break; 
                    }
                }
                if (!found){
                    cans++;
                }
            }
            ans = min(ans, cans);
        }
        return ans;
        
    }
};