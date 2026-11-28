class Solution {
private:
    vector<vector<int>> rects;
    vector<int> prefix;
    int totalPoints;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int n = rects.size();
        totalPoints = 0;
        prefix.assign(n , 0);
        for (int i = 0; i < n; ++i) {
            int xlen = rects[i][2] - rects[i][0] + 1;
            int ylen = rects[i][3] - rects[i][1] + 1;
            totalPoints += xlen * ylen;
            prefix[i] = totalPoints;
        }
    }
    vector<int> pick() {
        int randPoint = rand() % totalPoints;
        int rectIndex = upper_bound(prefix.begin(), prefix.end(), randPoint) - prefix.begin();
        auto& r = rects[rectIndex];
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        return {x, y};
    }
};