/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> bruteforceproductExceptSelf(vector<int> &nums)
    {
        vector<int> result;
        int prod = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (j != i)
                    prod = prod * nums[j]; // Fixed: multiply by nums[j], not nums[i]
            }
            result.push_back(prod);
            prod = 1;
        }
        return result;
    }
    vector<int> DevwayproductExceptSelf(vector<int> &nums)
    {
        vector<int> result;
        int start = 0;
        int j = 1;
        int prod = 1;
        while (start < nums.size())
        {
            if (start == j)
            {
                result.push_back(prod);
                start++;
                j = start + 1;
                if (j == nums.size())
                    j = 0;
                prod = 1;
            }
            else
            {
                prod = prod * nums[j];
                j++;
                if (j == nums.size())
                    j = 0;
            }
        }
        return result;
    }
    vector<int> SpaceissueproductExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int j = n - 2; j >= 0; j--)
        {
            suffix[j] = suffix[j + 1] * nums[j + 1];
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        int suffix = 1;

        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        for (int j = n - 2; j >= 0; j--)
        {
            suffix *= nums[j + 1];
            ans[j] *= suffix;
        }

        return ans;
    }
};

// Main function should be outside the class
// int main()
// {
//     Solution solution;
//     vector<int> nums = {1, 2, 3, 4};
//     vector<int> result = solution.productExceptSelf(nums);

//     for (int num : result)
//     {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }
// @lc code=end
