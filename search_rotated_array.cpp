class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] == target) return mid;

            if (A[lo] <= A[mid]) { // first part is sorted
                if (A[mid] > target && target >= A[lo])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            } else { // latter part is sorted
                if (A[mid] < target && target <= A[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }

        return -1;
    }
};