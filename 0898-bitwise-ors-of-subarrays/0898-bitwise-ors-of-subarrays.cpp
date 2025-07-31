class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> ans,currOr;
        for(int i=0; i<n; i++){
            unordered_set<int> nextOr;
            nextOr.insert(arr[i]);
            for(auto it:currOr){
                nextOr.insert(arr[i]|it);
            }
            ans.insert(nextOr.begin(),nextOr.end());
            currOr=nextOr;
        }
        return ans.size();
    }
};