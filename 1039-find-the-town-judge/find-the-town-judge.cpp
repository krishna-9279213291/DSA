class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        // Count trust relationships
        for (auto &t : trust) {
            int a = t[0];
            int b = t[1];

            outdegree[a]++; // a trusts someone
            indegree[b]++;  // b is trusted by someone
        }

        // Judge condition:
        // 1. trusts nobody -> outdegree = 0
        // 2. trusted by everyone else -> indegree = n-1
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};