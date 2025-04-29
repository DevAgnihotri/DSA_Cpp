#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int bruteForcemaxArea(vector<int> &height)
    {
        int maxWater = 0;
        for (int i = 0; i < height.size(); i++)
            for (int j = i + 1; j < height.size(); j++)
            {
                int wd = j - i;
                int ht = min(height[j], height[i]);
                int currwater = wd * ht;
                maxWater = max(maxWater, currwater);
            }
        return maxWater;
    }

    int OptmaxArea(vector<int> &height)
    {
        int start = 0;
        int end = height.size() - 1;
        int maxArea = 0;
        while (start < end)
        {
            int wd = end - start;
            int ht = min(height[start], height[end]);
            int currArea = wd * ht;
            maxArea = max(maxArea, currArea);
            height[start] > height[end] ? end-- : start++;
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Brute Force Method: " << sol.bruteForcemaxArea(height) << endl;
    cout << "Optimized Method: " << sol.OptmaxArea(height) << endl;

    return 0;
}