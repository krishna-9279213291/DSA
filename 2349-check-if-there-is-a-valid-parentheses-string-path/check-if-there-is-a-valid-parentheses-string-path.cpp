class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;

        // dp[j] = possible balances at current row, column j
        vector<set<int>> dp(n);

        dp[0].insert(1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) continue;

                set<int> cur;

                // From top
                if (i > 0)
                    cur.insert(dp[j].begin(), dp[j].end());

                // From left
                if (j > 0)
                    cur.insert(dp[j-1].begin(), dp[j-1].end());

                dp[j].clear();

                for (int bal : cur) {
                    int nb = bal + (grid[i][j] == '(' ? 1 : -1);

                    if (nb >= 0)
                        dp[j].insert(nb);
                }
            }
        }

        return dp[n-1].count(0);
    }
};