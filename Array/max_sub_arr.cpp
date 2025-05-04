#include <iostream>
#include <climits> // Include this for INT_MIN
using namespace std;

void printsubarray(int arr[], int n)
{
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            for (int i = start; i <= end; i++)
                cout << arr[i];

            cout << " ";
        }
        cout << endl;
    }
}

void maxSumSubArray(int arr[], int n)
{
    // Brute force approach
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int start = 0; start < n; start++)
    {
        currentSum = 0;
        for (int end = start; end < n; end++)
        {
            currentSum = currentSum + arr[end];
            maxSum = max(currentSum, maxSum);
        }
    }

    cout << "max sub array sum: " << maxSum << endl;
}

void kadanealgo(int arr[], int n)
{
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
            currentSum = 0;
    }

    cout << "Max sub array sum by Kadane's algorithm: " << maxSum;
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6};
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int n = sizeof(arr) / sizeof(int);

    printsubarray(arr, n);
    maxSumSubArray(arr, n);
    kadanealgo(arr, n);

    return 0;
}