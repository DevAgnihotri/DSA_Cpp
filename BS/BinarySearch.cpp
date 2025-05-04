#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int binarySearch(vector<int> &arr, int tar)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        // int mid = (start + end)/2 Causes OVerflow
        int mid = start + (end - start) / 2;

        if (arr[mid] < tar)
            start = mid + 1;

        else if (arr[mid] > tar)
            end = mid - 1;

        else
            return mid;
    }
    return -1; // Element not found
}

int recBS(vector<int> &arr, int tar, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (start <= end)
    {
        if (tar < arr[mid])
            return recBS(arr, tar, start, mid - 1);
        else if (tar > arr[mid])
            return recBS(arr, tar, mid + 1, end);
        else
            return mid;
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    int end = sizeof(arr) / sizeof(int);
    int result = recBS(arr, target, 0, end);
    if (result != -1)
        cout << "Element found at position: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}