#include <iostream>
#include <climits> // Include this for INT_MIN
using namespace std;

void printsubarray(int arr[], int n) // Accept size as a parameter
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

void maxSumSubArray(int arr[], int n) // Accept size as a parameter
{
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

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    printsubarray(arr, n);  // Pass size as an argument
    maxSumSubArray(arr, n); // Pass size as an argument

    return 0;
}