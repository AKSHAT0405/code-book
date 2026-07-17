#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void brute(int arr[] , int n , int d ){
    d = d%n;
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = d; i < n; i++)
    {
        arr[i-d] = arr[i];
    }
    for (int i = n-d ; i < n; i++)
    {
        arr[i] = temp[i-(n-d)];
    }
}

void optimal(int arr[] , int n , int d){
    reverse(arr , arr+d);
    reverse(arr+d , arr+n);
    reverse(arr , arr+n);
}

int main()
{
    int n;
    cout<<"input n : ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout<<"input k : ";
    cin >> k;

    // brute(arr, n, k);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }


    // optimal(arr, n, k);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}

//  brute tc = o(n+d) sc = o(d)
//  optimal tc = o(2n) sc = o(1)
// mistake : forgot reverse exist in library 
