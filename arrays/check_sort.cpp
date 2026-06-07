// question : check if the array is sorted or not 

#include <bits/stdc++.h>
using namespace std;
bool sort_check(const vector<int>arr , int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        return false;
    }
    return true;
}
int main()
{
    int q;
    cin >> q;
    vector<int> arr(q);
    for (int i = 0; i < q; i++)
    {
        cin >> arr[i];
    }
    int output = sort_check(arr, q);
    if (output == 1) cout << "true";
    else cout << "false";
    return 0;
}

// time complexity of sort_check function : O(n)
// space complexity of check function : O(1)