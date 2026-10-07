class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                count++;
            }
            else if (ch == ')') {
                count--;

                // More closing brackets than opening
                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int size = q.size();

            // Process one level = one number of removals
            while (size--) {
                string curr = q.front();
                q.pop();

                // If valid, add it
                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                // If valid strings found at this level,
                // don't generate next level
                if (found)
                    continue;

                // Remove one character
                for (int i = 0; i < curr.length(); i++) {

                    // Only remove parentheses
                    if (curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) +
                                  curr.substr(i + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // Minimum removals achieved
            if (found)
                break;
        }

        return ans;
    }
};