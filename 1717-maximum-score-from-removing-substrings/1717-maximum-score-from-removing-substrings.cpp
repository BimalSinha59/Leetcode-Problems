class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        // vector<char> v;
        // int ans = 0;
        // if (x >= y) {
        //     for (int i = 0; i < n; i++) {
        //         if (s[i] == 'b' && !v.empty() && v.back() == 'a') {
        //             ans += x;
        //             v.pop_back();
        //         }
        //         else {
        //             v.push_back(s[i]);
        //         }
        //     }
        //     vector<char>vv;
        //     for (int i = 0; i < v.size(); i++) {
        //         if(v[i]=='a' && !vv.empty() && vv.back()=='b'){
        //             ans+=y;
        //             vv.pop_back();
        //         }
        //         else{
        //             vv.push_back(v[i]);
        //         }
        //     }
        // } 
        // else {
        //     for (int i = 0; i < n; i++) {
        //         if (s[i] == 'a' && !v.empty() && v.back() == 'b') {
        //             ans += y;
        //             v.pop_back();
        //         } 
        //         else {
        //             v.push_back(s[i]);
        //         }
        //     }
        //     vector<char>vv;
        //     for (int i = 0; i < v.size(); i++) {
        //         if(v[i]=='b' && !vv.empty() && vv.back()=='a'){
        //             ans+=x;
        //             vv.pop_back();
        //         }
        //         else{
        //             vv.push_back(v[i]);
        //         }
        //     }
        // }  ====>>> TC=O(n) && SC=O(n)

        //////Optimization//////
        if(x<y){
            swap(x,y);
            reverse(s.begin(),s.end());
        }
        int ans=0;
        int acnt=0,bcnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                acnt++;
            }
            else if(s[i]=='b'){
                if(acnt>0){
                    ans+=x;
                    acnt--;
                }
                else{
                    bcnt++;
                }
            }
            else{
                ans+=min(acnt,bcnt)*y;
                acnt=0;
                bcnt=0;
            }
        }
        ans+=min(acnt,bcnt)*y;
        return ans; //====>>>TC=O(n) , SC=O(1)
    }
};