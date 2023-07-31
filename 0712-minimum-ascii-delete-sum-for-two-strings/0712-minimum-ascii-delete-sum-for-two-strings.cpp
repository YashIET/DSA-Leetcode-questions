class Solution {

public:
    
    int rec(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        
        
        if (i < 0) {
            
            int c = 0;
            for (int k = 0; k <= j; k++) {
            c += s2[k];
            }
            return c;
        }

        if (j < 0) {
        
            int c = 0;
            for (int k = 0; k <=i; k++) {
                c += s1[k];
            }
            return c;
        }

        
         if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) {
            return dp[i][j]= rec(s1, s2, i - 1, j - 1, dp);
        } 

              int take1 = s1[i]+rec(s1 , s2 , i-1 , j,dp);

    int take2 = s2[j]+rec(s1 , s2 , i , j-1,dp);

    return dp[i][j]= min(take1 , take2);

      
        return dp[i][j];
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return rec(s1, s2, m-1, n-1, dp);
    }

};