#include <iostream>
#include <vector>
#include <algorithm> // Include this for std::sort

using namespace std;

vector<int> bruteForce(int arr[], int sz, int target)
{

    vector<int> vec;
    for (int i = 0; i < sz; i++)
    {
        int comp = target - arr[i];
        for (int j = i + 1; j < sz; j++)
        {
            if (comp == arr[j])
            {
                vec.push_back(i);
                vec.push_back(j);
                return vec;
            }
        }
    }
    return vec;
}

vector<int> twoPointer(int arr[], int sz, int target)
{
    vector<int> vec;
    int start = 0;
    int end = sz - 1;

    while (start < end)
    {
        int res = arr[start] + arr[end];
        if (res == target)
        {
            vec.push_back(start);
            vec.push_back(end);
            return vec;
        }
        else if (res > target)
            end--;
        else
            start++;
    }
}

vector<int> twoSum1(vector<int> &nums, int target)
{
    vector<int> vec;
    for (size_t i = 0; i < nums.size(); i++)
    {
        size_t complement = target - nums[i];
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] == complement)
            {
                // return {i,j};
                vec.push_back(i);
                vec.push_back(j);
                return vec;
            }
        }
    }
    return vec;
}

vector<int> twoSum2(vector<int> &nums, int target)
{
    // sorting the array hence index changes
    vector<int> vec;
    int start = 0;
    int sz = nums.size(); // Use nums.size() to get the correct size
    int end = sz - 1;
    sort(nums.begin(), nums.end());
    while (start < end)
    {
        int res = nums[start] + nums[end];
        if (res < target)
        {
            start++;
        }
        else if (res > target)
            end--;
        else
        {
            vec.push_back(start);
            vec.push_back(end);
            return vec;
        }
    }
    return vec;
}

int main()
{
    int arr[] = {3, 2, 4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int sz = sizeof(arr) / sizeof(int);
    cout << "Size of array  is = " << sz << endl;

    // Sort the vector
    int target = 6;
    // vector<int> vec = twoPointer(arr, sz, target);
    vector<int> car = twoSum1(nums, target); // case of sorted vector
    for (int val : car)
    {
        cout << val << " ";
    }
}