class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        
        // row[i] = kitni baar ith row increment hui
        vector<int> row(m, 0);
        
        // col[j] = kitni baar jth column increment hua
        vector<int> col(n, 0);

        // rows aur columns ke increment count store karo
        for (auto &idx : indices) {
            int r = idx[0];
            int c = idx[1];

            row[r]++;
            col[c]++;
        }

        int oddRows = 0;
        int oddCols = 0;

        // odd increment wali rows count karo
        for (int i = 0; i < m; i++) {
            if (row[i] % 2 != 0) {
                oddRows++;
            }
        }

        // odd increment wale columns count karo
        for (int j = 0; j < n; j++) {
            if (col[j] % 2 != 0) {
                oddCols++;
            }
        }

        /*
            Formula:
            
            odd row + even col  => odd
            even row + odd col  => odd

            Total odd cells =
            (oddRows * evenCols) +
            (evenRows * oddCols)
        */

        int evenRows = m - oddRows;
        int evenCols = n - oddCols;

        return (oddRows * evenCols) + (evenRows * oddCols);
    }
};