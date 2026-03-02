class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";

        vector<int> need(128, 0), win(128, 0);

        int required = 0;
        for (char c : t) {
            if (need[c] == 0) required++;
            need[c]++;
        }

        int formed = 0;
        int bestLen = INT_MAX, bestL = 0;

        int l = 0;
        for (int r = 0; r < (int)s.size(); ++r) {
            char c = s[r];
            win[c]++;
            if (need[c] > 0 && win[c] == need[c]) {
                formed++;
            }

            // 覆盖了就收缩
            while (formed == required) {
                int len = r - l + 1;
                if (len < bestLen) {
                    bestLen = len;
                    bestL = l;
                }

                char leftChar = s[l];
                win[leftChar]--;
                if (need[leftChar] > 0 && win[leftChar] < need[leftChar]) {
                    formed--;
                }
                l++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};