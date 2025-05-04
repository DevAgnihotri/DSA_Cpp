#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        set<int> st(nums.begin(), nums.end());           // make set
        vector<int> distinct_nums(st.begin(), st.end()); // convert set to vector

        sort(distinct_nums.begin(), distinct_nums.end()); // sort ascending
        cout << "Distict vector" << endl;
        for (int num : distinct_nums) // debug
        {
            cout << num << " ";
        }
        cout << endl;
        int n = distinct_nums.size();
        cout << "Size is -> " << n << endl; // debug
        return distinct_nums[n - k];        // pick the (n-k)th element
    }
};
int main()
{
    Solution solution;
    // vector<int> nums = {3, 2, 1, 5, 6, 4};
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    cout << "largest kth element to find: " << k << endl;
    int result = solution.findKthLargest(nums, k);
    cout << result;

    return 0;
}