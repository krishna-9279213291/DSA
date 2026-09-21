class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // endWord dictionary me nahi hai -> impossible
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            
            int size = q.size();

            while (size--) {
                
                string word = q.front();
                q.pop();

                // Current word se saare possible one-letter words banao
                for (int i = 0; i < word.length(); i++) {
                    
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        
                        if (ch == original)
                            continue;

                        word[i] = ch;

                        // Valid word mil gaya
                        if (st.find(word) != st.end()) {
                            
                            // Destination mil gaya
                            if (word == endWord)
                                return level + 1;

                            q.push(word);

                            // Visited mark
                            st.erase(word);
                        }
                    }

                    word[i] = original;
                }
            }

            level++;
        }

        return 0;
    }
};