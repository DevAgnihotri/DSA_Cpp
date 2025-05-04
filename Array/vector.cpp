#include <iostream>
#include <vector>
#include <string>
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
    while (start < end)
    {
        swap(vec[start], vec[end]);
        start++;
        end--;
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
    vec.push_back(80); // Example usage
    vec.push_back(40);
    vec.push_back(45);
    for (int val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
    int b = 80;
    cout << "Linear Search for element " << b << " is at index:- "
         << (LinearSearch(vec, b) == -1 ? "not found" : to_string(LinearSearch(vec, b))) << endl;

    cout << "Reversed Vector" << endl;
    rev(vec);
    for (int val : vec)
    {
        cout << val << " ";
    }
    return 0;
}