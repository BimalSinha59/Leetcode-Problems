class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;

        for (int i = 0; i < n; i++) {
           if(digits[i]==0){
            continue;
           }
            
            for(int k=0; k<n; k++){
                if(k==i){
                    continue;
                }
                for (int j = 0; j < n; j++) {

                    if(j==i || j==k){
                        continue;
                    }
                
                    int a = 100 * digits[i] + 10 * digits[k] + 1 * digits[j];
                           
                    if (a % 2 == 0) {
                        st.insert(a);
                    }
                }
               
            }
           
        }
        return st.size();
    }
};