class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // ASCII characters ke liye size 256 ka array
        vector<int> mapST(256, -1);
        vector<int> mapTS(256, -1);

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // Agar mapping pehle se nahi hui
            if (mapST[c1] == -1 && mapTS[c2] == -1) {
                mapST[c1] = c2;
                mapTS[c2] = c1;
            }
            // Agar mapping mismatch hui
            else if (mapST[c1] != c2 || mapTS[c2] != c1) {
                return false;
            }
        }

        return true;
    }
};