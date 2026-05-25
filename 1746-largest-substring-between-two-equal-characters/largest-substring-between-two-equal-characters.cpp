class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;

        // har character ka first index store karenge
        vector<int> first(26, -1);

        for (int i = 0; i < s.length(); i++) {

            // agar character pehli baar mila
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            else {
                // current length calculate karo
                ans = max(ans, i - first[s[i] - 'a'] - 1);
            }
        }

        return ans;
    }
};