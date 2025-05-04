/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[start] <= nums[mid]) // left sorted
            {
                if (nums[start] <= target && target <= nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else // right sorted
            {
                if (nums[mid] <= target && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Adding a main function to test the code
// int main()
// {
//     Solution solution;
//     vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
//     int target = 0;
//     int result = solution.search(nums, target);

//     cout << "Index of " << target << " in rotated array: " << result << endl;

//     return 0;
// }
// @lc code=end
