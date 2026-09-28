#include <iostream>
#include <climits>
using namespace std;

int minCoins(int coins[], int n, int amount)
{
    int dp[100];

    // Initialize DP array
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        dp[i] = INT_MAX;

    // Calculate minimum coins
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i],
                            dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[amount];
}

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    int coins[100];

    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    int result = minCoins(coins, n, amount);

    if (result == INT_MAX)
        cout << "Change cannot be made." << endl;
    else
        cout << "Minimum number of coins = " << result << endl;

    return 0;
}