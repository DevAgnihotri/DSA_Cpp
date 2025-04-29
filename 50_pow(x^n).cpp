class Solution
{
public:
    double myPow(double x, int n)
    {

        // Corner Cases
        if (n == 0)
            return 1.0;
        if (x == 0)
            return 0.0;
        if (x == 1)
            return 1.0;
        if (x == -1 && n % 2 == 0)
            return 1.0;
        if (x == -1 && n % 2 != 0)
            return -1.0;

        long binform = n;
        double ans = 1;
        // Converting -ve power to +ve
        if (n < 0)
        {
            x = 1 / x;
            binform = -binform;
        }

        // O(n) = log(n)
        // calculating binary form 5 :- 101
        while (binform > 0)
        {
            if (binform % 2 != 0)
            {             // if binaryform digit is 1
                ans *= x; // ans = ans*5 [10(1)] , 0 wont work, ans = ans*(5^4) [(1)01]
            }
            x *= x; // iterating in squares of x pow of x (1,2,4,8....) x^n
            binform /= 2;
        }

        return ans;
    }
};