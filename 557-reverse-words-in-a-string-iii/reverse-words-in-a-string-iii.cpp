class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int l = s.length();

        for (int i = 0; i < l; i++) {
            string temp = "";
            while (i < l && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            reverse(temp.begin(), temp.end());
            ans += temp;
            if (i < l) {
                ans += ' ';
            }
        }
        return ans;
    }
};