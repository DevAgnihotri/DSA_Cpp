#include <iostream>
#include <vector>
using namespace std; // Add this line to avoid prefixing std::

int LinearSearch(const vector<int> &vec, int val)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (val == vec.at(i))
            return i;
    }
    return -1; // case where the value is not found
}

void rev(vector<int> &vec)
{
    int start = 0;
    int end = vec.size() - 1;
    int temp;
    while (start < end)
    {
        temp = vec[start];
        vec[start] = vec[end];
        vec[end] = temp;
    }
}

int main()
{
    vector<int> vec;   // Now `vector` is recognized
    vec.push_back(10); // Example usage
    vec.push_back(20);
    vec.push_back(30);
    for (int val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    cout << "Front element: " << vec.front() << endl;
    cout << "Back element: " << vec.back() << endl;
    vec.pop_back();
    cout << "After pop_back, back element: " << vec.back() << endl;
    for (int val : vec)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}