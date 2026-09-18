class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // s2 empty hai -> s1 ke saare characters delete
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }

        // s1 empty hai -> s2 ke saare characters delete
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    // Same character hai, delete karne ki zarurat nahi
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    // Either s1 ka character delete
                    // OR s2 ka character delete
                    dp[i][j] = min(
                        s1[i - 1] + dp[i - 1][j],
                        s2[j - 1] + dp[i][j - 1]
                    );
                }
            }
        }

        return dp[n][m];
    }
};