class Solution {
public:
    void generateBinStrings(string curr, int &n, vector<string>& ans){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        generateBinStrings(curr+"1", n, ans);
        if(curr.empty() || curr.back()!='0'){
            generateBinStrings(curr+'0', n, ans);
        }
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        generateBinStrings("",n,ans);
        return ans;
    }
};