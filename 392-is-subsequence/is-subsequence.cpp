class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;  // pointer for s
        int j = 0;  // pointer for t

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.length();
    }
};