class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x, y;

        // Find rook
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                }
            }
        }

        int ans = 0;
        vector<pair<int, int>> dir = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        for (auto [dx, dy] : dir) {
            int i = x + dx;
            int j = y + dy;

            while (i >= 0 && i < 8 && j >= 0 && j < 8) {
                if (board[i][j] == 'B') break;

                if (board[i][j] == 'p') {
                    ans++;
                    break;
                }

                i += dx;
                j += dy;
            }
        }

        return ans;
    }
};