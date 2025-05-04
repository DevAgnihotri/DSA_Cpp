/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int st = 1, end = arr.size() - 2;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (arr[mid - 1] <= arr[mid] && arr[mid + 1] <= arr[mid])
                return mid;
            else if (arr[mid - 1] <= arr[mid])
                st = mid + 1;
            else //(arr[mid-1] >= mid)
                end = mid - 1;
        }
        return -1;
    }
    int peakIndexInMountainArray2(vector<int> &arr)
    {
        int st = 1, end = arr.size() - 2;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            // Check if mid is valid and is a peak
            if ((mid == 0 || arr[mid - 1] < arr[mid]) &&
                (mid == arr.size() - 1 || arr[mid] > arr[mid + 1]))
                return mid;
            // If we're on the ascending part of the mountain
            else if (mid < arr.size() - 1 && arr[mid] < arr[mid + 1])
                st = mid + 1; // Move right to find peak
            // If we're on the descending part of the mountain
            else
                end = mid - 1; // Move left to find peak
        }
        return -1; // Should not reach here for valid mountain arrays
    }
};
// @lc code=end
