
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for(int x : arr)
        cout << x << " ";

    return 0;
}

// Time Complexity:
// Average Case: O(n log n)
// Worst Case: O(n^2)

// Space Complexity:
// Average/Best Case: O(log n) 
// Worst Case: O(n) recursion stack