/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int singleNonDuplicate1(vector<int> &A)
    {
        int n = A.size();
        int st = 0, end = n - 1;
        while (st < end)
        {
            int mid = st + (end - st) / 2;

            if (mid == 0 && A[0] != A[1])
                return A[mid];
            if (mid == n - 1 && A[n - 2] != A[n - 1])
                return A[mid];

            if (A[mid - 1] != A[mid] && A[mid + 1] != A[mid])
                return A[mid];

            else if (mid % 2 == 0) // even
            {
                if (A[mid - 1] == A[mid])
                    end = mid - 1; // left
                else
                    st = mid + 1; // right
            }
            else
            {
                if (A[mid - 1] == A[mid]) // odd
                    st = mid + 1;         // right
                else
                    end = mid - 1; // left
            }
        }
        return -1;
    }

    int singleNonDuplicate(vector<int> &A)
    {
        int n = A.size();
        int st = 0, end = n - 1;

        // Handle edge cases
        if (n == 1)
            return A[0];
        if (A[0] != A[1])
            return A[0];
        if (A[n - 1] != A[n - 2])
            return A[n - 1];

        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            // Safe check for mid being the single element
            if (mid > 0 && mid < n - 1 && A[mid] != A[mid - 1] && A[mid] != A[mid + 1])
                return A[mid];

            // Use the property of even/odd indices
            if ((mid % 2 == 0 && mid + 1 < n && A[mid] == A[mid + 1]) ||
                (mid % 2 == 1 && mid - 1 >= 0 && A[mid] == A[mid - 1]))
            {
                st = mid + 1; // Single element is on the right
            }
            else
            {
                end = mid - 1; // Single element is on the left
            }
        }

        return A[st]; // Return the element at final position
    }
};
// @lc code=end
