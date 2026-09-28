#include <iostream>
using namespace std;

// Iterative method
long long factorialIterative(int n)
{
    long long result = 1;

    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }

    return result;
}

// Recursive method
long long factorialRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main()
{
    int n = 5;

    cout << "Number: " << n << endl;

    cout << "Factorial using Iterative Method: "
         << factorialIterative(n) << endl;

    cout << "Factorial using Recursive Method: "
         << factorialRecursive(n) << endl;

    return 0;
}