class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        for(int i=0; i<n; i++){
            if(arr[i]==1){
                count++;
            }
        }
        vector<int> ans{-1,-1};
        if(count==0){
            ans[0]=0;
            ans[1]=2;
            return ans;
        }
        if(count%3!=0){
            ans[0]=-1;
            ans[1]=-1;
          return ans;
        }

        int divs=count/3;
        // string s1,s2,s3;
        // int c=0;
        // int i=0;
        // while(c<divs){
        //     s1.push_back(arr[i]+'0');
        //     if(arr[i]==1){
        //         c++;
        //     }
        //     i++;
        // }
        //  c=0;
        //  ans[0]=i-1;
        // // while(arr[i]!=1){
        // //     i++;
        // // }
        // while(c<divs){
        //     s2.push_back(arr[i]+'0');
        //     if(arr[i]==1){
        //         c++;
        //     }
        //     i++;
        // }
        //  c=0;
        //  ans[1]=i;
        // // while(arr[i]!=1){
        // //     i++;
        // // }
        // while(i<n){
        //     s3.push_back(arr[i]+'0');
        //     // if(arr[i]==1){
        //     //     c++;
        //     // }
        //     i++;
        // }
        // cout<<s1<<" "<<s2<<" "<<s3<<endl;

        // reverse(s1.begin(),s1.end());
        //  reverse(s2.begin(),s2.end());
        //   reverse(s3.begin(),s3.end());

        // int x=s1.size()-1;
        // while(s1[x]!='1'){
        //     s1.pop_back();
        //     x--;
        // }
        //  x=s2.size()-1;
        // while(s2[x]!='1'){
        //     s2.pop_back();
        //     x--;
        // }
        // x=s3.size()-1;
        // while(s3[x]!='1'){
        //     s3.pop_back();
        //     x--;
        // }

        // cout<<s1<<" "<<s2<<" "<<s3;

        // if(s1!=s2 || s2!=s3 || s1!=s3){
        //     ans[0]=-1;
        //     ans[1]=-1;
        // }
        // return ans;

        int i;
        int c1=0;
        for(i=0; i<n; i++){
            if(arr[i]==1){
               break;
            }
        }
        int left=i;
        for(i=0; i<n; i++){
            if(arr[i]==1){
                c1++;
            }
            if(c1==divs+1){
                break;
            }
        }
        int cent=i;
        c1=0;
        for(i=0; i<n; i++){
            if(arr[i]==1){
                c1++;
            }
            if(c1==2*divs+1){
                break;
            }
        }
        int right=i;

        while(right<n && arr[left]==arr[cent] && arr[cent]==arr[right]){
            left++;
            cent++;
            right++;
        }

        if(right==n){
            ans[0]=left-1;
            ans[1]=cent;
            return ans;
        }

        return ans;

    }
};