class Solution {
public:
    int maxArea(vector<int> &h) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = -1;
        int n = h.size();

        int i = 0, j = n - 1;

        while (i < j) {
            res = max(res, (j - i) * min(h[i], h[j]));

            if (h[i] <= h[j]) { // move i;
                int newi = i + 1;
                while (newi < j && h[newi] <= h[i])
                    newi++;
                i = newi;
            } else { // move j
                int newj = j - 1;
                while (i < newj && h[newj] <= h[j])
                    newj--;
                j = newj;
            }
        }

        return res;
    }
};