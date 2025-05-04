#include <iostream>
using namespace std;

void print_arr(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
}
void sumarr(int arr[], int sz)
{
    int sum = 0;
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " + ";
        sum = sum + arr[i];
    }
    cout << "0 = " << sum << endl;
}

void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swap_max_min(int arr[], int sz)
{
    int max_idx = 0, min_idx = 0;

    for (int i = 1; i < sz; i++)
    {
        if (arr[i] > arr[max_idx])
            max_idx = i;
        if (arr[i] < arr[min_idx])
            min_idx = i;
    }

    int temp = arr[max_idx];
    arr[max_idx] = arr[min_idx];
    arr[min_idx] = temp;

    cout << "Max num is: " << arr[max_idx] << endl;
    cout << "Min num is: " << arr[min_idx] << endl;
}
void un_val(int arr[], int size)
{
    int value;
    cout << "Unique value inside array" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                continue;
            }
            else
            {
                value = arr[i];
            }
        }
        cout << value << " ";
    }
}
int main()
{
    int arr[] = {2, 5, 2, 6, 8, 3, 3, 1, 8, 9, 4};
    int size = sizeof(arr) / sizeof(int);
    print_arr(arr, size);
    cout << endl
         << "Size of the Array is: " << size << endl;

    sumarr(arr, size);
    swap_max_min(arr, size);
    print_arr(arr, size);
    un_val(arr, size);
}