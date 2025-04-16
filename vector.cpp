#include <iostream>
#include <vector>
using namespace std; // Add this line to avoid prefixing std::

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

    return 0;
}