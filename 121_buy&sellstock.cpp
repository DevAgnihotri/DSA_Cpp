#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int bruteForcemaxProfit(vector<int> &prices)
    {
        auto max = max_element(prices.begin(), prices.end());
        int diff = 0;
        int max_val = *max;
        if (max_val != 0)
        {
            for (int i = 0; i < (int)max_val; i++)
            {
                if (diff < prices[max_val] - prices[i])
                    diff = prices[max_val] - prices[i];
            }
        }
        return diff;
    }

    int OptmaxProfitclass(vector<int> &prices)
    {
        int bestbuy = prices[0], mp = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > bestbuy)
            {
                mp = max(mp, prices[i] - bestbuy);
            }
            // else
            // {
            //     bestbuy = prices[i];
            // }
            bestbuy = min(bestbuy, prices[i]);
        }
        return mp;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example prices
    Solution solution;

    cout << "Input prices: ";
    for (int price : prices)
    {
        cout << price << " ";
    }
    cout << endl;

    // Test optimized solution
    int maxProfit = solution.OptmaxProfitclass(prices);
    cout << "Maximum profit: " << maxProfit << endl;

    // Test with another example
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "\nInput prices 2: ";
    for (int price : prices2)
    {
        cout << price << " ";
    }
    cout << endl;

    int maxProfit2 = solution.OptmaxProfitclass(prices2);
    cout << "Maximum profit: " << maxProfit2 << endl;

    return 0;
}