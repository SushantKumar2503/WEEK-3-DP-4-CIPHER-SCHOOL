class Solution {
public:
    int minDistance(string word1, string word2) {
        int length1=word1.size();
        int length2=word2.size();
        vector<vector<int>>dp(length1+1,vector<int>(length2+1,0));
        for(int i=0;i<=length1;i++){
            for(int j=0;j<=length2;j++){
                if(i==0){
                    dp[i][j]=j;
                }
                else
                if(j==0){
                    dp[i][j]=i;
                }
                else
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                }
            }
        }
        return dp[length1][length2];
    }
};
