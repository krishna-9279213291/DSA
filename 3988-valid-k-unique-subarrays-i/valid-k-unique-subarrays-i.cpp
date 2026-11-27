class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        
        mt19937_64 rng(1337);
        unordered_map<int, uint64_t> zobrist_map;
        int max_val = 0;
        
        for (int x : nums) {
            if (!zobrist_map.count(x)) {
                zobrist_map[x] = rng();
            }
            if (x > max_val) {
                max_val = x;
            }
        }
        
        int global_distinct = zobrist_map.size();

        vector<uint64_t> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] ^ zobrist_map[nums[i]];
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        vector<int> seen(max_val + 1, 0);
        int query_id = 0;

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int len = r - l + 1;

            if ((len & 1) || len < 2 * k || ((pref[r + 1] ^ pref[l]) != 0)) {
                ans.push_back(false);
                continue;
            }

            query_id++;
            int cnt = 0;
            bool is_val = true;

            for (int i = l; i <= r; i++) {
                if (seen[nums[i]] != query_id) {
                    seen[nums[i]] = query_id;
                    cnt++;

                    if (cnt > k) {
                        is_val = false;
                        break;
                    }
                    if (cnt == k && global_distinct <= k) {
                        break;
                    }
                }
            }

            ans.push_back(is_val && cnt == k);
        }

        return ans;
    }
};