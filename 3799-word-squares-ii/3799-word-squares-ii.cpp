class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n=words.size();
        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            int idx;
            string left,right;
            for(int j=0; j<n; j++){
                if(j!=i && words[i][0]==words[j][0]){
                    left=words[j];
                    for(int k=0; k<n; k++){
                        if(k!=i && k!=j && words[i][3]==words[k][0]){
                            right=words[k];
                            for(int l=0; l<n; l++){
                                if(l!=i && l!=j && l!=k && words[l][0]==left[3] && 
                                words[l][3]==right[3]){

                                    vector<string>temp={words[i],left,right,words[l]};
                                    ans.push_back(temp);
                                }
                            }
                        }
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};