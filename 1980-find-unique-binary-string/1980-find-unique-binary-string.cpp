class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0; i<(1<<n); i++){
            string str;
            int num=i;
            while(num>0){
                int dig=num%2;
                str.push_back(dig+'0');
                num/=2;
            }
            string add(n-str.size(),'0');
            reverse(str.begin(), str.end());
            str=add+str;
            if(st.count(str)==0){
                return str;
            }
        }
        return "";
    }
};