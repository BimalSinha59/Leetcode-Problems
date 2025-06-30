class Solution {
public:
    vector<int> findPSEE(vector<int>& nums, int n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i]=st.empty() ? -1:st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findNSE(vector<int>& nums, int n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            ans[i]=st.empty() ? n:st.top();
            st.push(i);
        }
        return ans;
    }
    
    long long sumMin(vector<int>& nums, int n){
        auto psee=findPSEE(nums,n);
        auto nse=findNSE(nums,n);
        long long ans=0;
        for(int i=0; i<n; i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            ans+=(1LL*left*right*nums[i]);
        }
        return ans;
    }

    vector<int> findPGEE(vector<int>& nums, int n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            ans[i]=st.empty() ? -1:st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findNGE(vector<int>& nums, int n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            ans[i]=st.empty() ? n:st.top();
            st.push(i);
        }
        return ans;
    }


    long long sumMax(vector<int>& nums, int n){
        auto pgee=findPGEE(nums,n);
        auto nge=findNGE(nums,n);
        long long ans=0;
        for(int i=0; i<n; i++){
            int left=i-pgee[i];
            int right=nge[i]-i;
            ans+=(1LL*left*right*nums[i]);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sumOfMax=sumMax(nums,n);
        long long sumOfMin=sumMin(nums,n);
        return sumOfMax-sumOfMin;
    }
};