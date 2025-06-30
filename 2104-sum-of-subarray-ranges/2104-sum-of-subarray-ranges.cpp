class Solution {
public:
    void nextSmaller(vector<int>& nums,int n, vector<int>&nextmn){
        stack<int>st;
        st.push(-1);
        for(int i=n-1; i>=0; i--){
            int ele = nums[i];
            while(!st.empty() && st.top()!=-1 && nums[st.top()]>ele){
                st.pop();
            }
            nextmn.push_back(st.top());
            st.push(i);
        }
    }
    void prevSmaller(vector<int>&nums,int n, vector<int>&prevmn){
        stack<int>st;
        st.push(-1);
        for(int i=0; i<n; i++){
            int ele=nums[i];
            while(!st.empty() && st.top()!=-1 && nums[st.top()]>=ele){
                st.pop();
            }
            prevmn.push_back(st.top());
            st.push(i);
        }
    }
    long long sumSubarrayMins(vector<int>& nums) {
        vector<int>nextmn;
        vector<int>prevmn;
        int n=nums.size();
        nextSmaller(nums,n,nextmn);
        reverse(nextmn.begin(),nextmn.end());

        for(int i=0; i<n; i++){
            if(nextmn[i]==-1){
                nextmn[i]=n;
            }
        }

        prevSmaller(nums,n,prevmn);
        
        long long sum=0;
        for(int i=0; i<n; i++){
            long long nextS=nextmn[i]-i;
            long long prevS=i-prevmn[i];
            long long mul=(nextS)*(prevS);
            long long total=(mul*nums[i]);
            sum=(sum+total);
        }
        return sum;
    }

    void nextGreater(vector<int>& nums,int n, vector<int>&nextmx){
        stack<int>st;
        st.push(-1);
        for(int i=n-1; i>=0; i--){
            int ele = nums[i];
            while(!st.empty() && st.top()!=-1 && nums[st.top()]<ele){
                st.pop();
            }
            nextmx.push_back(st.top());
            st.push(i);
        }
    }
    void prevGreater(vector<int>&nums,int n, vector<int>&prevmx){
        stack<int>st;
        st.push(-1);
        for(int i=0; i<n; i++){
            int ele=nums[i];
            while(!st.empty() && st.top()!=-1 && nums[st.top()]<=ele){
                st.pop();
            }
            prevmx.push_back(st.top());
            st.push(i);
        }
    }
    long long sumSubarrayMaxs(vector<int>& nums) {
        vector<int>nextmx;
        vector<int>prevmx;
        int n=nums.size();
        nextGreater(nums,n,nextmx);
        reverse(nextmx.begin(),nextmx.end());

        for(int i=0; i<n; i++){
            if(nextmx[i]==-1){
                nextmx[i]=n;
            }
        }

        prevGreater(nums,n,prevmx);
        
        long long sum=0;
        for(int i=0; i<n; i++){
            long long nextS=nextmx[i]-i;
            long long prevS=i-prevmx[i];
            long long mul=(nextS)*(prevS);
            long long total=(mul*nums[i]);
            sum=(sum+total);
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {

        long long minSum=sumSubarrayMaxs(nums);
        long long maxSum=sumSubarrayMins(nums);
        cout<<minSum<<" "<<maxSum;
        long long ans=maxSum-minSum;
        return -ans;
        
    }
};