class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<int> commonFreq(26, INT_MAX);

        // Har word ki frequency count karo
        for(string &word : words) {
            vector<int> freq(26, 0);

            for(int ch : word) {
                freq[ch - 'a']++;
            }

            // Minimum frequency store karo
            for(int i = 0; i < 26; i++) {
                commonFreq[i] = min(commonFreq[i], freq[i]);
            }
        }

        vector<string> ans;

        // Jo characters sabme common hain unko add karo
        for(int i = 0; i < 26; i++) {
            while(commonFreq[i] > 0) {
                ans.push_back(string(1, 'a' + i));
                commonFreq[i]--;
            }
        }

        return ans;
    }
};