class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, prefix = 0;
        vector<int> mp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix += (nums[i] % 2);
            mp[prefix]++;
            if (prefix >= k) {
                ans += mp[prefix - k];
                if (prefix == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};