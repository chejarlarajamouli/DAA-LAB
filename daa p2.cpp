#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[100], n, key, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    cout << "\n1. Linear Search";
    cout << "\n2. Binary Search";
    cout << "\nEnter your choice: ";
    cin >> choice;

    int result;

    if (choice == 1)
    {
        result = linearSearch(arr, n, key);

        if (result != -1)
            cout << "Element found at index: " << result;
        else
            cout << "Element not found";
    }
    else if (choice == 2)
    {
        result = binarySearch(arr, n, key);

        if (result != -1)
            cout << "Element found at index: " << result;
        else
            cout << "Element not found";
    }
    else
    {
        cout << "Invalid choice!";
    }

    return 0;
}
