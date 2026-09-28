#include <iostream>
using namespace std;

int matrixChainMultiplication(int p[], int n)
{
    int dp[100][100];

    // Cost is 0 when there is only one matrix
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // Chain length
    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = 999999999;

            // Try every possible split
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[100];

    cout << "Enter dimensions of matrices:\n";

    // For n matrices, enter n+1 dimensions
    cout << "Enter " << n + 1 << " dimensions: ";

    for (int i = 0; i <= n; i++)
        cin >> p[i];

    int result = matrixChainMultiplication(p, n + 1);

    cout << "\nMinimum number of scalar multiplications = "
         << result << endl;

    return 0;
}