class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if(n<10)
            return {};
        unordered_map<int,int> freq;
        vector<string> ans;
        int mask = (1 << 20) - 1;
        int hash = 0;
        for(int i = 0;i<10;i++){
            hash=(hash << 2) | ((s[i] >> 1) & 3);
        }
        freq[hash]++;
        for(int i = 10;i<n;i++){
            hash=((hash << 2)&mask) | ((s[i] >> 1) & 3);
            if (freq[hash] == 1) {
                ans.push_back(s.substr(i - 9, 10));  
            }
            freq[hash]++;
        }
        return ans;
    }
};