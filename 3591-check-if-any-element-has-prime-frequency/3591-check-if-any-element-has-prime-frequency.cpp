class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto it:mp){
            int x=it.second;
            if(x==2){
                return true;
            }
            if(x>1){
                int c=0;
                for(int i=2; i<=x/2; i++){
                    if(x%i==0){
                        c=1;
                        break;
                    }
                }
                if(c==0){
                    return true;
                }
            }
        }
        return false;
    }
};