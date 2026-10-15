class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, temp1 = 0, temp2 = -1;
        int x = s.length(), y = p.length();
        while (i < x) {

            if ((j < y)&&(p[j] == '?' || p[j] == s[i]) ){
                i++;
                j++;
            }
            else if ((j < y)&&(p[j] == '*')) {
                temp2 = j;
                temp1 = i;
                j++;
            }
            else if (temp2 != -1) {
                i=temp1, j=temp2;
                i++, j++,temp1++;
            } 
            else {
                return false;
            }
        }
        while (j < y && p[j] == '*') {
            j++;
        }
        if(j==y) return true;
        return false;
    }
};