class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        int n=operations.size();
        for(int i=0; i<n; i++){
            auto s=operations[i];
            int m=s.size();
            if(s[0]=='+' || s[m-1]=='+'){
                ans++;
            }
            else if(s[0]=='-' || s[m-1]=='-'){
                ans--;
            }
        }
        return ans;
    }
};