class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        vector<vector<int>>v;
        for(int i=0; i<n; i++){
            vector<int>v1;
            for(int j=i; j<n; j++){
                v1.push_back(nums[j]);
                if(v1.size()==k){
                    v.push_back(v1);
                    break;
                }
               
            }
    
        }
        for(int i=0; i<n; i++){
            int c=0;
            for(int j=0; j<v.size();j++){
                
                for(int l=0; l<v[j].size(); l++){
                    if(nums[i]==v[j][l]){
                        c++;
                        break;
                    }
                }
                
            }
            if(c==1){
                //cout<<nums[i]<<" ";
                    ans=max(ans,nums[i]);
                }
        }
        return ans;
        
    }
};