#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// void brFc(int arr[], int size)
// {
//     int maxCount = 0, maxElement = arr[0];
//     for (int i = 0; i < size; i++)
//     {
//         int count = 0;
//         for (int j = 0; j < size; j++)
//         {
//             if (arr[i] == arr[j])
//                 count++;
//         }
//         if (count > maxCount)
//         {
//             maxCount = count;
//             maxElement = arr[i];
//         }
//     }
//     cout << "Element with max frequency: " << maxElement << " (Frequency: " << maxCount << ")" << endl;
// }

int bruteforce(const vector<int> &nums)
{
    int n = nums.size();
    for (int val : nums)
    {
        int freq = 0;
        for (int el : nums)
        {
            if (el == val)
            {
                freq++;
            }
        }
        if (freq > n / 2)
        {
            return val;
        }
    }
    return -1;
}

int optzApp(vector<int> &nums)
{

    // sort
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int freq = 1;
    int ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
            freq++;
        else
        {
            freq = 1;
            ans = nums[i];
        }

        if (freq > n / 2)
        {
            return ans;
        }
    }
    return ans;
}

int mooreAlgo(vector<int> &nums)
{
    int freq = 0, ans;
    for (int i = 0; i < nums.size(); i++)
    {

        if (freq == 0)
            ans = nums[i];

        if (ans == nums[i])
            freq++;
        else
            freq--;
    }

    // checker
    int count = 0;
    for (int val : nums)
    {
        if (val == ans)
            count++;
    }

    if (count > nums.size() / 2)
        return ans;
    else
        return -1;
}

int main()
{
    vector<int> vec = {1, 2, 2, 1, 1, 1, 2, 2, 2};

    cout << "Brute force approach: " << bruteforce(vec) << endl;
    cout << "Optimised Approach: " << optzApp(vec);
    cout << "\nMoore's Voting Algorithm: " << mooreAlgo(vec) << endl;
    return 0;
}