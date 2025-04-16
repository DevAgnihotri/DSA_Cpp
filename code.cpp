#include <iostream>
using namespace std;

void reverseArray(int arr[], int sz)
{
    int start = 0, end = sz - 1, temp = 0;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int arr[] = {4, 8, 9, 7, 3, 5, 1};
    int arrSZ = sizeof(arr) / sizeof(int);
    reverseArray(arr, arrSZ);
    for (int i = 0; i < arrSZ; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << "lalalallaaaaa";
    return 0;
}