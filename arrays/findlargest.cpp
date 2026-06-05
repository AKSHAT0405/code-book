// find largest element in an array 
#include <bits/stdc++.h>
using namespace std;
int find_largest(int arr[], int n)
{
    int target = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (target <= arr[i])
            target = arr[i];
    }
    return target;
}
int main()
{
    int q;
    cin >> q;
    int arr[q];
    for (int i = 0; i < q; i++)
    {
        cin >> arr[i];
    }
    find_largest(arr, q);
    int largest = find_largest(arr, q);
    cout << "largest is: " << largest;
}

// time complexity -- O(n)
//  Space Complexity: O(1)