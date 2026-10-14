class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)
            return "";

        int q = sum / 9;
        int r = sum % 9;

        string ans(q, '9');

        if (r > 0)
            ans += to_string(r);

        ans += string(num - ans.size(), '0');

        return ans;
    }
};