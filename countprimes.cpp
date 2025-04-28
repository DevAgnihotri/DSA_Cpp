#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;

        // Making a vector with all vals true
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

        for (int i = 2; i * i < n; i++)
        {
            // check if the value is true or false in the isPrime vector
            if (isPrime[i])
            {
                // mark all multiple of i as false ex:- for i = 2
                // 4 6 8 10 12 14 ............
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
                count++;
        }
        return count;
    }
};

int main()
{
    Solution solution;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int primeCount = solution.countPrimes(n);
    cout << "Number of primes less than " << n << " is: " << primeCount << std::endl;

    return 0;
}