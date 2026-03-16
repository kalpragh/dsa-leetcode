class Solution {
public:
    vector<string> ans;
    void backtrack(string& num, int target, int idx,long long calc, long long tail,string expr) {
        if (idx == num.size()) {
            if (calc == target) {
                ans.push_back(expr);
            }
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') break;
            string part = num.substr(idx, i - idx + 1);
            long long cur = stoll(part);
            if (idx == 0) {
                backtrack(num, target, i + 1, cur, cur, part);
            } else {
                backtrack(num, target, i + 1,calc + cur,cur,expr + "+" + part);
                backtrack(num, target, i + 1,calc - cur,-cur,expr + "-" + part);
                backtrack(num, target, i + 1,calc - tail + tail * cur,tail * cur,expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        backtrack(num, target, 0, 0, 0, "");
        return ans;
    }
};