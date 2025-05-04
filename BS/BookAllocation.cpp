#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages)
{
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++) // O(n)
    {
        if (arr[i] > maxAllowedPages)
            return false;

        if (pages + arr[i] <= maxAllowedPages)
        {
            pages += arr[i];
        }
        else
        {
            students++;
            pages = arr[i];
        }
    }
    return students > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += arr[i];
    }

    int st = 0, end = sum;
    int ans = -1;
    while (st <= end) // O(logN * n) N = range on bin search
    {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) // left
        {
            ans = mid;
            end = mid - 1;
        }
        else // right
        {
            st = mid + 1;
        }
    }
}

int main()
{
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2;
    // n is num of books
    // m is studetns books are allocated
    cout << allocateBooks(arr, n, m) << endl;
    return 0;
}