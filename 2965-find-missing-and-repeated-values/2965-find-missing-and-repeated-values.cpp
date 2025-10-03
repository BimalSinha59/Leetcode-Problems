class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_set<int>st;
        vector<int>ans(2);
        for(auto it:grid){
            for(auto jt:it){
                if(st.count(jt)){
                    ans[0]=jt;
                }
                st.insert(jt);
            }
        }
        for(int i=1; i<=n*n; i++){
            if(st.count(i)==0){
                ans[1]=i;
                break;
            }
        }
        return ans;
    }
};