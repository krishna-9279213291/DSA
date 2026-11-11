class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int idx) {

        // Word completely matched
        if (idx == word.size())
            return true;

        // Boundary check and character matching
        if (i < 0 || j < 0 || i >= m || j >= n ||
            board[i][j] != word[idx])
            return false;

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);

        // Backtrack: Restore original character
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        // Search pruning: Check character frequencies
        int freq[128] = {0};

        for (auto& row : board) {
            for (char c : row)
                freq[(unsigned char)c]++;
        }

        int required[128] = {0};

        for (char c : word) {
            required[(unsigned char)c]++;
        }

        for (int i = 0; i < 128; i++) {
            if (required[i] > freq[i])
                return false;
        }

        // Start DFS from every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};