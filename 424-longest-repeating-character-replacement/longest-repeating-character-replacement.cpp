class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int l = 0, maxfreq = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxfreq = max(maxfreq, count[s[r] - 'A']);

            while ((r - l + 1) - maxfreq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
