class Solution {
public:
    int longestValidParentheses(string s) {
        int n  = s.size();
        vector<int> dp(n + 1);
        vector<int> vi;

        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                vi.push_back(i);
                dp[i + 1] = 0;
            } else {
                if (vi.empty())
                    dp[i + 1] = 0;
                else {
                    int p = vi.back();

                    vi.pop_back();

                    dp[i + 1] = i - p + 1 + dp[p];
                    maxlen = max(maxlen, dp[i + 1]);
                }
            }
        }

        return maxlen;
    }
};