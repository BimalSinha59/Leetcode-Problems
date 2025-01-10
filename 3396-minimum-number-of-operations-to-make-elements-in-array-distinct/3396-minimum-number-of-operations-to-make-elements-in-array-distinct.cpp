class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==2 && nums[0]==nums[1]){
            return 1;
        }
        if(n==3 && ((nums[0]==nums[1])||(nums[0]==nums[2]) || (nums[2]==nums[1]))){
            return 1;
        }
        int ans=0;
        int c=0;
        for(int i=0; i<n; i+=3){
            bool t1=false,t2=false,t3=false;

            if(i+3<n){
                c++;
            }
            else{
                break;
            }
            map<int ,int>mp;
            for(int j=i+3; j<n; j++){
                mp[nums[j]]++;
            }

            for(auto it:mp){
                if(it.second>1){
                    t1=true;
                    break;
                }
            }

            if(i+2<n && ((nums[i]==nums[i+1])||(nums[i]==nums[i+2])||(nums[i+1]==nums[i+2]))){
              t3=true;
            }

            if(mp.find(nums[i])!=mp.end() || mp.find(nums[i+1])!=mp.end() || mp.find(nums[i+2])!=mp.end()){
                t2=true;
            }

            if(t1 || t2 || t3){
                ans++;
            }
        }
       
        int rem=n-3*c;
      
        if(rem==2 && nums[n-2]==nums[n-1]){
            ans++;
        }
        if(rem==3 && ((nums[n-3]==nums[n-2])||(nums[n-3]==nums[n-1])||(nums[n-2]==nums[n-1]))){
            ans++;
        }
       
        return ans;
    }
};