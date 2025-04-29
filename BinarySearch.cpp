#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int binarySearch(int *arr, int size, int tar)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {

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

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int result = binarySearch(arr, size, target);
    if (result != -1)
        cout << "Element found at position: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}