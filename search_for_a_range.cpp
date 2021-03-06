class Solution {
public:

    // returns the smallest index i such that a[i] >= target
    // note that if i < j and a[i] >= target, a[j] >= a[i] >= target
    int solve(int a[], int n, int target) {
        int lo = 0;
        int hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] >= target) hi = mid;
            else lo = mid + 1;
        }

        if (a[lo] != target) return -1;
        else return lo;
    }


    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> res;

        int x = solve(A, n, target);
        res.push_back(x);

        if (x == -1) {
            res.push_back(-1);
            return res;
        }

        int y = x + 1;
        while (y < n && A[y] == target) y++;
        res.push_back(y - 1);

        return res;
    }
};